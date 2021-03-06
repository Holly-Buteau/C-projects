/* CS261- Assignment 1 - Q.2*/
/* Name: Holly Buteau	
* Date: April 5, 2016
* Solution description: using pointer manipulation to add and subtract ints
*/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c) {
	/*Set a to double its original value*/
	*a = *a * 2;
	/*Set b to half its original value*/
	*b = *b / 2;
	/*Assign a+b to c*/
	c = *a + *b;
	/*Return c*/
	return c;
}

int main() {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
	int value;
	/*Print the values of x, y and z*/
	printf("The value of x is: %d \n", x);
	printf("The value of y is: %d \n", y);
	printf("The value of z is: %d \n", z);
	/*Call foo() appropriately, passing x,y,z as parameters*/
	value = foo(&x, &y, z);
	/*Print the value returned by foo*/
	printf("The value returned by foo is: %d \n", value);
	/*Print the values of x, y and z again*/
	printf("The value of x is: %d \n", x);
	printf("The value of y is: %d \n", y);
	printf("The value of z is: %d", z);
	/*Is the return value different than the value of z?  Why?*/
	return 0;
}



