#include<stdio.h> //���ת��ΪӢ�ߺ�Ӣ��
#define FEET 2.54 //1 feet=2.54cm
#define INCH 30.48 //1 inch=30.48cm
int main(void)
{
    float height=0,inch=0;
    int feet=0;
    printf("������������(cm):");
    scanf("%f",&height);
    while(height>0)
    {
        feet=(int)(height/INCH);
        inch=(height-feet*INCH)/FEET;
        printf("%.1f cm =%d Ӣ��, %.1f Ӣ��.\n",height,feet,inch);
        printf("��������0ʱ����\n");
        scanf("%f",&height);
    }
    system("pause");
    return 0;
}
