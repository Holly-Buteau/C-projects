#include "stdio.h"


int main(void)
{
	int numFeet;
	int inches;
	printf ("\n");

	printf("We are going to convert feet to inches.");
	printf("\n");
	printf ("Please enter how many feet and I will tell you the number of inches.");
	printf ("\n");
	scanf("%d", &numFeet);
	inches = numFeet * 12;
	printf("The number of inches is: %i\n", inches);
	return 0;

}
