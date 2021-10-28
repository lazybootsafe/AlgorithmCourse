#if 0
#include <stdio.h>
#include <stdlib.h>

#define  SINGLE 17850	//单租
#define  HOLDER 23900	//householder有家庭
#define   MARRY 26750	//已婚
#define DIVORCE 14875	//离异

#define BASE_TAX 0.15f
#define EXTRA_TAX 0.28f

void show_menu(void)
{
	system("cls");
	printf("Please select tax type, There are for type:\n");
	printf("1)Single\t2)House holder\n3)Married\t4)Divorced\n5)Quit\n");
	printf("Your selected type: ");
}

int main(void)
{
	char type;
	float salary;
	float tax, salary_taxed;
	printf("Please select tax type, There are for type:\n");
	printf("1)Single\t2)House holder\n3)Married\t4)Divorced\n5)Quit\n");
	printf("Please select your type: ");
	scanf_s("%c", &type, 1);
	while (type != '5')
	{
		switch (type)
		{
		case '1':
			show_menu();
			printf("Type single.\nEnter your salsry: ");
			scanf_s("%f", &salary);
			if (salary <= SINGLE)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = (SINGLE*BASE_TAX) + ((salary - SINGLE)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '2':
			show_menu();
			printf("Type house holder.\nEnter your salary: ");
			scanf_s("%f", &salary);
			if (salary <= HOLDER)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = HOLDER * BASE_TAX + ((salary - HOLDER)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '3':
			show_menu();
			printf("Type married.\nEnter your salary: ");
			scanf_s("%f", &salary);
			if (salary <= MARRY)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = (MARRY*BASE_TAX) + ((salary - MARRY)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '4':
			show_menu();
			printf("Type divorce.\nEnter your salary: ");
			scanf_s("%f", &salary);
			if (salary <= DIVORCE)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = DIVORCE * BASE_TAX + ((salary - DIVORCE)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '5':
			break;
		default:
			printf("Error selected type.\n");
		}
		printf("Please select your type: ");
		scanf_s("%c", &type, 1);
	}
	return 0;
}

#endif