#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

/**************************************************************************************************************

	ǰ�ԣ�

	�ڽṹ�н���ʹ���ַ����飬��������ַ�ָ��ĺ��岢�����
	1.ʹ���ַ����飬�ַ���ֱ�Ӵ洢�ڽṹ�ڲ�
	2.ʹ���ַ�ָ�룬�洢���ַ�ָ�룬ָʾ�˴洢�ַ����ĵ�ַ�����ַ����洢�ڳ����������ط����ڱ������洢�ַ����������κεط���
	  �����printf("%s",person.fname);//�����������У�person.fnameָʾ�˴洢�����ݶε��ַ��������ĵ�ַ	
	  ���ǣ�scanf("%s",person.fname)��//����û���⣬����һ��Ǳ�ڵķ��ա�
									person.fname���ַ�ָ�룬ָʾ��scanf()������һ���ַ�����person.fnameָʾ�ĵ�ַ������
									����ָ�����δ����ʼ�������Ե�ַ�������κ�ֵ������Ϳ��԰Ѹ��ַ��������κεط���
									������˵Ļ�������������Щʱ������������С����������������ʹ���򳹵�ֹͣ��
									ʵ���ϣ�����������У����Ǻܲ��ҵģ���Ϊ�����к����û�δ�������Σ�յı�̴���
	��ˣ������Ҫһ���ṹ���洢�ַ�����Ӧ��ʹ���ַ������Ա���洢�ַ�ָ���������ô�����Ҳ�б��������õĿ��ܡ�

	************************************************************************************************************
	���ڣ�

	�ڽṹ��ʹ��ָ�봦���ַ����������һ�����ӡ���ʹ��malloc()�����ڴ棬����ָ������ŵ�ַ��

	����������ŵ��ǣ���������malloc()����պ������ַ������������Ŀռ䡣��������4�ֽ����洢"Joe"���ȵȡ�

	��ע�⣺ʹ��malloc()������ڴ��ڳ���ִ���ڼ�һֱ���ڣ�ֱ��free()�ͷŸ�ռ���ڴ档��malloc() ������ڴ�洢ʱ���ǵ����ڴ���亯����ʼһֱ����һ�ε���free()Ϊֹ��
		�������ǰѧ���ģ�������ӡ��(^_^)��
	������ʵ����
*/

struct namect
{
	char * fname;						//ʹ���ַ�ָ��
	char * lname;
	int letters;
};

void getinfo(struct namect *);			//�����ڴ�
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);			//�����ʱ�ͷ��ڴ�

int main(void)
{
	struct namect person;

	system("color 0A");
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	system("pause");
	return 0;
}

void getinfo(struct namect * pst)
{
	char temp[SIZE];

	printf("Please enter your first name:\n");
	gets_s(temp, SIZE);
	pst->fname = (char *)malloc((strlen(temp) + 1) * sizeof(char));		//���������ֵ��ڴ�
	strcpy_s(pst->fname, (strlen(temp) + 1), temp);						//�����ָ��Ƶ��ѷ�����ڴ���
	printf("Please enter your last name:\n");
	gets_s(temp, SIZE);
	pst->lname = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(pst->lname, (strlen(temp) + 1), temp);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{ 
	printf("%s %s, your name contains %d letters.\n", 
		pst->fname, pst->lname, pst->letters);		//��ӳ�Ա�����ͨ���ṹָ���ӷ��ʽṹ��Ա���ṹ��Ա�����ͨ���ṹ��ֱ�ӷ��ʽṹ��Ա��
}

void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}