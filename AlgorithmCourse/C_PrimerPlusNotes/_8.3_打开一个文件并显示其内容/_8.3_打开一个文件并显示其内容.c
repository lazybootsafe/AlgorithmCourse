#include <stdio.h>
#include <stdlib.h>						//�ṩ��exit()�ĺ���ԭ��

int main(void)
{
	//�����ļ���ȡ������һ���ļ�����ȡ�������ݵ�����̨,�Խ������Ŀ¼�µġ�test.txt��Ϊ�����ļ�

	int ch;
	FILE *fp;							//�ļ�ָ��
	errno_t err;		
	char fname[50];

	system("color 0A");
	printf("Please enter the name of the file��e.g.\"test.txt\"��:\n");
	scanf_s("%s", fname, sizeof fname);
	err = fopen_s(&fp, fname, "r");		//��ֻ����ʽ���ļ�����ȡ,ʧ�ܷ��ط�0������
	if (err != 0)						//��ʧ�ܣ��쳣�˳���ʱ
	{
		printf("Failed to open the file!\n");
		exit(1);						//�˳�����
	}
	while ((ch = getc(fp)) != EOF)		//getc()���ļ���һ���ַ�
	{
		putchar(ch);
	}
	fclose(fp);							//�ر��ļ�

	getchar();		
	getchar();		
	getchar();		
	return 0;
}