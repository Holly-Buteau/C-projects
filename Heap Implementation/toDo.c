/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
	int i;
    for (i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
	FILE *fp;
	char *fName = malloc(sizeof(char)* 250); 
	char description[100] = "";
	int priority;
	Task* fTask;
	//char *ptr;

    if (command == 'l')
{	
	printf("Enter the filename \n ");
	fgets(fName, 100, stdin);// != NULL)
/*	{
	char *cPtr;
	cPtr = strchr(fName, '\n');
	if(cPtr)
		*cPtr = '\0';
	}*/
	if (fName[strlen(fName) - 1] == '\n')
		fName[strlen(fName) - 1] = 0;
	
	fp = fopen(fName, "r");
	if (fp == NULL)
	{
		printf("\n%s\" File not found", fName);
		
	//	main();
	} 	

	listLoad(list, fp);
	
	printf("File opened \n");
	fclose(fp);
//	main();	
    //if (command == "s")
    
	
	
}

	if (command == 's')
	{
		if (dySize(list) > 0)
		{
			printf("Enter the filename \n");
			fgets(fName, sizeof(fName), stdin); 
			fp = fopen(fName, "w");
			if (fp == NULL)
			{
				printf("\n%s\" Can not open file \n", fName);
//				main();
			}
			
			listSave(list, fp);
			fclose(fp);
			printf("List was saved \n");
		}
		
		else 
		{	printf("Empty list \n");
			
		}
	}

	if(command == 'a')
	{
		printf("What is the task? \n");
		fgets(description, sizeof(description), stdin); 	
		printf("What is the priority? \n");
		scanf("%d", &priority);
		Task*  newT = taskNew(priority, description);
		dyHeapAdd(list, newT, taskCompare);
		printf("Task: %s has been added. \n", description);
			
	}
//main();

	if (command == 'g')
	{
		if(dySize(list) > 0)
		{	
			fTask = (Task*)dyGet(list, 0);
			printf("The first task is: %s\n\n", fTask->name);
		}
		else
			printf("Nothing to do yet. \n");
	}

	if(command == 'r')
	{
		if(dySize(list) == 0)
			printf("Your list is empty. \n");
		else
		{
			//description = (Task*)dyHeapGetMin(list)->name;
		   	dyHeapRemoveMin(list, taskCompare);
			printf("The first task  was removed \n");
		}	
	}	

	if (command == 'p')
	{
		if (dySize(list) > 0)
			listPrint(list);
		else
			printf("Your list is empty \n");
	}

	if(command == 'e')
	{	printf("Now leaving the program \n");
		exit(1);	
	}		
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}
