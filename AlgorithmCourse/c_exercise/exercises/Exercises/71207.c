#if 0
#include <stdio.h>

#define BASIC_SALARY 10		//��������
#define EXTRA_HOUR 1.5f		//�Ӱ�
#define BASIC_TAX 0.15f		//����˰��
#define EXTRA_TAX 0.2f		//�м�˰��
#define EXCEED_TAX 0.25f	//����˰��

int main(void)
{
	float hours;			//��ʱ
	float salary;			//˰ǰ����
	float taxed_salary;		//˰����
	float tax;				//Ӧ������˰

	printf("Enter the working hours a week:");
	scanf_s("%f", &hours);
	if (30 >= hours)
	{
		salary = hours * BASIC_SALARY;
		tax = salary * BASIC_TAX;
		taxed_salary = salary - tax;
	}
	else if (40 >= hours)
	{
		salary = hours * BASIC_SALARY;
		tax = 300 * BASIC_TAX + (salary - 300)*EXCEED_TAX;
		taxed_salary = salary - tax;
	}
	else
	{
		salary = 40 + ((hours - 40) * EXTRA_HOUR) * BASIC_SALARY;
		if (salary <= 450)
		{
			tax = (300 * BASIC_TAX) + (salary - 300)*EXTRA_TAX;
		}
		else
		{
			//tax = (300 * BASIC_TAX) + (150 * EXCEED_TAX) + (salary - 450)*EXCEED_TAX;
			tax = (300 * BASIC_TAX) + (salary - 300)*EXTRA_TAX + (salary - 450)*EXCEED_TAX;
		}
		taxed_salary = salary - tax;
	}
	printf("Your salary before tax is %.2f, tax is %.2f, salary after tax is %.2f\n", salary, tax, taxed_salary);

	return 0;
}

#endif