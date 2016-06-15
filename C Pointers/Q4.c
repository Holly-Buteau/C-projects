/* CS261- Assignment 1 - Q.4*/
/* Name: Holly Buteau
* Date: April 10, 2016
* Solution description: working with sorting methods
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

void sort(struct student* students, int n) {
	/*Sort the n students based on their score*/
	int x;
	int y;
	for (x = 0; x < (n - 1); x++)
	{
		for (y = 0; y < (n - 1); y++)
		{
			int temp1 = students[y].score;
			int tempID1 = students[y].id;
			int temp2 = students[y + 1].score;
			int tempID2 = students[y + 1].id;
			if (temp1 > temp2)
			{
				students[y + 1].id = tempID1;
				students[y].id = tempID2;
				students[y + 1].score = temp1;
				students[y].score = temp2;
				
			}
		}
	}

}

int main() {
	/*Declare an integer n and assign it a value.*/
	int n = 10;
	/*Allocate memory for n students using malloc.*/
	struct student *myStudents = malloc(n * sizeof(struct student));
	/*Generate random IDs and scores for the n students, using rand().*/
	int j;
	int x;
	int y;
	int i;
	int k;
	for (j = 0; j < n; j++)
	{
		myStudents[j].id = 0;
		myStudents[j].score = rand() % 100 + 1;
	}

	while (myStudents[8].id == 0) //Not sure why 5 is the magic number but all other numbers result in some IDs still being 0
	{
		int test = 0;
		for (x = 0; x < 10; x++)
		{
			int q = rand() % 10 + 1;
			for (y = 0; y < 10; y++)
			{
				if (myStudents[y].id != 0)
				{
					if (q == myStudents[y].id)
						test = 1;
				}
			}


			if (test == 0)
				myStudents[x].id = q;
			test = 0;


		}
	}
	/*Print the contents of the array of n students.*/
	printf("Array of Students: \n");
	for (i = 0; i < 10; i++)
	{
		printf("ID: %d Score: %d \n", myStudents[i].id, myStudents[i].score);
	}
	/*Pass this array along with n to the sort() function*/
	sort(myStudents, n);
	/*Print the contents of the array of n students.*/
	printf("Array of Sorted Students: \n");
	for (k = 0; k < 10; k++)
	{
		printf("ID: %d Score: %d \n", myStudents[k].id, myStudents[k].score);
	}
	return 0;
}

