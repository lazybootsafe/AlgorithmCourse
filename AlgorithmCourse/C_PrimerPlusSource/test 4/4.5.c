/*5.��дһ��������ʾ�û���������λÿ�루Mb/s��Ϊ��λ�������ٶ�
�������ֽڣ�MB��Ϊ��λ���ļ���С��������Ӧ�����ļ�������ʱ�䡣ע
�⣬����1�ֽڵ���8λ��ʹ��float���ͣ�����/��Ϊ���š��ó���Ҫ������
�ĸ�ʽ��ӡ 3 ��������ֵ�������ٶȡ��ļ���С������ʱ�䣩����ʾС����
������λ���֣�
At 18.12 megabits per second, a file of 2.20 megabytes
downloads in 0.97 seconds.*/
#include <stdio.h>

int main(void)
{
    float size,time,speed;
    printf("�������ļ���С(MB)�ʹ���(Mb/s):");
    scanf("%f%f",&size,&speed);
    time=size*8.0/speed;
    printf("At %.2f megabits per second,a file of %.2f"
           " megabytes\ndownloads in %.2f seconds.\n"
           ,speed,size,time);

    return 0;
}
