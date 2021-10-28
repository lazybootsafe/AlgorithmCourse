#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
	int ch, countchar, countword, countupper, countlower, countpunct, countnum;
	FILE *fp;							//�ļ�ָ��
	errno_t err;
	char fname[50];
	bool inword = false;

	countchar = countword = countupper = countlower = countpunct = countnum = 0;

	system("color 0A");
	printf("Please enter the name of the file��e.g.\"test.txt\"��:\n");
	scanf_s("%s", fname, sizeof fname);
	err = fopen_s(&fp, fname, "r");		//��ֻ����ʽ���ļ�����ȡ,ʧ�ܷ��ط�0������
	if (err)							//��ʧ��
	{
		printf("Failed to open the file!\n");
		exit(1);						//�˳�����
	}
	while ((ch = getc(fp)) != EOF)		//getc()���ļ���һ���ַ�
	{
		countchar++;					//�ַ�������
		if (!isspace(ch) && !inword)
		{
			countword++;				//���ʼ�����
			inword = true;
		}
		if (isspace(ch) && inword)
		{
			inword = false;
		}
		if (isupper(ch))
		{
			countupper++;				//��д��ĸ������
		}
		if (islower(ch))
		{
			countlower++;				//Сд��ĸ������
		}
		if (ispunct(ch))
		{
			countpunct++;				//�����ż�����
		}
		if (isdigit(ch))
		{
			countnum++;					//�����ַ�������
		}
	}
	fclose(fp);

	printf("The count of characters is %d\n", countchar);
	printf("The count of words is %d\n", countword);
	printf("The count of upper words is %d\n", countupper);
	printf("The count of lower words is %d\n", countlower);
	printf("The count of punctuation characters is %d\n", countpunct);
	printf("The count of number characters is %d\n", countnum);

	getchar();
	getchar();
	getchar();
	return 0;
}