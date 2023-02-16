#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node * next;
    struct Node * prev;
};
typedef struct Node Node;

//creating new nodes in a diff funcs to avoid loosing the head and loop connection issues
Node * create_node(int i){
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->value = i;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}




//Initating a circular doubly linked list
void IniaterCDLS(Node *Head){
    Node *ptr = Head;
    int i;
    for ( i = 2; i < 21; i++)
    {
     
      ptr->next = create_node(i);
      ptr->next->prev = ptr;
      ptr = ptr->next;
        
        
    }
    ptr->next = Head;
    Head->prev = ptr;
    
    
}
//Disply function
void printcdls(Node *Head){
    Node *ptr = Head;
    while ( Head->next != ptr )
    {
        printf("%d-",Head->value);
        Head = Head->next;
    }
    printf("%d-",Head->value);
    printf("\n");
}

//Inserting at the start
void insert_beg(Node **Head,Node *Inserted){
    Inserted->next = *Head;
    Inserted->prev = (*Head)->prev;
    (*Head)->prev->next = Inserted;
    (*Head)->prev = Inserted;
    *Head = Inserted;
}

//Inserting at the end
void insert_end(Node *Head,Node *Inserted){
    Inserted->next = Head;
    Inserted->prev = Head->prev;
    Head->prev->next = Inserted;
    Head->prev = Inserted;
    
}
//Inserting after
/*void insert_after(Node *Head,int val,Node *Inserted){
    Node *ptr = Head;
    Node *After = NULL;
    while (ptr->next != Head)
    {
        if (ptr->value == val )
        {
            After = ptr;
            break;
        }else{
            ptr = ptr->next;
        }
        
    }
    if (After == NULL)
    {
        if (ptr->value == val)
        {
            After = ptr;
        }else{
            printf("The node wasnt found\n");
            return;
        }
        
    }

    Inserted->next = After->next;
    After->next->prev = Inserted;
    After->next = Inserted;
    Inserted->prev = After;

    
    
}*/
void insert_after(Node * head,int val,Node *newnode){
    Node *ptr = head;
    while (ptr->value != val)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    newnode->prev = ptr;
    
}
void delete_head(Node **head){
    Node * ptr = *head;
    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;
    (*head) = (*head)->next;
    free(ptr);
}

void delete_end(Node *head){
    Node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    
    ptr->prev->next = head;
    head->prev = ptr->prev;
    free(ptr);

}

void delete_after(Node * head,int val){
    Node * ptr = head;
    while (ptr->value != val)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    
}
void delete_before(Node *head,int val){
    Node *ptr = head;
    while (ptr->value != val)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->prev;
    ptr->prev = temp->prev;
    temp->prev->next = ptr;
    free(temp);
}



int main(){

    Node * Head = (Node *)malloc(sizeof(Node));
    Head->value = 1;
    Head->next = NULL;
    Head->prev = NULL;
    IniaterCDLS(Head);
    Node * Test = (Node *)malloc(sizeof(Node));
    Test->value = 99;
    Test->next = NULL;
    Test->prev = NULL;
    insert_beg(&Head,Test);
    Node * Test2 = (Node *)malloc(sizeof(Node));
    Test2->value=  88;
    Test2->next = NULL;
    Test2->prev = NULL;
    insert_end(Head,Test2);
    Node * Test3 = (Node *)malloc(sizeof(Node));
    Test3->value=  77;
    Test3->next = NULL;
    Test3->prev = NULL;
    insert_after(Head,10,Test3);
    delete_head(&Head);
    delete_end(Head);
    //delete_after(Head,10);
    //delete_before(Head,77);
    printcdls(Head);
    
}