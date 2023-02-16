#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next_node;
};
typedef struct Node Node;

static void function2(Node** head) {
 Node* r = NULL;
 Node* cur = *head;
 Node* n;
 while (cur!= NULL) {
 n = cur ->next_node;
 cur ->next_node = r;
 r = cur;
 cur = n;
 }
 *head = r;
}

void function1(Node ** a, Node** b) {
    Node* cur;
    if (*a == NULL) {
        *a = *b;
    }
    else {
        cur = *a;
        while (cur ->next_node != NULL) {
            cur = cur ->next_node;
        }
        cur ->next_node = *b;
        }
    *b=NULL;
}



void function3(Node* head) {
 Node* cur = head;
 if (cur == NULL) return;
 while(cur ->next_node!=NULL) {
 if (cur ->value == cur ->next_node->value) {
 Node* nextNext = cur ->next_node->next_node;
 free(cur ->next_node);
 cur ->next_node = nextNext;
 }
 else {
 cur = cur ->next_node;
 }
 }
}



Node * Create_Node(int value){
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next_node = NULL;
    return new_node;
}


void Insert_End(Node  *Head,Node  *inserted){
    Node *ptr = Head;

    while (ptr->next_node != NULL)
    {
        ptr = ptr->next_node;
    }
    ptr->next_node = inserted;

    
}




void LS_print(Node  *head){
    Node *ptr = head;
    int num_of_nodes = 0;
    while (ptr != NULL)
    {
        printf("%d-",ptr->value);
        num_of_nodes++;   
        ptr = ptr->next_node;

    }
    printf("\nnum of nodes: %d",num_of_nodes);
}

int search_Nodes(Node* Head,int num){
    Node *ptr = Head;

    while (ptr != NULL)
    {
       if (ptr->value == num)
       {
           printf("Number was found");
           return 1;
       }
       else
       {
           ptr = ptr->next_node;
           continue;
       }
       
        

    }

    printf("Number wasnt found");
    return 0;
}

Node *Insert_Head(Node *Head,Node * Inserted){
    Inserted->next_node = Head;
    return Inserted;
}


Node *Insert_After(Node *After_Node,Node *to_Insert){
    to_Insert->next_node = After_Node->next_node;
    After_Node->next_node = to_Insert;
}

Node *Before_Before(Node* Head,int val_Before){
    Node *ptr = Head;
    Node *tmp;

    while (ptr != NULL)
    {
       if (ptr->value == val_Before)
       {
           printf("Number was found");
           return tmp;
       }
       else
       {
           tmp = ptr;
           ptr = ptr->next_node;
           continue;
       }
       
        

    }

    printf("Number wasnt found");
    return NULL;
}

Node *Insert_Beforev2(Node *Head,int val_Before,Node * INSERTED){
    Node *Before_B = Before_Before(Head,val_Before);
    INSERTED->next_node = Before_B->next_node;
    Before_B->next_node = INSERTED;
    return INSERTED;

}


void Insert_Before(Node *Head,int value,Node * Inserted){
    Node * ptr = Head;
    Node *PREptr = NULL;
    while (ptr->value != value)
    {
        PREptr = ptr;
        ptr = ptr->next_node;
    }
    PREptr->next_node = Inserted;
    Inserted->next_node = ptr;
    
}

void Delete_Head(Node **head){
    Node * ptr = *head;
    (*head) = (*head)->next_node;
    free(ptr);

}

void Delete_tail(Node *head){
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr->next_node != NULL)
    {
        prev = ptr;
        ptr = ptr->next_node;
    }
    prev->next_node = NULL;
    free(ptr);
    
}

void Delete_after(Node *head, int val){
    Node *ptr = head;
    while (ptr->value != val)
    {
        ptr = ptr->next_node;
    }
    Node *temp = ptr->next_node;
    ptr->next_node = temp->next_node;
    free(temp);
}   




int main(){
    
    int i;
    
    Node *temp;

    Node *Head = (Node *)malloc(sizeof(Node));
    Node *Ay = (Node *)malloc(sizeof(Node));
    Head->value = 12;
    Head->next_node = NULL;

    for ( i = 0; i < 10; i++)
    {

        temp = Create_Node(i);
        Insert_End(Head,temp);
        temp = Create_Node(i);
        Insert_End(Head,temp);
    }
    
    //LS_print(Head);
    //search_Nodes(Head,8);
    Ay->value = 48;
    Ay->next_node = NULL;
    //function1(&Head,&Ay);
    //function2(&Head);
    //Head = Insert_Head(Head,Ay);
    //LS_print(Head);
    //Insert_After(Head,Ay);
    function3(Head);
    //Insert_Before(Head,5,Ay);
    //Delete_Head(&Head);
    //Delete_tail(Head);
    
    LS_print(Head);
    return 0;
}