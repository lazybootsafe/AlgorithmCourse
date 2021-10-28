/*
	5.位运算符的应用：

	&与掩码：
	0 & 1 = 0; 1 & 1 = 1;
	0 & 0 = 0; 1 & 0 = 0;
	掩码：掩码是某些位设为开，而某些位设为关的位组合。
	因为任何比特位与1&都是它本身，与0&是0，
	所以可用掩码覆盖某个数的对应位而只显示某些位。

	|与打开位：
	0 | 1 = 1; 1 & 1 = 1;
	0 & 0 = 0; 1 & 0 = 1;
	因为任何比特位与1|都是1，与0|是它本身，
	所以可用|运算将一个数的特定位打开。

	&~与关闭位：
	0 & ~1 = 0; 1 & ~1 = 0;
	0 & ~0 = 0; 1 & ~0 = 1;
	因为任何比特位与1的反码&为0，与0的反码&为它本身，
	所以可用&和一个掩码的反码关闭位。

	^与转置位：
	0 ^ 1 = 1; 1 ^ 1 = 0;
	0 ^ 0 = 0; 1 ^ 0 = 1;
	因为任何比特位与1^都是它的转置，与0^是它本身，
	所以可用^来转置某个数的对应位。

	6.移位运算符：
	左移运算符<<：
	左移运算符<<将左侧操作数的值的每位向左移动，移动的位数由右侧操作数指定。
	空出的位用0填充，并且丢弃移出左侧操作数末端的位。

	右移>>:
	右移运算符>>将左侧操作数的值的每位向右移动，移动的位数由右侧操作数指定。
	丢弃移出左侧操作数右端的位。对于无符号类型，使用0填充左端空出的位；对于有符号类型，结果依赖于机器。空出的位可能用0填充，或者使用符号（最左端的）位的副本填充。
	（调试后，我的系统下，对有符号数>>运算，左端空出的位用符号位填充）

	7.移位运算符的用法：

	移位运算符能够提供快捷高效的（依赖于硬件）对2的幂的乘法和除法。
	num << n;		//num乘以2的n次幂
	num >> n;		//如果num非负，num除以2的n次幂	

	这些移位运算符类似于在十进制中移动小数点来乘以10或除以10.
	移位运算符也用于从较大的单位中提取多组比特位。例如，假设使用unsignec long值代表颜色值，其中低位字节存放红色亮度，下一字节存放绿色亮度，第三字节存放蓝色亮度。假设希望将每种颜色的亮度存放在各自的unsigned char变量中，可以使用以下语句：
	#define BYTE_MASK 0xff
	unsigned long color = 0x002a162f;
	unsigned char blue, green, red;
	red = color & BYTE_MASK ;			//屏蔽其他位，只取低8位
	green = (color >> 8) & BYTE_MASK ;	//右移8位，屏蔽其他位，只取低8位
	blue = (color >> 16) & BYTE_MASK ;	//右移16位，屏蔽其他位，只取低8位
	这段代码使用右移运算符将8位颜色值移动到低位字节，然后使用掩码技术将低位字节赋给所需的变量。

	*/

#include <stdio.h>
#include <stdlib.h>

char * itobs(int, char *);
void show_bstr(const char *);

int main(void)
{
	char bin_str[8 * sizeof(int) + 1];
	int number;

	system("color 5A");
	puts("Ener integers and see them in binary:");
	puts("Non-numeric input terminates program");
	while (scanf_s("%d", &number, 10)== 1)
	{
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!");

	system("pause");
	return 0;
}

char * itobs(int n, char * ps)
{
	static int size = 8 * sizeof(int);			//一个int值所占的位数

	for (int i = size - 1; i >= 0; i--, n >>= 1)
	{
		ps[i] = (n & 0x1) + '0';				/*从右向左取得int值的每一比特位填充数组（倒数第2个元素开始填充）
												  使用移位运算符和掩码技术，用八进制01做掩码
												  int值依次向右移动1位，用掩码01屏蔽int值位0(值1）之外的所有位，
												  并用(n & 01)取出int值的最后一位：0或1，因为要保存成为字符，
												  所以得到的0或1在加‘0’的ASCII值，得到‘0’或‘1’的ASCII值，
												  保存
												  
												  题外：也可以使用1&n代替01&n。但是，使用八进制的01而不是十进制的1
												  看起来会更接近计算机一些。
												  也可以在阅读到01&n时更直观地明白，该运算不是数值运算，起到了提醒
												  的作用（当然，前提是必须了解不同进制数的C表示法）*/
	}
	ps[size] = '\0';							//空字符的八进制ASCII值
	return ps;
}

//4位一组显示二进制字符串
void show_bstr(const char * str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])		//如果达到了4个字符，且下一个字符非空，则打印‘ ’
		{
			putchar(',');
		}
	}
}