#include <stdio.h>  //���㼸�����ѳ���150
# define DUN 150
int main(void)
{
	int man=5,n;  //nΪ��,manΪ����
    for(n=1;man<=DUN;n++)
    {
        man-=n;
        man*=2;
        printf("��%d��,��%d������\n",n,man);
    }
	return 0;
}
