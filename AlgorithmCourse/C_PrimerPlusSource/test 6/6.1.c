#include <stdio.h>        //��ӡ26��Сд��ĸ
int main(void){
    int a[26],b;
    for(b=0;b<26;b++)
    {
        a[b]=(int)'a'+b;
        printf("%c ",a[b]);
    }
    return 0;
}
