/* CS261- Assignment 1 - Q.1*/
/* Name: Holly Buteau
* Date: April 4, 2016
* Solution description: creating a struct of student IDs and Scores
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	int numStudents = 10;
	struct student *myStudents = malloc(numStudents * sizeof(struct student));
	/*return the pointer*/
	return myStudents;
}

void generate(struct student* students) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int j;
	int x;
	int y;	
	for (j = 0; j < 10; j++)
	{
		students[j].id = 0;
		students[j].score = rand() % 100 + 1;
	}

	while (students[8].id == 0) //Not sure why 5 is the magic number but all other numbers result in some IDs still being 0
	{
		int test = 0;
		for (x = 0; x < 10; x++)
		{
			int q = rand() % 10 + 1;
			for (y = 0; y < 10; y++)
			{
				if (students[y].id != 0)
				{
					if (q == students[y].id)
						test = 1;
				}
			}

			
				if (test == 0)
					students[x].id = q;
				test = 0;
		

		}
	}
}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	int y;
	for (y = 0; y < 10; y++)
	{
		printf("ID: %d Score: %d \n", students[y].id, students[y].score);
	}
}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int max = students[0].score;
	int min = students[0].score;
	double average = 0;
	int i = 0;
	int x;
	for (x = 0; x < 10; x++)
	{
		if (students[x].score > max)
			max = students[x].score;
		if (students[x].score < min)
			min = students[x].score;
		average += students[x].score;
		i++;
	}
	average = average / i;

	printf("Minimum is: %d \n", min);
	printf("Maximum is: %d \n", max);
	printf("Average is: %g \n", average);
}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	/*int i;
	for (i = 0; i < 10; i++)
	{
		if (stud[i].id > 0 && stud[i].id <= 10)
			free(stud);
	}*/
	free(stud);
}

int main() {
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);
	return 0;
}

