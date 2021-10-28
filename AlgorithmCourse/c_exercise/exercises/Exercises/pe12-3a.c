#include "pe12-3a.h"

void set_mode3a(int * mode)
{
	if (*mode == 0 || *mode == 1)
		return;
	else
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		*mode = 1;
	}
}

void get_info3a(int mode, double * distance, double * fuel)
{
	if (mode == 0)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%lf", distance);
		printf("Enter fuel consumed in liters: ");
		scanf_s("%lf", fuel);
		return;
	}
	if (mode == 1)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%lf", distance);
		printf("Enter fuel consumed in gallon: ");
		scanf_s("%lf", fuel);
		return;
	}
}

void show_info3a(int mode, double distance, double fuel)
{
	if (mode == 0)
		printf("Fuel consumption is %.2lf liters per 100 km.\n", \
		(fuel / distance) * 100);
	else
		printf("Fuel consumption is %.1lf miles per gallon.\n", \
			distance / fuel);
}