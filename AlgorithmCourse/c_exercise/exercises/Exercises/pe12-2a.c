#include "pe12-2a.h"

void set_mode(int set)
{
	if (0 == set || 1 == set)
		mode = set;
	else
		printf("Invalid mode specified. Mode %s used.\n",\
		(mode ? "1(US)" : "0(metric)"));
}

void get_info(void)
{
	if (0 == mode)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%lf", &distance);
		printf("Enter fuel comsumed in liter: ");
		scanf_s("%lf", &fuel_consumed);
		return;
	}
	if (1 == mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf_s("%lf", &fuel_consumed);
		return;
	}
}

void show_info(void)
{
	if (0 == mode)
	{
		printf("Fuel consumption is %.2lf liters per 100km\n", \
			((fuel_consumed / distance) * 100));
		return;
	}
	if (1 == mode)
	{
		printf("Fule consumption is %.1lf miles per gallon.\n",\
			distance / fuel_consumed);
		return;
	}
}
