#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(_MSC_VER)
#if _MSC_VER == 1800
#pragma message("Compiler Version��vs2013")

#endif // _MSC_

#endif // defined(_MSC_VER)

#define PI (4.0 * atan(1))			//ʹ���㹻������ű�֤��ȷ������˳��ͽ����
#define RAD_TO_DEG (180.0 / PI)

typedef struct polar_v
{
	double magnitude;
	double angle;
} POLAR_V;

typedef struct rect_v
{
	double x;
	double y;
} RECT_V;

//POLAR_V rect_to_polar(RECT_V);
__inline POLAR_V rect_to_polar(RECT_V rv)				//��֧��inline(��ϰһ��֮ǰ����������,Ҳ����д��һ����ⲿ�������塣��ע�⣺�洢����˵���������Ĵ洢��Ĭ����extern�ġ���
{
	POLAR_V pv;

	pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);		/*�����������ʾ��sqrt���޷��������ⲿ���ţ���ô˵����������������û���ҵ���ѧ�⡣
														UNIXϵͳҪ��ʹ��-lm���ָʾ������������ѧ�⣺cc _16.13_��ѧ�⺯��ʵ��.c -lm
														Linux��gnu������Ҳʹ����ͬ��ʽ��gcc _16.13_��ѧ�⺯��ʵ��.c -lm
														*/
	if (pv.magnitude == 0)
	{
		pv.angle = 0;
	}
	else
	{
		pv.angle = atan2(rv.y, rv.x) * RAD_TO_DEG;
	}
	
	return pv;
}

int main(void)
{
	RECT_V input;
	POLAR_V result;

	system("color 0A");
	puts("Enter x, y coordinates: enter q to quit:");
	while (scanf_s("%lf %lf", &input.x, &input.y) == 2)
	{
		result = rect_to_polar(input);
		printf("magnitude = %.2lf, angle = %.2lf\n",
			result.magnitude, result.angle);
	}
	puts("Bye!");

	system("pause");
	return 0;
}