#include "../inc/qgsort.h"
#include "qgsort.c"


int main()
{	
	char t;

	menu();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
    while((t = getchar()) != 'i')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'h')
		{	
			switch(t)
			{
			    case'a':
					printf("\n����������\n");
					print(insertSort);
					reactive();
					break;
				case'b':
					printf("\n���鲢����\n");
					print(merge);
					reactive();
					break;
				case'c':
					printf("\n����������(�ݹ�)��\n");
					print(quicksort_re);
					reactive();
					break;
				case'd':
					printf("\n����������(�ǵݹ�)��\n");
					print(QuickSort);
					reactive();
					break;
				case'e':
					printf("\n����������\n");
					print(count);
					reactive();
					break;
				case'f':
					printf("\n��������������\n");
					print(RadixCountSort);
					reactive();
					break;
				case'g':
					printf("\n����ɫ����\n");
					print(ColorSort);
					reactive();
					break;
				case'h':
					printf("\n������Ѱ�㡿\n");
					print(find);
					reactive();
					break;
			}
		}
		else 
			printf("\n�������,����������:  ");

		while(getchar() != '\n')
			continue;
	}		
    return 0;
}



