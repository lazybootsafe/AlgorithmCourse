# C++光速入门

```

```
入门前提:C语言  
环境:DEV C++ / Clion
配置环境
![](images/2021-08-13-12-13-10.png)  
新建项目就自带了cmakelists.txt了.那就开始吧 

markdown环境 vscode

## 1 Hello World

 ```cpp
#include<iostream> //输入输出头文件
using namespace std; //使用标准命名空间 记得分号

int main(){ //主函数
	cout<<"hello world!"<<endl;//输出
	return 0; //返回0 程序正常结束
}
 ```

```cpp
#include<iostream>
using namespace std;

namespace A{
  int  i=10;
}

namespace B{
	int  i=20;
	namespace C{//命名空间的定义可以嵌套
       int i=30;
	}
	int n=i+C::i;
}

int main(){
    cout<<A::i<<endl;   //或者using namespace A;
    cout<<B::i<<endl;
    cout<<B::n<<endl;
    return 0;
}

```

## 2 数据类型及表达范围
使用编程语言进行编程时，需要用到各种变量来存储各种信息。变量保留的是它所存储的值的内存位置。这意味着，当您创建一个变量时，就会在内存中保留一些空间。  

您可能需要存储各种数据类型（比如字符型、宽字符型、整型、浮点型、双浮点型、布尔型等）的信息，操作系统会根据变量的数据类型，来分配内存和决定在保留内存中存储什么。  

类型	关键字  
布尔型	bool  
字符型	char  
整型	int  
浮点型	float  
双浮点型	double  
无类型	void  
宽字符型	wchar_t  


|类型|位|范围 |
|--|---|------|
|char|	1 个字节|	-128 到 127 或者 0 到 255  |
unsigned char|	1 个字节|	0 到 255  
signed char	|1 个字节|	-128 到 127  
int	|4 个字节|	-2147483648 到 2147483647  
unsigned int|	4 个字节|	0 到 4294967295  
signed int	|4 个字节|	-2147483648 到 2147483647  
short int	|2 个字节|	-32768 到 32767  
unsigned short int	|2 个字节|	0 到 65,535  
signed short int	|2 个字节|	-32768 到 32767  
long int	|8 个字节|	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807  
signed long int	|8 个字节|	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807  
unsigned long int	|8 个字节|	0 到 18,446,744,073,709,551,615  
float	|4 个字节|	精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字)  
double	|8 个字节|	双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字)  
long double	|16 个字节|	长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。  
wchar_t	|2 或 4 个字节|	1 个宽字符  


## 3 输入输出
C++ 标准库提供了一组丰富的输入/输出功能，我们将在后续的章节进行介绍。本章将讨论 C++ 编程中最基本和最常见的 I/O 操作。  

C++ 的 I/O 发生在流中，流是字节序列。如果字节流是从设备（如键盘、磁盘驱动器、网络连接等）流向内存，这叫做输入操作。如果字节流是从内存流向设备（如显示屏、打印机、磁盘驱动器、网络连接等），这叫做输出操作。  

```cpp
#include<iostream>//输入输出头文件 
//i=input 输入
//o=output 输出
//stream 流
using namespace std;//命名空间 
//std=standard 标准的

int main(){//主函数	
	const double pi=3.14159;
	double r, c, s;
	cout<<"输入圆的半径：";
	cin>>r;
	c=2.0*pi*r;
	s=pi*r*r;
	cout<<"圆的周长为："<<c<<endl;
	cout<<"圆的面积为："<<s<<endl;
	
//	int a=10,*p;
//	int &b=a;
//	p=&a;
//	string s="C++";
//	string *ps=&s;
//	cout<<p<<endl;  //输出结果是指针p的值，a变量的地址
//	cout<<b<<endl;  //输出结果是b的值10
//	cout<<*p<<endl; //输出结果是指针p指向的变量的值，即a的值10
//	cout<<ps<<endl; //输出结果是指针ps的的值，s变量的地址
//	cout<<*ps<<endl; //输出结果是指针ps指向的变量的值，即s的值”C++”
//	a=20;
//	cout<<a<<endl;  
//	cout<<b<<endl;  
//	b=30;
//	cout<<a<<endl;  
//	cout<<b<<endl;

	//cout<<"hello world!"<<endl;//输出 
//	char c1,c2;
//	cin>>c1>>c2;
//	cout<<c1<<" "<<c2;
	//cout<<10<<endl;
	//cout<<'a'<<endl;
	//cout<<"C++"<<endl;
//	int a=10;
//	string s="C++";
//	float f=1.2;
//	cout<<a<<endl;  //输出int类型的变量
//	cout<<s<<endl;  //输出string类型的变量
//	cout<<f<<endl;  //输出float类型的变量

//	int n;
//	string s;
//	float f;
//	cin>>n>>s>>f;
//	cout<<n<<" "<<s<<" "<<f<<endl;
	return 0;//返回0 
 } 

```
### I/O 库头文件
下列的头文件在 C++ 编程中很重要。

