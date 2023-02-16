#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};


void printFB(struct nodeFB *startFB){
	while (startFB != NULL)
	{
		printf("%d %d\n",startFB->id,startFB->age);
		startFB = startFB->next;
	}
	printf("\n");
}

void printGS(struct nodeGS *startGS){
	while (startGS != NULL)
	{
		printf("%d\n",startGS->id);
		startGS = startGS->next;
	}
	printf("\n");
}

void printAll(struct newNodeFB *startNewFB){
	struct newNodeFB *tempNewFB = startNewFB;
	struct newNodeGS *tempNewGS = startNewFB->next;
	while(tempNewGS->next != NULL){
		printf("%d %d\n",tempNewFB->id,tempNewFB->age);
		printf("%d\n",tempNewGS->id);
		tempNewFB = tempNewGS->next;
		tempNewGS = tempNewFB->next;
		
		
	}
	printf("%d %d\n",tempNewFB->id,tempNewFB->age);
	printf("%d\n",tempNewGS->id);
		
	
	
}

void insertFB(struct nodeFB **startFB,int id,int age){
	struct nodeFB *temp = *startFB;
	struct nodeFB *Btemp = NULL;
	struct nodeFB *newnode = (struct nodeFB *)malloc(sizeof(struct nodeFB));
	int changemade = 0;
	newnode->id = id;
	newnode->age = age;
	newnode->next = NULL;
	if ( *startFB == NULL)
	{
		*startFB = newnode; 
	}else{
	
		while (temp->next != NULL)
		{
			if (id<temp->id && (Btemp != NULL) )
			{
				newnode->next = temp;
				Btemp->next = newnode;
				changemade = 1;
				break;
			}else if (id<temp->id)
			{
				newnode->next = (*startFB);
				(*startFB) = newnode;
				changemade = 1;
				break;
			}else{
				Btemp = temp;
				temp = temp->next;
			}
			
			
		}
		if (changemade == 0)
		{
			if ((*startFB)->next == NULL && (*startFB)->id > id)
			{
				newnode->next = (*startFB);
				(*startFB) = newnode;
			}else if ((*startFB)->next == NULL && (*startFB)->id < id)
			{
				(*startFB)->next = newnode;
			}else{
				if (temp->id > id)
				{
					Btemp->next = newnode;
					newnode->next = temp;
					temp->next = NULL;
				}else{
					temp->next = newnode;
				}
			}
			
			
		}

	}
	
	
	
	
}

void insertGS(struct nodeGS **startGS,int id){
	struct nodeGS *temp = *startGS;
	struct nodeGS *Btemp = NULL;
	struct nodeGS *newnode = (struct nodeGS *)malloc(sizeof(struct nodeGS));
	int changemade = 0;
	newnode->id = id;
	newnode->next = NULL;
	if ( *startGS == NULL)
	{
		*startGS = newnode; 
	}else{
	
		while (temp->next != NULL)
		{
			if (id>temp->id && (Btemp != NULL) )
			{
				newnode->next = temp;
				Btemp->next = newnode;
				changemade = 1;
				break;
			}else if (id>temp->id)
			{
				newnode->next = (*startGS);
				(*startGS) = newnode;
				changemade = 1;
				break;
			}else{
				Btemp = temp;
				temp = temp->next;
			}
			
			
		}
		if (changemade == 0)
		{
			if ((*startGS)->next == NULL && (*startGS)->id < id)
			{
				newnode->next = (*startGS);
				(*startGS) = newnode;
			}else if ((*startGS)->next == NULL && (*startGS)->id > id)
			{
				(*startGS)->next = newnode;
			}else{
				if (temp->id < id)
				{
					Btemp->next = newnode;
					newnode->next = temp;
					temp->next = NULL;
				}else{
					temp->next = newnode;
				}
				
			}
			
			
		}

	}
}

void insertNEWGS(struct newNodeGS **startNewGS,struct nodeGS *startGS){
	struct newNodeGS *NewNode = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
	NewNode->id = startGS->id;
	NewNode->next = NULL;
	*startNewGS = NewNode;
	 
}
void insertNEWFB(struct newNodeFB **startNewFB,struct nodeFB *startFB){
	struct newNodeFB *NewNode = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
	NewNode->id = startFB->id;
	NewNode->age = startFB->age;
	NewNode->next = NULL;
	*startNewFB = NewNode;
	 
}

void createFinalList(struct newNodeFB **startNewFB,struct nodeFB *startFB,struct nodeGS *startGS){
	
	insertNEWFB(startNewFB,startFB);
	struct newNodeFB *tempNewFB = *startNewFB;
	
	struct newNodeGS *tempNewGS = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
	insertNEWGS (&((*startNewFB)->next),startGS);
	tempNewGS = (*startNewFB)->next;
	tempNewFB->next = tempNewGS;

	while (startGS->next != NULL)
	{
		startFB = startFB->next;
		startGS = startGS->next;
		insertNEWFB(&(tempNewGS->next),startFB);
		tempNewFB = tempNewGS->next;
		insertNEWGS(&(tempNewFB->next),startGS);
		tempNewGS = tempNewFB->next;
	}
	
	


	
	
}


// You need to write all the function definitions to be used in this lab in this file.
// You can call other functions that you define from the mandatory functions.
// Do not make any changes to the main.c file.
// Upload the file function.h to the system as StudentNumber.h. 


