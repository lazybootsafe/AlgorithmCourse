#include "../head/SqStack.h"
#include "SqStack.c"

void main()
{
	SqStack *sta=NULL;  
	char t;
    
    
	abc();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
    while((t = getchar()) != 'j')
	{
		if(t == '\n')
			continue;
		if('a' <= t && t <= 'i')
		{	
			switch(t)
			{
			    case'a':
					init(&sta);
					wsg();
					break;
				case'b':
					isempty(sta);
					wsg();
					break;
				case'c':
					gettop(sta);
					wsg();
					break;
				case'd':
					clear(sta);
					wsg();
					break;
				case'e':
					destroy(sta);
					sta = NULL;
					wsg();
					break;
				case'f':
					length(sta);
					wsg();
					break;
				case'g':
					push(sta);
					wsg();
					break;
				case'h':
					pop(sta);
					wsg();
					break;
				case'i':
					print(sta);
					wsg();
					break;
			}
		}
		else 
			printf("\n�������,����������:  ");

		while(getchar() != '\n')
			continue;
	}
	printf("�����Ѿ���������л���ʹ��\n");
    getchar();
}

