#include <stdio.h>
#include <stdlib.h>
		//�ַ����������ھ�̬�洢�࣬�ڳ������еĹ����У����ַ���ֻ�洢һ��
#define MSG "You must have many talents.Tell me some! "			//�����ַ�������1���ַ�������(λ��һ��˫�����ڵ��κ��ַ��ɱ�����׷�ӽ�β��־���ַ�����Ϊ�ַ������浽�ڴ�ռ�)																

#define LIM 5
#define LINELEN 81												/*����ַ������� + 1*/

int main(void)
{
	char name[LINELEN];											//�����ַ�������2��char����
	char talents[LINELEN];	

	//��ʼ��һ����Сȷ����char����, �ȱ�׼�����ʼ����Լ��:
	const char m1[40] = "Limit yourself to one line's worth.";		//��ʼ���ַ���ʱ�����뱣֤�ַ�����ĳ������ٱ��ַ�����1���������ɿ��ַ�'\0'��,�ַ�������ʣ���Ԫ�ؿռ䱻���ַ�'\0'���
	
	/*const char m1[40] = {		//��׼�����ʼ��,ע�⣺��׼��ʼ���ַ�����������ַ�������ֹ��'\0'������ֻ��һ���ַ�����
	'L', 'i', 'm', 'i', 't', ' ',
	'y', 'o', 'u', 'r', 's', 'e', 'l', 'f', ' ',
	't', 'o', ' ',
	'o', 'n', 'e', ' ',
	'l', 'i', 'n', 'e', '\'', 's', ' ',
	'w', 'o', 'r', 't', 'h', '.','\0'
	};*/

	//�ñ��������������С
	const char m2[] = "If you can't think of anything, fake it. ";
	
	//��ʼ��һ��ָ��
	const char * m3 = "\nEnough about me - what's your name?";	//�����ַ�������3��charָ��ָ�����ַ���ָ�����ִ����������ָ����һ���ַ����ַ���λ��PE�ļ�����Դ����
	
	//��ʼ��һ���ַ���ָ�������								
	const char * mytal[LIM] = {									//�����ַ�������4���ַ���ָ�����飬 
		"Adding numbers swiftly",
		"Multiplying accurately", 
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language" 
	};

	system("color 0A");
	printf("Hi! I'm Clyde the Computer. "                      "I have many talents.\n");	//����ַ��������м�û�м���������ǿո����ANSI C�Ὣ���Ǵ�������

	printf("Let me tell you some of them.\n");
	puts("What were they? Ah, yes, here's a partial list.");	//�ַ����������
	for (int i = 0; i < LIM; i++)
	{
		puts(mytal[i]);				/*��ӡ��������ܵ��б�*/
	}
	puts(m3);
	gets_s(name, LINELEN);										//�ַ�����ȡ�������ӵ�һ���ַ�����һ�����з�֮��������ַ�ȫ�����뵽name����ȡ81���ֽ�
	printf("Well, %s, %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);
	gets_s(talents, LINELEN);
	puts("Let's see if I've got that list: ");
	puts(talents);
	printf("Thanks for the information, %s\n", name);

	system("pause");
	return 0;
}