#include <stdio.h>
#include <ctype.h>		//�ṩislower()����ԭ��

int main(void)
{
	//��ʾ�û�����һ��Сд��ĸ���������һ���Ը�Сд��ĸ��ͷ�Ķ�������

	char ch;

	printf("Give me a letter of the alphabet, and i will give ");
	printf("an animals name \nbeginning with that letter.\n");
	printf("Please type in a letter : type # to end my act.\n");
	while ((ch = getchar()) != '#')
	{
		if (islower(ch))
		{
			switch (ch)
			{
			case 'a':
				printf("argali, a wild sheep of Asia\n");
				break;
			case 'b':
				printf("babirusa, a wild pig of Malay\n");
				break;
			case 'c':
				printf("coati, racoonlike mammal\n");
				break;
			case 'd':
				printf("desman, aquatic, molelike critter\n");
				break;
			case 'e':
				printf("echidna, the spiny anteater\n");
				break;
			case 'f':
				printf("fisher, brownish marten\n");
				break;
			default:
				printf("That's a stumper!\n");
				break;
			}
		}
		else
		{
			printf("I recognize only lowercase letters.\n");
		}
		while (getchar() != '\n')
		{
			continue;	/*���������е�ʣ�ಿ��,
						�������һ���ַ���
						�����ַ�������ȡ��������
						����ȡ�������һ�����з�ʱ���¸��ַ�����һ�е����ַ�,�����whileѭ����getchar()��ȡ����ֵ��ch,
						*/
		}
		printf("Please type another letter or a #.\n");
	}
	printf("Bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}