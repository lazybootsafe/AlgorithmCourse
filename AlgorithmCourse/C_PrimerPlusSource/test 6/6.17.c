#include <stdio.h>  //��ʼ100��,�껯8%,ÿ��ȡ10��,����ȡ��
#define RATE 0.08  //�����껯8%
int main(void)
{
	int n;
	float mon=100.0;//100�򱾽�
	for(n=1;mon>=0;n++)
    {
        mon=mon*(1+0.08)-10;
    }
    printf("%d",n-1);
	return 0;
 }
