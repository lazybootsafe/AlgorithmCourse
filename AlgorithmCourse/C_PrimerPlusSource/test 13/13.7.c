/*7.��дһ������������ļ�������ʹ�������в�������ʾ�û�������
������*/
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
#include <string.h>
#define SIZE 256
void printa(FILE *p1, FILE *p2);
void printb(FILE *p1, FILE *p2);

int main(int argc, char *argv[])
{
    FILE *p1,*p2;
    char name1[40],name2[40];


    if(argc<2)
    {
        printf("�������һ���ļ�����");
        fscanf(stdin,"%s",name1);
        printf("������ڶ����ļ�����");
        fscanf(stdin,"%s",name2);
    }
    else if(argc<3)
    {
        fprintf(stderr,"������2������.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        strcpy(name1,argv[2]);
        strcpy(name2,argv[3]);
    }
    if((p1=fopen(name1,"r")) ==NULL)
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name1);
    if((p2=fopen(name2,"r")) ==NULL)
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name2);
    puts("a��:");
    printa(p1,p2);
    fclose(p1);
    fclose(p2);
    printf("\n");
    putchar('\n');
    if((p1=fopen(name1,"r")) ==NULL)
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name1);
    if((p2=fopen(name2,"r")) ==NULL)
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name2);
    puts("b��:");
    printb(p1,p2);

    fclose(p1);
    fclose(p2);
    return 0;
}
//a��ӡ����
void printa(FILE *p1, FILE *p2)
{
    char ch[SIZE];
    char *r1,*r2;

    do
    {
        if((r1 = fgets(ch,SIZE,p1)) != NULL)
            fputs(ch,stdout);
        if((r2 = fgets(ch,SIZE,p2)) != NULL)
            fputs(ch,stdout);
    }
    while( r1!=NULL || r2!=NULL) ;
}
//b��ӡ����
void printb(FILE *p1, FILE *p2)
{
    char ch1,ch2;

    while( ch1!=EOF || ch2!=EOF)
    {
        while ((ch1=getc(p1)) !=EOF && ch1 != '\n' )
            putchar(ch1);
        while ((ch2=getc(p2)) !=EOF && ch2 != '\n' )
            putchar(ch2);
        putchar('\n');
    }
}


