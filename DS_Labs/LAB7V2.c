#include <stdio.h>
#include <stdlib.h>


struct tree
{
    int value;
    int balance_factor;
    struct tree *rightnode;
    struct tree *leftnode;
};
typedef struct tree tree;
struct queue
{
    int value;
    char side;
    int balance_factor;
    int prev_value;
    tree *right_node;
    tree *left_node;
    struct queue * next_node;
};
typedef struct queue queue;
void insert_queue(queue **Front,queue **Rear,tree * mytree,char side,int prev_value){
    queue * newnode = (queue *)malloc(sizeof(queue));
    newnode->value = mytree->value;
    newnode->prev_value = prev_value;
    newnode->balance_factor = mytree->balance_factor;
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

tree *new_node(int value){
    tree * node = (tree *)malloc(sizeof(tree));
    node->value = value;
    node->balance_factor = 0;
    node->rightnode = NULL;
    node->leftnode = NULL;
    return node;
}


int left_height;
int right_height;
int height(tree * mytree){
    if (mytree == NULL)
    {
        return 0;     
    }else{
        left_height = height(mytree->leftnode);
        right_height = height(mytree->rightnode);
        if (left_height > right_height)
        {
            left_height = left_height + 1;
            return left_height;
        }else{
            right_height = right_height + 1;
            return right_height;
        }
        
    }
    

}


tree * LL_rotate(tree * mytree){
    tree * new_left = mytree->leftnode->rightnode;
    tree * new_root = mytree->leftnode;
    new_root->rightnode = mytree;
    mytree->leftnode = new_left;
    mytree->balance_factor = (height(mytree->leftnode)) - (height(mytree->rightnode));
    left_height = 0;
    right_height = 0;
    new_root->balance_factor = (height(new_root->leftnode)) - (height(new_root->rightnode));
    left_height = 0;
    right_height = 0;
    return new_root;
}

tree * RR_rotate(tree * mytree){
    tree * new_root = mytree->rightnode;
    tree * new_right = mytree->rightnode->leftnode;
    new_root->leftnode = mytree;
    mytree->rightnode = new_right;
    mytree->balance_factor = (height(mytree->leftnode)) - (height(mytree->rightnode));
    left_height = 0;
    right_height = 0;
    new_root->balance_factor = (height(new_root->leftnode)) - (height(new_root->rightnode));
    left_height = 0;
    right_height = 0;
    return new_root;
}




tree * insert_AVL(tree *mytree,int value){
    //inserting
    if( mytree == NULL)
    {
        return new_node(value);
    }else{
        if (value < mytree->value )
        {
            mytree->leftnode = insert_AVL(mytree->leftnode,value);
        }else if (value > mytree->value)
        {
            mytree->rightnode = insert_AVL(mytree->rightnode,value);
        }else{
            return mytree;
        }
        
           
    }
    mytree->balance_factor = (height(mytree->leftnode)) - (height(mytree->rightnode));
    left_height = 0;
    right_height = 0;
    
    //LL case
    if (mytree->balance_factor >= 2 && mytree->leftnode->value > value)
    {
        return LL_rotate(mytree);
    }
    //RR case
    if (mytree->balance_factor <= -2 && mytree->rightnode->value < value)
    {
        return RR_rotate(mytree);
    }
    //LR case
    if (mytree->balance_factor >= 2 && mytree->leftnode->value < value)
    {
        mytree->leftnode = RR_rotate(mytree->leftnode);
        return LL_rotate(mytree);
    }
    //RL case
    if (mytree->balance_factor <= -2 && mytree->rightnode->value > value)
    {
        mytree->rightnode = LL_rotate(mytree->rightnode);
        return RR_rotate(mytree);
    }
    //Unchanged 
    return mytree;

}

void inorder_tree(tree * mytree){
    if (mytree == NULL)
    {
        return;
    }
    inorder_tree(mytree->leftnode);
    printf("%d\n",mytree->value);
    inorder_tree(mytree->rightnode);

    
}

int number_nodes = 0;
void levelorder_tree(tree * mytree,queue **Front,queue **Rear){
    int current_rear_value;
    int changed = 0;
    int nodes_printed = 0;
    while (1)
    {
        if ((*Front) == NULL)
        {
            break;
        }else
        {
            if ((*Front)->side == 'H')
            {
                printf("%d (%d B)",(*Front)->value,(*Front)->balance_factor);
                printf("\n");
                nodes_printed++;
                if (mytree->leftnode != NULL)
                {
                    insert_queue(Front,Rear,mytree->leftnode,'L',mytree->value);
                }
                if (mytree->rightnode != NULL)
                {
                    insert_queue(Front,Rear,mytree->rightnode,'R',mytree->value);
                    
                }
                current_rear_value = (*Rear)->value;
                delete_queue(Front);
                
                continue;
            }else
            {
                if ((*Front)->side == 'L')
                {
                    printf("%d (%d %c) (%d B)",(*Front)->value,(*Front)->prev_value,(*Front)->side,(*Front)->balance_factor);
                    nodes_printed++;
                    if ((*Front)->left_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->left_node,'L',(*Front)->value);
                    }
                    if ((*Front)->right_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->right_node,'R',(*Front)->value);
                        
                    }
                    if (current_rear_value == (*Front)->value)
                    {
                        current_rear_value = (*Rear)->value;
                        if (nodes_printed != number_nodes)
                        {
                            printf("\n");
                        }
                        
                    }else{
                        printf(" ");
                    }
                    changed = 0;
                    delete_queue(Front);

                }else{
                    printf("%d (%d %c) (%d B)",(*Front)->value,(*Front)->prev_value,(*Front)->side,(*Front)->balance_factor);
                    nodes_printed++;
                    if ((*Front)->left_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->left_node,'L',(*Front)->value);
                    }
                    if ((*Front)->right_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->right_node,'R',(*Front)->value);
                        
                    }
                    if (current_rear_value == (*Front)->value)
                    {
                        current_rear_value = (*Rear)->value;
                        if (nodes_printed != number_nodes)
                        {
                            printf("\n");
                        }
                    }else{
                        printf(" ");
                    }
                    delete_queue(Front);
                }    
                
            }
            
            
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
            mytree = insert_AVL(mytree,value);
            
        }
        
    }
    inorder_tree(mytree);
    insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);
}