|头文件	|函数和描述|
|---|---|
|iostream|	该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。
|iomanip|	该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。
|fstream	|该文件为用户控制的文件处理声明服务。我们将在文件和流的相关章节讨论它的细节。

### 标准输出流（cout）
预定义的对象 cout 是 iostream 类的一个实例。cout 对象"连接"到标准输出设备，通常是显示屏。cout 是与流插入运算符 << 结合使用的，如下所示：  

```cpp
#include <iostream>
 
using namespace std;
 
int main( )
{
   char str[] = "Hello C++";
 
   cout << "Value of str is : " << str << endl;
}
```
当上面的代码被编译和执行时，它会产生下列结果：

`Value of str is : Hello C++`
C++ 编译器根据要输出变量的数据类型，选择合适的流插入运算符来显示值。<< 运算符被重载来输出内置类型（整型、浮点型、double 型、字符串和指针）的数据项。  

流插入运算符 << 在一个语句中可以多次使用，如上面实例中所示，endl 用于在行末添加一个换行符。  

### 标准输入流（cin）
预定义的对象 cin 是 iostream 类的一个实例。cin 对象附属到标准输入设备，通常是键盘。cin 是与流提取运算符 >> 结合使用的，如下所示：

```cpp
#include <iostream>
 
using namespace std;
 
int main( )
{
   char name[50];
 
   cout << "请输入您的名称： ";
   cin >> name;
   cout << "您的名称是： " << name << endl;
 
}
```
当上面的代码被编译和执行时，它会提示用户输入名称。当用户输入一个值，并按回车键，就会看到下列结果：  
```
请输入您的名称： cplusplus
您的名称是： cplusplus
```
C++ 编译器根据要输入值的数据类型，选择合适的流提取运算符来提取值，并把它存储在给定的变量中。  

流提取运算符 >> 在一个语句中可以多次使用，如果要求输入多个数据，可以使用如下语句：

`cin >> name >> age;`
这相当于下面两个语句：

```cpp
cin >> name;
cin >> age;
```
### 标准错误流（cerr）
预定义的对象 cerr 是 iostream 类的一个实例。cerr 对象附属到标准错误设备，通常也是显示屏，但是 cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。  

cerr 也是与流插入运算符 << 结合使用的，如下所示：

```cpp
#include <iostream>
 
using namespace std;
 
int main( )
{
   char str[] = "Unable to read....";
 
   cerr << "Error message : " << str << endl;
}
```

### 标准日志流（clog）
预定义的对象 clog 是 iostream 类的一个实例。clog 对象附属到标准错误设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到 clog 都会先存储在缓冲区，直到缓冲填满或者缓冲区刷新时才会输出。  

clog 也是与流插入运算符 << 结合使用的，如下所示：

```cpp
#include <iostream>
 
using namespace std;
 
int main( )
{
   char str[] = "Unable to read....";
 
   clog << "Error message : " << str << endl;
}
```

