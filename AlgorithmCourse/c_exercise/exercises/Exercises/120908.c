#if 0
#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int *pa;
	int size;
	int value;
	printf("Enter the number of elements: ");
	while (scanf_s("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");
	return 0;
}

int * make_array(int elem, int val)
{
	int *p = (int*)malloc(elem * sizeof(int));
	if (p == NULL)
		return NULL;
	for (int i = 0; i < elem; i++)
		p[i] = val;
	return p;
}

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if ((i + 1) % 8 == 0)
			putchar('\n');
	}
	putchar('\n');
}

#endif