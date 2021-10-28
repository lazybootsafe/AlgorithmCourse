/*5.�޸ĳ����嵥13.5�еĳ����������н�����潻��ʽ���档*/
//�����в���argv[1]����Ŀ���ļ��������漸��ΪԴ�ļ���
//�ó���Ѷ��Դ�ļ��ӵ�Դ�ļ�ĩβ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);
int main(int argc, char *argv[])
{
    FILE *fa, *fs;  // fa ָ��Ŀ���ļ���fs ָ��Դ�ļ�
    int files = 0;    // ���ӵ��ļ�����
    char ch;
    int i;

    if(argc<3)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    for(i=2;i<argc;i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                    continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n",argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n",argv[1]);
            fclose(fs);
            printf("File %s appended.\n", argv[i]);
        }
    }
    printf("%s contents:\n", argv[1]);
    rewind(fa);

    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // ֻ����һ��
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // ���һ��з�
        if (find)         // �����ַ����NULL��
            *find = '\0';    // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

