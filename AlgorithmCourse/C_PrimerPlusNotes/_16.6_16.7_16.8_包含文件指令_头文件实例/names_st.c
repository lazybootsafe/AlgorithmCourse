//����names_st����

#include <stdio.h>
#include <stdlib.h>
#include "names.h"		//����ͷ�ļ�

//��������
void get_names(names * pn)
{
	int i;

	system("color 0A");

	printf("Please enter your first name: ");
	fgets(pn->first, SLEN, stdin);
	i = 0;
	while (pn->first[i] != '\n' && pn->first[i] != '\0')
	{
		i++;
	}
	if (pn->first[i] == '\n')		//�����������ַ����д��ڻ��з������ÿ��ַ�����û��з�
	{
		pn->first[i] = '\0';
	}
	else							//���򣬱�ʾfgets()�ڴﵽ��β֮���Ѿ�ֹͣ��ȡ��Ϊ�˲�Ӱ�����IO����������ȥ���û������ʣ���С�
	{
		while (getchar() != '\n')
		{
			continue;
		}
	}

	printf("Please enter your last name: ");
	fgets(pn->last, SLEN, stdin);
	i = 0;
	while (pn->last[i] != '\n' && pn->last[i] != '\0')
	{
		i++;
	}
	if (pn->last[i] == '\n')
	{
		pn->last[i] = '\0';
	}
	else
	{
		while (getchar() != '\n')
		{
			continue;
		}
	}
}

void show_names(const names * pn)
{
	printf("%s %s", pn->first, pn->last);
}