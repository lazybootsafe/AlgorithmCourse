#include<stdio.h>/*12.��д�����嵥10.7��rain.c���򣬰�main()�е���Ҫ���񶼸ĳ��ú���
����ɡ�*/
#define MONTHS 12   // һ����·���
#define YEARS 5   // ����
double every_year_rain(const double ar[][MONTHS], int years);// ÿһ�꣬���µĽ�ˮ���ܺ�
double both_years_rain(const double ar[][MONTHS], int years);// 5����ܽ�ˮ��
double every_month_rain(const double ar[][MONTHS], int years); // ÿ���£�5����ܽ�ˮ��
int main(void)
{
    // ��2010��2014��Ľ�ˮ�����ݳ�ʼ������
    const double rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5,  6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4,  7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1,  8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3,  6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6,  5.2 }
    };

    every_year_rain(rain , YEARS);
    printf("\n");
    both_years_rain(rain , YEARS);
    printf("\n");
    every_month_rain(rain , YEARS);

    return 0;
}

double every_year_rain(const double ar[][MONTHS], int years)// ÿһ�꣬���µĽ�ˮ���ܺ�
{
    int i,j;
    double tol=0;

    printf("��\t12���½�ˮ���ϼ�\n");
    for(i=0;i<years;i++)
    {
        for(j=0,tol=0;j<MONTHS;j++)
            tol+=ar[i][j];
        printf("%d\t%g\n",i+2010,tol);
    }
}

double both_years_rain(const double ar[][MONTHS], int years)// 5����ܽ�ˮ��
{
    int i,j;
    double tol=0;

    for(i=0;i<years;i++)
        for(j=0;j<MONTHS;j++)
            tol+=ar[i][j];
    printf("%d���ƽ����ˮ����:%g\n",YEARS,tol/YEARS);
}

double every_month_rain(const double ar[][MONTHS], int years) // ÿ���£�5����ܽ�ˮ��
{
    int y,m;
    double tol=0;

    printf("�·�\t%d��������ƽ����ˮ��\n",YEARS);
    for(m=0;m<MONTHS;m++)
    {
        for(y=0,tol=0;y<years;y++)
            tol+=ar[y][m];
        printf("%d��\t%g\n",m+1,tol/years);
    }
}
