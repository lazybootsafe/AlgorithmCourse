#include<stdio.h> //һ����������
void cube (double n);
int main(void)
{
    double numble=0.0;
    printf("����һ����:");
    scanf("%lf",&numble);
    cube(numble);
    system("pause");
    return 0;
}

void cube(double n)
{
    printf("%f��������:%f.\n",n,n*n*n);
}
