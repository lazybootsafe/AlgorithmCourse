#if 0
#include <stdio.h>
#include <stdlib.h>

void Temperatures(double fa);

int main(void)
{
	double input;
	printf("Enter a fahrenheit: ");
	while (scanf_s("%lf", &input) == 1)
	{
		Temperatures(input);
		printf("Enter next fahrenheit(press any char to quit): ");
	}

	return 0;
}

void Temperatures(double fa)
{
	const double f = 32;
	const double c = 273.16;
	double celsius;
	double kelvin;
	celsius = 5.0 / 9.0*(fa - f);
	kelvin = celsius * c;
	printf("%.2f. fahrenheit, equal %.2f celsius, and %.2f kelvin\n", fa, celsius, kelvin);
}

#endif