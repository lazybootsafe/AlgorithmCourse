#include "stuManager.h"
#include "stuManager.cpp"

// ������
void main()
{	
	int i;
	LinkedList stu;
	
	init(stu);
	readFile(stu);

	menu();
	printf("\n��ѡ�����������: ");
    while((i = inputInt()) != 6)
	{	
		if(1 <= i && i <= 5)
		{	
			switch(i)
			{
				case 1:
					// [����]һ��ѧ��
					add(stu);
					writeFile(stu);
					reactive();
					break;
				case 2:
					// [ɾ��]һ��ѧ��
					del(stu);
					writeFile(stu);
					reactive();
					break;
				case 3:
					// [����]ѧ����Ϣ
					searchStu(stu);
					reactive();
					break;
				case 4:
					// [�޸�]ѧ����Ϣ
					change(stu);
					reactive();
					break;
				case 5:
					// [��ӡ]ȫ��ѧ��
					printfALL(stu);
					reactive();
					break;
			}
		}
		else 
			printf("\n��ѡ�������ѡ����������,������ѡ��:  ");
	}
	printf("\n\n�������������Ѿ���������л����ʹ�ã�\n\n");
}

