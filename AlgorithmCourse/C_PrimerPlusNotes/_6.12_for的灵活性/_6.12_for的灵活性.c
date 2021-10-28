#include <stdio.h>

int main(void)
{
	//for��3�����ʽ�������(initialize���ʽ��test���ʽ��update���ʽ)

	//1.������С
	for (int sec = 5; sec > 0; sec--)
	{
		printf("%d second!", sec);
		if (sec != 1)
		{
			printf("\bs!\n");
		}
	}
	printf("\n\n");
	
	//2.����ֵ�Զ���
	for (int i = 2; i < 60; i += 13)
	{
		printf("%d\n", i);
	}
	printf("\n");
	
	//3.���ַ�����
	for (char ch = 'a'; ch <= 'z'; ch++)	//�����������������forѭ���ִ��һ��ѭ�������ӣ���С��1��ǰ��׺Ч����ͬ��
	{
		printf("The ASCII for %c is %d\n", ch, ch);
	}
	printf("\n");

	//4.�жϵ�������֮�������
	printf("    n n-cubed\n");
	for (int i = 1; i*i*i <= 216; i++)
	{
		printf("%5d %5d\n", i, i*i*i);
	}
	printf("\n");

	//5.��������ȡ����������
	for (double i = 100.0; i < 150.0; i*= 1.1)
	{
		printf("Your debt is now $%.2f\n", i);
	}
	printf("\n");
	
	//6.ʹ�ô���������и��£����õı�̷��
	int x;
	int y = 55;

	for (x = 1; y <= 75; y = (++x * 5) + 50)	//��������֪���ڶ������ʽ�ȼ���x<=5
	{
		printf("%10d %10d\n", x, y);
	}
	printf("\n");

	//7.һ���������ʽΪ�գ���Ҫ�зֺţ�ֻ��ȷ����ѭ���а�������ʹѭ����������䣨ע�⣺��8�����ӣ�
	int n, ans;

	ans = 2;
	for (n = 3; ans <= 25; )
	{
		ans *= n;
		printf("n = %d, ans = %d\n", n, ans);
	}
	printf("\n");

	//7.2.�ڶ������ʽΪ��ʱ��Ĭ��Ϊ�棬ѭ������Զִ��
	/*for (;;)
	{
		printf("I want some action.\n");
	}
	printf("\n");*/

	//8.��һ�����ʽ���س�ʼ��һ��������������ĳ�����͵�printf������䡣��ֻ��ִ��һ��
	int num = 0;

	for (printf("Keep entering numbers!(6 end the loop-for)\n"); num != 6;)
	{
		scanf_s("%d", &num);
	}
	printf("That's the one I want!\n\n");
	
	//9.ѭ���еĶ������Ըı�ѭ�����ʽ�Ĳ���
	int delta = 0;

	printf("Please enter the increment of the loop-for\n");
	printf("(When the num is 0, the loop-for will use the default 10):");

	scanf_s("%d", &delta);
	for (int i = 0; i < 100; i += delta)
	{
		if (delta == 0)
		{
			delta = 10;
		}
		printf("i = %d\n", i);
	}
	printf("\n");

	getchar();
	getchar();
	return 0;
}