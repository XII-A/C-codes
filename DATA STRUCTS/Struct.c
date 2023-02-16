#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void push(struct node**top,int value){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = *top;
    *top = newnode;
}
 

int main(){
    struct node * top = (struct node *)malloc(sizeof(struct node));
    top->value = 12;
    top->next = NULL;
    int i;
    for ( i = 0; i < 10; i++)
    {
        push(&top,i);
    }
    for ( i = 0; i < 11; i++)
    {
        printf("%d ",top->value);
        top = top->next;
    }
    
    

}