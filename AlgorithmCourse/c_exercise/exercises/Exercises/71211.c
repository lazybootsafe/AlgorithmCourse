#if 0
#include <stdio.h>
#include <stdlib.h>

#define     ARTI 2.05f	//洋蓟
#define     BEET 1.15f	//甜菜
#define   CARROT 1.09f	//胡萝卜
#define DISCOUNT 0.05f	//每百元优惠

void menu(void);
float get_weight(void);

int main(void)
{
	float arti = 0;
	float beet = 0;
	float carrot = 0;
	char choice;
	float weight, amount, rebate, freight;//重量，数量，折扣，运费
	float total;	//总额

	menu();
	scanf_s("%c", &choice, 1);
	while (choice != 'e')
	{
		switch (choice)
		{
		case 'a':
			arti += get_weight();
			break;
		case 'b':
			beet += get_weight();
			break;
		case 'c':
			carrot += get_weight();
			break;
		case 'e':
			break;
		default:
			printf("Input error, try again.\n");
		}
		menu();
		scanf_s("%c", &choice, 1);
	}

	amount = arti * ARTI + beet * BEET + carrot * CARROT;
	weight = arti + beet + carrot;

	if (amount >= 100)
		rebate = amount * DISCOUNT;
	else
		rebate = 0;

	if (weight <= 5)
		freight = 6.5f;
	else if (weight > 5 && weight <= 20)
		freight = 14;
	else
		freight = 14 + (weight - 20)*0.5f;
	total = amount + freight - rebate;

	printf("The price of vegetable:\nartichoke %g$/pound, beet %g$/pound, carrot %g/pound .\n",\
		ARTI, BEET, CARROT);
	printf("You order %g pound artichoke, %g pound beet, %g pound carrot.\n", \
		arti, beet, carrot);
	printf("You total order %g pounds, discount %g$, amount %g$, freight %g$, total %g$.\n", \
		weight, rebate, amount, freight, total);

	return 0;
}

void menu(void)
{
	system("cls");
	printf("******************************************************************\n");
	printf("Choice you need.\n");
	printf("a) artichoke\t\t\tb) beets\n");
	printf("c) carrot\t\t\te) exit & checkout\n");
	printf("******************************************************************\n");
	printf("Please Enter you want to buy(a,b,c or e for exit): ");
}

float get_weight(void)
{
	float weight;
	printf("Enter how many pounds you buy: ");
	scanf_s("%f", &weight);
	printf("Add %g pound to cart.\n", weight);
	system("pause");
	return weight;
}

#endif