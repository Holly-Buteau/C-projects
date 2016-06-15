#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	list->sentinel = malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel;
   	list->sentinel->prev = list->sentinel;
   	list->size = 0;

	
}


/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link* link = malloc(sizeof(struct Link));
    	link->value = value;
    	link->next = 0;
    	link->prev = 0;
	
	return link;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);
	struct Link* newLink = createLink(value);
	newLink->next = link->next;
	link->next = newLink;
    	newLink->prev = link;
    	newLink->next->prev = newLink;
	newLink->value = value;
    	list->size++;
	
	
		

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);
	link->next->prev = link->prev;
    	link->prev->next = link->next;
	
	free(link);
    	list->size -= 1; 
    	
	
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	/* while (list->size > 0)
        {
                circularListRemoveFront(list);
        }
        free(list->sentinel);*/
	struct Link* link = list->sentinel->next;
	struct Link* nextLink = list->sentinel->next->next;
	int x;
	for (x = 0; x < list->size; x++)
	{
		//free(link);
		link = nextLink;
		free(link->prev);
		nextLink = nextLink->next;
		list->size--;
	}
	free(list->sentinel);
        
	
	
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	addLinkAfter(list, list->sentinel, value);
	
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	if (list->sentinel->prev == 0)
		list->sentinel->prev->value = value;
	else
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);
    	return list->sentinel->next->value;
	
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
        assert(list->size != 0);
	
        return list->sentinel->prev->value;
	
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
        assert(list->size != 0);
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	if (list->size == 0)
		return 1;
	else
		return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXE: you must write this
	assert(list != 0);
	assert(list->size != 0);
	struct Link* current = list->sentinel->next;
		
 	while(current != list->sentinel)
	{
		printf ("%g \n", current->value);
		current = current->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);
	struct Link* current = list->sentinel;
	struct Link* holder = list->sentinel->next;
	
	int x;
	for (x = 0; x < list->size; x++)
	{
		
		//holder = current->next;
		current->next = current->prev;
		current->prev = holder;
		current = holder;
		holder = holder->next;
		//
		//current = current->next;	
	}
	
		

		
}
