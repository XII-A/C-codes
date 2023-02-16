#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "LAB4.h"


int main()
{
	struct nodeClass *head = NULL;

	int id, midterm;
	scanf("%d", &id);
	while(id!=-1)
	{
		scanf("%d", &midterm);
		insert(&head, id, midterm);
		scanf("%d", &id);
	}
	

	computeClassAverage(head);
	
	printAll(head);

	return 0;

}
