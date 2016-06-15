/* CS261- Assignment 1 - Q.3*/
/* Name: Holly Buteau
* Date: April 10. 2016
* Solution description: using sorting methods to sort in ascending order
*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n) {
	/*Sort the given array number , of length n*/
	int x;
	int y;
	for (x = 0; x < (n - 1); x++)
	{
		for (y = 0; y < (n - 1); y++)
		{
			int temp1 = number[y];
			int temp2 = number[y + 1];
			if (temp1 > temp2)
			{
				number[y + 1] = temp1;
				number[y] = temp2;
			}
		}
	}

}

int main() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	int x;

	/*Allocate memory for an array of n integers using malloc.*/
	int *array = (int *)malloc(sizeof(int) * n);
	/*Fill this array with random numbers, using rand().*/
	for (x = 0; x < n; x++)
		array[x] = rand();
	/*Print the contents of the array.*/
	printf("Contents of array are: \n");
	for (x = 0; x < n; x++)
		printf("%d \n", array[x]);
	/*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);
	/*Print the contents of the array.*/
	printf("Contents of sorted array are: \n");
	for (x = 0; x < n; x++)
		printf("%d \n", array[x]);
	return 0;
}

