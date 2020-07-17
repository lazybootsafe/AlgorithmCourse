# cin,>>,空格

+++

~~~c++
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str;
	cout<<"请随便输入一个字符串:";
    cin>>str;
	cout<<str<<endl;
	return 0;
}

输入:I love China
输出:I
~~~

为什么最后只输出了一个I呢？原因如下：

+ cin是istream类的对象，它从标准输入设备(键盘)获取数据，程序中的变量通过流提取符“>>”从流中提取数据。

  > 注意：**只有在输入完数据再按回车键后，该行数据才被送入键盘缓冲区，形成输入流，提取运算符“>>”才能从中提取数据**。(还需要注意保证从流中读取数据能正常进行。）

 并且**流提取符>>从流中提取数据**时通常跳过输入流中的空格、tab键、换行符等空白字符。

而用**cin>>读取数据时**，以空白字符（包括空格、tab键、回车键）作为终止标志。即cin>>从流中提取数据，遇到空格，提取完成。然后再开始下一个提取。

~~~
例如

int a,b;

cin>>a>>b;

从键盘上输入

21 efg

cin>>从流中提取数据，遇到空格，提取完成。然后开始下一个提取。变量a从输入流中提取整数21，提取操作成功，此时cin流处于正常状态。但在变量b准备提取一个整数时，遇到了字母e，显然提取操作失败了。此时，cin流被置为出错状态，只有在正常状态时，才能从输入流中提取数据。
当cin尝试将输入的字符读为int类型数据失败后，会产生一个错误状态
cin.fail(),它会返回true,即告诉cin你读取出错了，所以cin返回0，所以b=0
~~~

既然如此，那我们怎么解决输入时带有空格的字符串呢？

+ 我们可以调用getline(istream is,string str,结束符)函数，

  用法：接收一个字符串，可以接收空格并输出；

  他不会遇到空白字符就结束输入，并且会丢掉最后一个换行符

+ 调用该函数时，需包含#include\<string\>这个头文件;

  其中的结束符参数可有可无；

+ 注意：cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数

  ~~~c++
  #include <iostream>
  #include <string>
  using namespace std;
   
  int main() {
  	char ch;
  	string str;
  	cout << "请输入string内容：" << endl;
  	getline(cin, str); //输入：abc(space)(space)d(enter)
  	//getline(cin, str, 'a');	
  	cout << str << endl;
  	cin.get(ch); //因为丢弃了最后一个换行符，所以此处从键盘输入b
  	cout << (int)ch << endl; //输出：98 'b'的ASCII码值
  	return 0;
  }
  ~~~

  