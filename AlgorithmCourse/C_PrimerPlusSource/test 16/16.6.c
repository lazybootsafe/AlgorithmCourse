/*6.�޸ĳ����嵥16.17��ʹ��struct namesԪ�أ��ڳ����嵥16.17�����
�����ж��������������double���͵����顣ʹ�ý��ٵ�Ԫ�أ�����ѡ����
������ʽ��ʼ�����顣*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define NUM 7
struct names {
    char first[SIZE];
    char last[SIZE];
};

int comp(const void * p1, const void * p2);
int main(void)
{
    int i;
    struct names staff[NUM]={
        {"��","��߷"},
        {"��","����"},
        {"��","��֭"},
        {"��","Ц��"},
        {"��","�Ϸ�"},
        {"л","ͦ��"},
        {"��","�»�"}
    };
    puts("ԭ�����ǣ�");
    for(i=0;i<NUM;i++)
        printf("%s%s\n",staff[i].first,staff[i].last);
    qsort(staff, NUM, sizeof(struct names),comp);
    puts("\n������ǣ�");
    for(i=0;i<NUM;i++)
        printf("%s%s\n",staff[i].first,staff[i].last);


    puts("\n�ټ�.");

    return 0;
}

/* ����С�����˳������ */
int comp(const void * p1, const void * p2)
{
/* Ҫʹ��ָ��������������ֵ */
    const struct names *a1 = (const struct names *)p1;
    const struct names *a2 = (const struct names *)p2;
    int temp=strcmp(a1->first,a2->first);

    return temp? temp : strcmp(a1->last,a2->last) ;
}
