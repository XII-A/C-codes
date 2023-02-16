#include <stdio.h>
#include <stdlib.h>
// NOT WORKING
struct tree
{
    int value;
    char color;
    struct tree *rightnode;
    struct tree *leftnode;
    struct tree *parent;
};
typedef struct tree tree;

struct queue
{
    int value;
    char side;
    char color;
    int prev_value;
    tree *right_node;
    tree *left_node;
    struct queue * next_node;
};
typedef struct queue queue;

//needs editing
void insert_queue(queue **Front,queue **Rear,tree * mytree,char side,int prev_value){
    queue * newnode = (queue *)malloc(sizeof(queue));
    newnode->value = mytree->value;
    newnode->prev_value = prev_value;
    newnode->color = mytree->color;
    newnode->side = side;
    newnode->left_node = NULL;
    newnode->right_node = NULL;
    if (mytree->leftnode != NULL)
    {
        newnode->left_node = mytree->leftnode;
    }
    if (mytree->rightnode != NULL)
    {
        newnode->right_node = mytree->rightnode;
    }
    
    newnode->next_node = NULL;
    
    if ((*Front) == NULL)
    {
        (*Front) = newnode;
        (*Rear) = newnode;
    }else{
        (*Rear)->next_node = newnode;
        (*Rear) = newnode;
    }
    
}

void delete_queue(queue **Front){
    queue *ptr = (*Front);
    (*Front) = (*Front)->next_node;
    free(ptr);
}


tree *new_node(int value,tree * parent,char color){
    tree * node = (tree *)malloc(sizeof(tree));
    node->value = value;
    node->color = color;
    node->parent = parent;
    node->rightnode = NULL;
    //node->rightnode->color = 'B';
    node->leftnode = NULL;
    //node->leftnode->color = 'B';
    return node;
}

void inorder_tree(tree * mytree){
    if (mytree == NULL)
    {
        return;
    }
    inorder_tree(mytree->leftnode);
    printf("%d %c\n",mytree->value,mytree->color);
    inorder_tree(mytree->rightnode);

    
}


int is_root = 1;

tree * insert_RBT(tree *mytree , int value , tree * parent){
    if (mytree == NULL)
    {
        if (is_root == 1)
        {
            return new_node(value,parent,'B');
        }else{
            return new_node(value,parent,'R');
        }
        
    }else{
        if (value < mytree->value)
        {
            mytree->leftnode = insert_RBT(mytree->leftnode,value,mytree);
            is_root = 0;
        }else if (value > mytree->value)
        {
            mytree->rightnode = insert_RBT(mytree->rightnode,value,mytree);
            is_root = 0;
        }else{
            return mytree;
        }
        
        
    }

    //getting the uncle and grand parent and inserted child
    tree *grandpa = NULL;
    tree *uncle = NULL;
    tree *child;

    if (mytree->parent != NULL)
    {
        grandpa = mytree->parent;
        if (grandpa->leftnode == mytree)
        {
            uncle = grandpa->rightnode;
        }else{
            uncle = grandpa->leftnode;
        }
    }
    

    if (mytree->leftnode != NULL && mytree->leftnode->value == value)
    {
        child = mytree->leftnode;
    }else if (mytree->rightnode != NULL && mytree->rightnode->value == value)
    {
        child = mytree->rightnode;
    }else
    {
        child = NULL;//this means we already delt with the node that had a new child
    }
    
    
    
    



    //Case 1 already cared about in the code

    
    if (child != NULL,uncle != NULL)
    {
        //case 2 the new node parent is black
        if (mytree->color == 'B')
        {
            return mytree;
        }
        //case 3 both parent and uncle are red
        if (mytree->color == 'R', uncle->color == 'R')
        {
            mytree->color = 'B';
            uncle->color = 'B';
            grandpa->color = 'R';
            return mytree;
        }
    
    }else{
        return mytree;
    }
    
    
    


}












int main(){
    tree * mytree = NULL;
    queue * Front = NULL;
    queue * Rear = NULL;
    int value;
    while (1)
    {
        scanf("%d",&value);
        if (value == -1)
        {
            break;
        }else{
            mytree = insert_RBT(mytree,value,NULL);
            
        }
        
    }
    inorder_tree(mytree);
    /*insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);*/

    return 0;
}