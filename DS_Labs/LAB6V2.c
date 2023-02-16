#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int grade;
    int student_id;
    struct tree * rightnode;
    struct tree * leftnode;
};

typedef struct tree tree;

struct queue
{
    int grade;
    int student_id;
    char side;
    int prev_grade;
    tree *right_node;
    tree *left_node;
    struct queue * next_node;
};

typedef struct queue queue;

int number_nodes = 0;

void insert_queue(queue **Front,queue **Rear,tree * mytree,char side,int prev_grade){
    queue * newnode = (queue *)malloc(sizeof(queue));
    newnode->grade = mytree->grade;
    newnode->prev_grade = prev_grade;
    newnode->student_id = mytree->student_id;
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



void insert_search_Btree(tree **mytree,int grade,int id){
    tree * node = (tree *)malloc(sizeof(tree));
    node->grade = grade;
    node->student_id = id;
    node->rightnode = NULL;
    node->leftnode = NULL;
    
    if ((*mytree) == NULL)
    {
        (*mytree) = node;
        number_nodes++;
    }else{
        if ((*mytree)->grade < grade)
        {
            insert_search_Btree(&((*mytree)->rightnode),grade,id);
        }else if ((*mytree)->grade > grade)
        {
            insert_search_Btree(&((*mytree)->leftnode),grade,id);
        }
        
        
        
    }
    
}

void inorder_tree(tree * mytree){
    if (mytree == NULL)
    {
        return;
    }
    inorder_tree(mytree->leftnode);
    printf("%d %d\n",mytree->student_id,mytree->grade);
    inorder_tree(mytree->rightnode);

    
}


void levelorder_tree(tree * mytree,queue **Front,queue **Rear){
    int current_rear_id;
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
                printf("%d %d",(*Front)->student_id,(*Front)->grade);
                printf("\n");
                nodes_printed++;
                if (mytree->leftnode != NULL)
                {
                    insert_queue(Front,Rear,mytree->leftnode,'L',mytree->grade);
                }
                if (mytree->rightnode != NULL)
                {
                    insert_queue(Front,Rear,mytree->rightnode,'R',mytree->grade);
                    
                }
                current_rear_id = (*Rear)->student_id;
                delete_queue(Front);
                
                continue;
            }else
            {
                if ((*Front)->side == 'L')
                {
                    printf("%d %d (%d %c)",(*Front)->student_id,(*Front)->grade,(*Front)->prev_grade,(*Front)->side);
                    nodes_printed++;
                    if ((*Front)->left_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->left_node,'L',(*Front)->grade);
                    }
                    if ((*Front)->right_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->right_node,'R',(*Front)->grade);
                        
                    }
                    if (current_rear_id == (*Front)->student_id)
                    {
                        current_rear_id = (*Rear)->student_id;
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
                    printf("%d %d (%d %c)",(*Front)->student_id,(*Front)->grade,(*Front)->prev_grade,(*Front)->side);
                    nodes_printed++;
                    if ((*Front)->left_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->left_node,'L',(*Front)->grade);
                    }
                    if ((*Front)->right_node != NULL)
                    {
                        insert_queue(Front,Rear,(*Front)->right_node,'R',(*Front)->grade);
                        
                    }
                    if (current_rear_id == (*Front)->student_id)
                    {
                        current_rear_id = (*Rear)->student_id;
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
    int id;
    int grade; 
    while (1)
    {
        scanf("%d",&id);
        if (id == -1)
        {
            break;
        }else{
            scanf("%d",&grade);
            insert_search_Btree(&mytree,grade,id);
        }
        
    }
    inorder_tree(mytree);
    insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);
    
    
}