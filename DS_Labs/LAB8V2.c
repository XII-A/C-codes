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


tree * insert_RBT(tree **mytree , int value , tree **parent){
    printf("workin on %d\n",(*mytree)->value);
    //case1
    if ((*mytree)->parent == NULL)
    {
        (*mytree)->color = 'B';
        printf("case 1\n");
        return *mytree;
    }
    //case 2
    if ((*mytree)->parent->color == 'B')
    {   
        printf("case 2\n");
        return *mytree;
        
    }
    if ((*mytree)->color == 'R')
    {
        //getting uncle and grandpa
        //printf("preparing for case 3 and 4\n");
        tree ** uncle = NULL;
        tree ** grandpa = NULL;
        char uncle_color = '0';
        if ((*mytree)->parent->parent != NULL)
        {
            grandpa = &((*mytree)->parent->parent);
            printf("grandpa initated\n");
        }
        
        if ((*grandpa)->leftnode == (*mytree)->parent)
        {
            uncle = &((*grandpa)->rightnode);
            printf("uncle init 1\n");
        }else{
            uncle = &((*grandpa)->leftnode);
            printf("uncle init 2\n");

        }
        if ((*uncle) == NULL)
        {
            uncle_color = 'B';
            printf("uncle color 1\n");

        }else{
            uncle_color = (*uncle)->color;
            printf("uncle color 2\n");

        }
        
        //case 3
        if ((*mytree)->parent->color == 'R' && uncle_color == 'R')
        {
            printf("case 3\n");
            (*mytree)->parent->color = 'B';
            (*uncle)->color = 'B';
            uncle_color = 'B';
            (*grandpa)->color = 'R';
            printf("exit case 3\n");
            return *mytree;

        }
        //case 4
        if ((*mytree)->parent->color == 'R' && uncle_color == 'B')
        {
            printf("case 4\n");
            if ((*mytree)->parent->rightnode == (*mytree) && (*mytree)->parent == (*grandpa)->leftnode)
            {
                
                printf("case 4 1\n");
                tree * new_right = (*mytree)->leftnode;
                tree * new_root = (*mytree);
                tree * new_left = (*mytree)->parent;
                tree * new_parent = (*mytree)->parent->parent;
                printf("step 1-");
                (*mytree)->leftnode = new_left;
                (*mytree)->parent = new_parent;
                printf("step 2-");
                (*mytree)->leftnode->rightnode = new_right;
                printf("step 3-");
                (*parent)->parent = (*grandpa)->leftnode;
                printf("step 4-");
                return *mytree;
                
                /*(*grandpa)->leftnode = (*mytree);
                printf("step 2-");
                
                (*mytree)->leftnode = (*mytree)->parent;
                printf("step 3-");
                
                (*mytree)->parent->rightnode = new_right;
                printf("step 4-");
                
                (*parent)->parent = (*mytree);
                (*mytree)->parent = *grandpa;
                printf("step 5-");*/
                
                

                
            }
            
        }
        
        
        
        
        

    }
    
    
    







}


int number_nodes = 0;
tree * insert_search_Btree(tree **mytree,int value,tree *parent){
    
    if ((*mytree) == NULL)
    {
        (*mytree) = new_node(value,parent,'R');
        
        number_nodes++;
    }else{
        if (value > (*mytree)->value)
        {
            (*mytree)->rightnode = insert_search_Btree(&((*mytree)->rightnode),value,(*mytree));
            insert_RBT(&((*mytree)->rightnode),value,&parent);
            return (*mytree)->rightnode;
            
        }else if (value < (*mytree)->value)
        {
            (*mytree)->leftnode = insert_search_Btree(&((*mytree)->leftnode),value,(*mytree));
            insert_RBT(&((*mytree)->leftnode),value,&parent);
            return (*mytree)->leftnode;

        }
        
        
        
    }
    insert_RBT(mytree,value,&parent);
    return (*mytree);

    
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
            insert_search_Btree(&mytree,value,NULL);
            //insert_RBT(&mytree,value,NULL);
            
        }
        
    }
    inorder_tree(mytree);
    insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);

    return 0;
}