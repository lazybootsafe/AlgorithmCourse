#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float height;
	char name[20];
	printf("Enter your name: ");
	scanf_s("%s", &name, 19);
	printf("Enter your height: ");
	scanf_s("%f", &height);
	//Ó¢´ç×ªÓ¢³ß 1Ó¢³ßµÈÓÚ12Ó¢´ç
	printf("%s, you are %.2f feet tall", name, height / 12);

	return 0;
}

#endif