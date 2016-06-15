/* CS261- Assignment 1 - Q. 0*/
/* Name: Holly Buteau
* Date: April 4, 2016
* Solution description: using pointers to manipulate data
*/

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/

	printf("Value of iptr is: %d \n", *iptr);
	/*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr is: %p \n", &*iptr);
	/*Print the address of iptr itself*/
	printf("Address of iptr: %p \n", &iptr);

}

int main() {

	/*declare an integer x*/
	int x = 10;
	/*print the address of x*/
	printf ("Address of x: %p \n" , &x);
		/*Call fooA() with the address of x*/
	fooA(&x);
		/*print the value of x*/
	printf("Value of x is: %d", x);
		return 0;
}