### 模板
输入输出流中的函数（模板）：

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout<<setiosflags(ios::left|ios::showpoint);  // 设左对齐，以一般实数方式显示
    cout.precision(5);       // 设置除小数点外有五位有效数字 
    cout<<123.456789<<endl;
    cout.width(10);          // 设置显示域宽10 
    cout.fill('*');          // 在显示区域空白处用*填充
    cout<<resetiosflags(ios::left);  // 清除状态左对齐
    cout<<setiosflags(ios::right);   // 设置右对齐
    cout<<123.456789<<endl;
    cout<<setiosflags(ios::left|ios::fixed);    // 设左对齐，以固定小数位显示
    cout.precision(3);    // 设置实数显示三位小数
    cout<<999.123456<<endl; 
    cout<<resetiosflags(ios::left|ios::fixed);  //清除状态左对齐和定点格式
    cout<<setiosflags(ios::left|ios::scientific);    //设置左对齐，以科学技术法显示 
    cout.precision(3);   //设置保留三位小数
    cout<<123.45678<<endl;
    return 0; 
}
```

测试输出结果：
```
123.46
****123.46
999.123
1.235e+02
```
其中 cout.setf 跟 setiosflags 一样，cout.precision 跟 setprecision 一样，cout.unsetf 跟 resetiosflags 一样。  


```
setiosflags(ios::fixed) 固定的浮点显示 
setiosflags(ios::scientific) 指数表示 
setiosflags(ios::left) 左对齐 
setiosflags(ios::right) 右对齐 
setiosflags(ios::skipws 忽略前导空白 
setiosflags(ios::uppercase) 16进制数大写输出 
setiosflags(ios::lowercase) 16进制小写输出 
setiosflags(ios::showpoint) 强制显示小数点 
setiosflags(ios::showpos) 强制显示符号 
```

## 4 if-else
![](images/2021-08-14-02-14-10.png)  

### 判断语句
C++ 编程语言提供了以下类型的判断语句。点击链接查看每个语句的细节。

|语句	|描述|
|----|----|
if 语句|	一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。
if...else 语句|	一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。
嵌套 if 语句|	您可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。
switch 语句|	一个 switch 语句允许测试一个变量等于多个值时的情况。
嵌套 switch 语句|	您可以在一个 switch 语句内使用另一个 switch 语句。

### ? : 运算符
我们已经在前面的章节中讲解了 条件运算符 ? :，可以用来替代 if...else 语句。它的一般形式如下：  

`Exp1 ? Exp2 : Exp3;`  

其中，Exp1、Exp2 和 Exp3 是表达式。请注意，冒号的使用和位置。  

? 表达式的值是由 Exp1 决定的。如果 Exp1 为真，则计算 Exp2 的值，结果即为整个 ? 表达式的值。如果 Exp1 为假，则计算 Exp3 的值，结果即为整个 ? 表达式的值。  

```cpp
#include<iostream>
using namespace std;

int main(){
	float score;
	cin>>score;
	cout<<score;
	if(score>=60)
		cout<<"及格！"<<endl; 
	else
		cout<<"不及格！"<<endl; 
	return 0;
}

```

```cpp
#include<iostream>
using namespace std;

int main(){
	float score;
	cin>>score;
	if(score>=70)
		if(score<80) 
			cout<<"中等"<<endl; 
		else if(score<90)
				cout<<"良好"<<endl; 
			else
				cout<<"优秀"<<endl; 
	else if(score>=60)
			cout<<"及格！"<<endl; 
		else
			cout<<"不及格！"<<endl; 
	return 0;
}

```

```cpp
#include <iostream>
using namespace std;

int main(){
    int num,a,b,c;
	cin>>num;
	a=num%10;  //个位数字
	b=(num/10)%10; //十位数字
	c=num/100;     //百位数字
	if(num==(a*a*a+b*b*b+c*c*c))
		cout<<num<<"是水仙花数"<<endl;
    else
        cout<<num<<"不是水仙花数"<<endl;
    return 0;
}

```

```cpp
#include<iostream>
using namespace std;

int main(){
    int month,season=0;
    cin>>month;
    if(3<=month&&month<=5)
        season=1;
    else if(6<=month&&month<=8)
           season=2;
        else if(9<=month&&month<=11)
               season=3;
            else if((1<=month&&month<=2)||(month==12))
                   season=4;
    switch(season){
	    case 1:
	        cout<<"春季"<<endl;
	        break;
	    case 2:
	        cout<<"夏季"<<endl;
	        break;
	    case 3:
	        cout<<"秋季"<<endl;
	        break;
	    case 4:
	        cout<<"冬季"<<endl;
	        break;
	    default:cout<<"输入的月份不对！"<<endl;
    }
    return 0;
}

```


## 5 for/while

## 6 函数

## 7 递归

## 8 结构体

## 9 数组

## 10 字符串