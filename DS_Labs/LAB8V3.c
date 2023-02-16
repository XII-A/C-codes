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



void inorder_tree(tree * mytree){
    if (mytree == NULL)
    {
        return;
    }
    inorder_tree(mytree->leftnode);
    printf("%d %c\n",mytree->value,mytree->color);
    inorder_tree(mytree->rightnode);

    
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

tree * check_rbt(tree **mytree){
    if ((*mytree)->parent == NULL)
    {
        (*mytree)->color = 'B';
        return *mytree;
    }
    else if ((*mytree)->parent->color == 'B')
    {
        return *mytree;
    }
    else{
        if ((*mytree)->color == 'R')
        {
            tree ** uncle = NULL;
            tree ** grandpa = NULL;
            char uncle_color = '0';
            if ((*mytree)->parent->parent != NULL)
            {
                grandpa = &((*mytree)->parent->parent);
                //printf("grandpa initated\n");
            }
            
            if ((*grandpa)->leftnode == (*mytree)->parent)
            {
                uncle = &((*grandpa)->rightnode);
                //printf("uncle init 1\n");
            }else{
                uncle = &((*grandpa)->leftnode);
                //printf("uncle init 2\n");

            }
            if ((*uncle) == NULL)
            {
                uncle_color = 'B';
                //printf("uncle color 1\n");

            }else{
                uncle_color = (*uncle)->color;
                //printf("uncle color 2\n");

            }
            
            //case 3
            if ((*mytree)->parent->color == 'R' && uncle_color == 'R')
            {
                //printf("case 3\n");
                (*mytree)->parent->color = 'B';
                (*uncle)->color = 'B';
                uncle_color = 'B';
                (*grandpa)->color = 'R';
                //printf("exit case 3\n");
                return *mytree;
            }
        }
        
    }
    
}






tree * insert_search_Btree(tree *mytree,int value,tree *parent){
    
    if( mytree == NULL)
    {
        return new_node(value,parent,'R');
    }else{
        if (value < mytree->value )
        {
            mytree->leftnode = insert_search_Btree(mytree->rightnode,value,mytree);
            //return check_rbt(&(mytree->leftnode));
        }else if (value > mytree->value)
        {
            mytree->rightnode = insert_search_Btree(mytree->leftnode,value,mytree);
            //return check_rbt(&(mytree->rightnode));

        }else{
            //return mytree;
        }
        
           
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
            mytree = insert_search_Btree(mytree,value,NULL);
            //insert_RBT(&mytree,value,NULL);
            
        }
        
    }
    inorder_tree(mytree);
    /*insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);*/

    return 0;
}