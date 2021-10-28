//�ݹ�ʵ�����������ʾ

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45	/*���Ƭ���������С*/

struct film
{
	char title[TSIZE];
	int rating;
	struct film * next;
};

void reverseTraversal(struct film * head);

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	//�ռ����洢��Ϣ
	system("color 0A");
	puts("Enter first movie title:");
	while (gets(input) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
		{
			;
		}
		current->rating &= 0xF;
		puts("Enter nwxt movie title (empty to stop):");
		prev = current;
	}

	//������Ӱ�б�
	if (head == NULL)
	{
		printf("No data entered.");
	}
	else
	{
		//�������
		puts("Here is the list of movies:");
		reverseTraversal(head);

		//�������
		/*current = head;
		while (current != NULL)
		{
			printf("Movie: %s Rating: %d.\n", current->title, current->rating);
			current = current->next;
		}*/
	}
	
	//��������ɣ�����ͷ���������ڴ�
	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//�ݹ�ʵ���������
void reverseTraversal(struct film * head)
{
	if (head != NULL)
	{
		reverseTraversal(head->next);
		printf("Movie: %s Rating: %d.\n", head->title, head->rating);
	}
}