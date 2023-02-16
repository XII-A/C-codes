#include <stdio.h>
#include <stdlib.h>
#define MAX_Prio 9999

typedef struct node
{
    int val;
    struct node * next;
    int priority;
}node;


void insert(node **Front,node **Rear,int val){
    node * newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->priority = MAX_Prio;
    if ((*Front) == NULL && (*Rear) == NULL)
    {
        (*Rear) = newnode;
        (*Front) = (*Rear);
    }else{
        (*Rear)->next = newnode;
        (*Rear) = newnode;
    }
    
}

void Display(node *Front){
    while (Front != NULL)
    {
        printf("%d-",Front->val);
        Front = Front->next;
    }
    
}

void Delete(node **Front){
    node *ptr = (*Front);
    (*Front) = (*Front)->next;
    free(ptr);

}

void insert_prio(node **Front,node ** Rear,int val,int prio){
    node * newnode = (node *)malloc(sizeof(node));
    newnode->priority = prio;
    newnode->val = val;
    newnode->next = NULL;

    
    if (newnode->priority < (*Front)->priority)
    {
        newnode->next = (*Front);
        (*Front) = newnode;
    }else
    {
        node * ptr = (*Front);
        node * prev = NULL;
        while (newnode->priority > ptr->priority && ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            (*Rear)->next = newnode;
            (*Rear) = newnode;
        }else{
            prev->next = newnode;
            newnode->next = ptr;
        }
        
        
    }
    
    


}











int main(){
    int i;
    node * Front = NULL;
    node * Rear = NULL;
    for ( i = 0; i < 10; i++)
    {
        insert(&Front,&Rear,i);
    }
    Display(Front);
    printf("\n");
    int prio = rand()%10;
    printf("%d->",prio);
    for ( i = 10; i < 20; i++)
    {
        insert_prio(&Front,&Rear,i, prio);
        prio = rand()%10;
        printf("%d->",prio);
    }
    printf("\n");
    Display(Front);






}