/*7.��дһ�����򣬽�һ��double���͵ı�������Ϊ1.0/3.0��һ��float��
�͵ı�������Ϊ1.0/3.0���ֱ���ʾ���μ���Ľ����3�Σ�һ����ʾС����
����6λ���֣�һ����ʾС�������12λ���֣�һ����ʾС�������16λ��
�֡�������Ҫ����float.hͷ�ļ�������ʾFLT_DIG��DBL_DIG��ֵ��1.0/3.0
��ֵ����Щֵһ����*/
#include <stdio.h>
#include <float.h>
int main(void)
{
    double a=1.0/3.0;
    float b=1.0/3.0;
    printf("double:%.6lf %.12lf %.16lf\n",a,a,a);
    printf("float:%.6lf %.12lf %.16lf\n",b,b,b);
    printf("FLT_DIG:%d\n",FLT_DIG);
    printf("DBL_DIG:%d\n",DBL_DIG);

    return 0;
}
