#if 0
#include <stdio.h>
#include <stdlib.h>

#define   YEAR 5
#define MONTHS 12

void average_year(const float src[YEAR][MONTHS])
{
	int year, month;
	float subtot, total;

	printf(" YEAR      RAINFALL (inches)\n");
	for (year = 0, total = 0; year < YEAR; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += src[year][month];   //rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEAR);
}

void average_month(const float src[YEAR][MONTHS])
{
	int year, month;
	float subtot = 0;
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEAR; year++)
			subtot += src[year][month];
		printf("%4.1f ", subtot / YEAR);
	}
}

int main(void)
{
	const float rain[YEAR][MONTHS] =
	{
		{ 4.3f, 4.3f, 4.3f, 3.0f, 2.0f, 1.2f, 0.2f, 0.2f, 0.4f, 2.4f, 3.5f, 6.6f },
		{ 8.5f, 8.2f, 1.2f, 1.6f, 2.4f, 0.0f, 5.2f, 0.9f, 0.3f, 0.9f, 1.4f, 7.3f },
		{ 9.1f, 8.5f, 6.7f, 4.3f, 2.1f, 0.8f, 0.2f, 0.2f, 1.1f, 2.3f, 6.1f, 8.4f },
		{ 7.2f, 9.9f, 8.4f, 3.3f, 1.2f, 0.8f, 0.4f, 0.0f, 0.6f, 1.7f, 4.3f, 6.2f },
		{ 7.6f, 5.6f, 3.8f, 2.8f, 3.8f, 0.2f, 0.0f, 0.0f, 0.0f, 1.3f, 2.6f, 5.2f }
	};
	average_year(rain);
	average_month(rain);
	printf("\n");

	return 0;
}

#endif