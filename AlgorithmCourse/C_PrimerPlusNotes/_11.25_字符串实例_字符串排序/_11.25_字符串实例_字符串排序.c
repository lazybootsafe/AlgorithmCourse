#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 81			//�ַ�����������(�������ַ�)
#define ROWS 20			//����ȡ������


void stsrt(char * ptstr[], int rows);		//ָ������

int main(void)
{
	char input[ROWS][SIZE];			//�ַ�������
	char * ptstr[ROWS];				//ָ�����鱣��ÿ���ַ����ĵ�ַ(������ָ���ַ�����ָ���������ע���ַ�������ÿ���ַ�������Ϊָ��ʱ�����ܽ���ָ�룬��Ϊ����ָ���ַ����ĵ�ַ�����������������޸�)
	int ct = 0;						//�������
	int i;							//�������
	
	system("color 0A");

	printf("Input up to %d lines, and I will sort them.\n", ROWS);
	printf("To stop, press the Enter key ay a line's start.\n");
	while (ct < ROWS && gets_s(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];		//ָ�������Աָ��ÿһ���ַ���
		ct++;						//ͳ��������ַ�����
	}
	stsrt(ptstr, ct);				//ָ������
	puts("\nHere's the sorted list: \n");
	for (i = 0; i < ct; i++)
	{
		puts(ptstr[i]);				//��ӡ������ָ��ָ����ַ���
	}

	getchar();
	return 0;
}


//�ַ���ָ��������
void stsrt(char * ptstr[], int rows)
{
	char * temp;

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = i + 1; j < rows ; j++)
		{
			if (strcmp(ptstr[i], ptstr[j])> 0)
			{
				temp = ptstr[i];
				ptstr[i] = ptstr[j];
				ptstr[j] = temp;
			}
		}
	}
}