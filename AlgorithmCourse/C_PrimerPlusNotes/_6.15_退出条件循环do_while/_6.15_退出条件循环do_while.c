#include <stdio.h>

int main(void)
{
	//��ȡ���룬������Ϊ13ʱ������ѭ��
	const int secret_code = 13;
	int code_entered;
	
	do
	{
		printf("To enter the triskaidekaphobia therapy club, \n");
		printf("please enter the secret code number: ");
		scanf_s("%d", &code_entered);
	} while (code_entered != secret_code);	//do while()ѭ��������һ����䣬��Ҫ��β�ķֺ�
	printf("OK, you have restored from the triskaidekaphobia!\n");

	getchar();
	getchar();
	return 0;

	//ʹ�õȼ۵�while()ѭ�������䳤����Ҫ���ж�һ�Σ��μ� _6.16_�������ѭ��
}