#include <stdio.h>/*10.ʮ����ת2-10����*/
void to_base_n(unsigned long n,unsigned int base);
int main(void)
{
    unsigned long num;
    unsigned int base;

    printf("����һ������(q�뿪):\n");
    while (scanf("%lu%u", &num,&base) == 2)
    {
        printf("����%u����: ",base);
        to_base_n(num,base);
        putchar('\n');
        printf("����һ������(q�뿪):\n");
    }
    printf("�깤.\n");

    return 0;
}

void to_base_n(unsigned long n,unsigned int base)
{
    int r;

    r = n % base;
    if (n >= base)
        to_base_n(n/base,base);
    printf("%d",r);
}


