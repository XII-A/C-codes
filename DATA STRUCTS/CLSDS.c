#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node * next;
};
typedef struct Node Node;

//creating new nodes in a diff funcs to avoid loosing the head and loop connection issues
Node * create_node(int i){
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->value = i;
    new_node->next = NULL;
    return new_node;
}

void IniaterCDLS(Node *Head){
    Node *ptr = Head;
    int i;
    for ( i = 2; i < 21; i++)
    {
     
      ptr->next = create_node(i);
      ptr = ptr->next;
        
        
    }
    ptr->next = Head;
    
    
}

//insert funcs
void insert_beg(Node **Head,Node *newnode){
    Node * ptr = *Head;
    while (ptr->next != *Head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = *Head;
    *Head = newnode;
    
}

void insert_end(Node *Head,Node *newnode){
    Node *ptr = Head;
    while (ptr->next != Head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = Head;
    
}
//delete funcs
void delete_head(Node **head){
    Node *ptr = *head;
    while (ptr->next != *head)
    {
        ptr = ptr->next;
    }
    ptr->next = (*head)->next;
    free((*head));
    *head = ptr->next;
    
}

void delete_end(Node *head){
    Node *ptr = head;
    Node *preptr = NULL;
    while (ptr->next != head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = head;
    free(ptr);
    
}
//Disply function
void printcdls(Node *Head){
    Node *ptr = Head;
    while ( ptr->next != Head )
    {
        printf("%d-",ptr->value);
        ptr = ptr->next;
    }
    printf("%d",ptr->value);
    printf("\n");
}

int main(){
    Node * Head = (Node *)malloc(sizeof(Node));
    Head->value = 1;
    Head->next = NULL;
    IniaterCDLS(Head);
    Node * Test = (Node *)malloc(sizeof(Node));
    Test->value = 99;
    Test->next = NULL;
    insert_beg(&Head,Test);
    Node * Test2 = (Node *)malloc(sizeof(Node));
    Test2->value=  88;
    Test2->next = NULL;
    insert_end(Head,Test2);
    delete_head(&Head);
    delete_end(Head);
    printcdls(Head);
    return 0;
}