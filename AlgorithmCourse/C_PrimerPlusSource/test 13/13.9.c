/*9.�޸ĳ����嵥 13.3 �еĳ��򣬴� 1 ��ʼ�����ݼ����б��˳��Ϊÿ��
���ʱ�š��������´�����ʱ��ȷ���µĵ��ʱ�Ž����ϴεı�ſ�ʼ��*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
    FILE *fp;
    char words[MAX];
    int i;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents:");
    rewind(fp);   /* ���ص��ļ���ʼ�� */
    for(i=1; (fscanf(fp, "%s", words) == 1) ; i++)
        printf("%d.%s\n",i,words);


    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
