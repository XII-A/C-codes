#include <stdio.h>
#include <stdlib.h>
/*
struct Linked_Lists
{
    int value;
    struct Linked_Lists *next_Node;
};

struct Linked_Lists node_array[5];

void Node_Creator(){
    int i;
    for ( i = 0; i < 5; i++)
    {
        node_array[i].value = i;
        node_array[i].next_Node = &node_array[i+1]; 
    }
    
}


int main()
{
    Node_Creator();
    for (int i = 0; i < 5; i++)
    {
        printf("node number: %d\nvalue = %d\n",i,node_array[i].value);
    }
    
    
    return 0;
  
}
*///how I implemented Linked lists



struct node  //the node struct
{
    int value;
    struct node * next;
};

typedef struct node node_t; //to not have to use struct node everytime we wanna create a new node

void printlist(node_t *head){ //to print the nodes
    node_t *i = head;
    while (i!=NULL)
    {
        printf("%d-",i->value);
        i = i->next;
        
    }
    printf("\n");
}

node_t * create_node(int value){ //to create the node
    node_t * node = malloc(sizeof(node_t)) ;
    
    node->value = value;
    node->next = NULL;
    return node;


}

node_t * insert_at_head(node_t * head,node_t * inserted_node){
    inserted_node->next = head; //makes the new node point at the previous node 
    return inserted_node; //then returning it to head to make it the new head node

}

node_t * find_node(node_t *head,int value){
    node_t *face = head;
    while (face->next!=NULL)
    {
        if (face->value == value)
        {
            printf("was found\n");
            return face;
        }
        else{
            face = face->next;
        }
        
    }
    
}


void insert_node_after_node(node_t *uw_after,node_t * inserted_node){ //uw = u want after

    inserted_node->next = uw_after->next;
    uw_after->next = inserted_node;
    
}

int main(){
    /*node_t n1,n2,n3;
    node_t *head;

    //giving value to the nodes
    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    //linking the nodes
    head = &n1;
    n3.next = &n2;
    n2.next = NULL;
    n1.next = &n3;//so we know when to stop
    printlist(head);*/

    /*node_t * n1 = create_node(45);
    node_t * n2 = create_node(8);
    n1->next = n2;
    printlist(n1);*/
    int i;
    node_t * head = NULL;
    node_t * temp;

    for ( i = 0; i < 5; i++)
    {
        temp = create_node(i); //creats a node
        /*temp->next = head;//makes the node point at the previous node
        head = temp;//makes that node the new head*/
        head = insert_at_head(head,temp);
    }
    printlist(head);
    //node_t * w_node = find_node(head,2);
    //printf("-%d-",w_node->value);
    insert_node_after_node(head,create_node(75));
    printlist(head);

    return 0;
}