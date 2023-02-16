#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
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

tree * mytree = NULL;
struct tree *in_order_P(tree * root){
    while (root->rightnode != NULL)
    {
        root = root->rightnode;
    }
    return root;
}

int number_nodes = 0;
tree * search_tree(tree *mytree , int val){
    if (mytree!= NULL)
    {
        if (mytree->grade == val)
        {
            printf("its in there");
            return mytree;
        }else{
            if (val < mytree->grade)
            {
                search_tree(mytree->leftnode,val);
            }else
            {
                search_tree(mytree->rightnode,val);
            }
            
            
        }
        
    }else
    {
        printf("its not in here");
    }
    
    
    
}
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


tree * search_tree_D(tree * mytree , int val ,tree **parent){
    if (mytree!= NULL)
    {
        if (mytree->grade == val)
        {
            return mytree;
        }else{
            if (val < mytree->grade)
            {
                (*parent) = mytree;
                search_tree_D(mytree->leftnode,val,parent);
            }else
            {
                (*parent) = mytree;
                search_tree_D(mytree->rightnode,val,parent);
            }
            
            
        }
        
    }else
    {
        return NULL;
    }
}

tree * in_order_S(tree *mytree){
    while (mytree->leftnode != NULL)
    {
        mytree = mytree->leftnode;
    }
    return mytree;
    
    
}


/*void Deleting_nodes(tree *mytree,int val){
    tree *node_parent = (tree *)malloc(sizeof(tree));
    tree *node = (tree *)malloc(sizeof(tree));
    node = search_tree_D(mytree,val,&node_parent);
    
    if (node == NULL)
    {
        printf("The node you want to delete isnt in here");
    }
    else if (node->leftnode == NULL && node->rightnode == NULL)
    {
        if (node_parent->leftnode->grade == node->grade)
        {
            node_parent->leftnode = NULL;
        }else{
            node_parent->rightnode = NULL;
        }
        free(node);
        printf("\ncase 1:node deleted\n");
    }
    else if (node->leftnode != NULL && node->rightnode == NULL)
    {
        if (node_parent->leftnode->grade == node->grade)
        {
            node_parent->leftnode = node->leftnode;
            free(node);
            printf("\ncase 2:node deleted\n");
        }else{
            node_parent->rightnode = node->leftnode;
            free(node);
            printf("\ncase 2:node deleted\n");
        }
        
    }
    else if (node->leftnode == NULL && node->rightnode != NULL)
    {
        if (node_parent->leftnode->grade == node->grade)
        {
            node_parent->leftnode = node->rightnode;
            free(node);
            printf("\ncase 2:node deleted\n");
        }else{
            node_parent->rightnode = node->rightnode;
            free(node);
            printf("\ncase 2:node deleted\n");
        }
    }
    else if (node->leftnode != NULL && node->rightnode != NULL)
    {
        
        tree * in_orderSucc = (tree *)malloc(sizeof(tree)); 
        in_orderSucc = in_order_S(node->rightnode);
        int grade = in_orderSucc->grade;
        Deleting_nodes(mytree,grade);
        node->grade = grade;
        printf("\ncase 3:node deleted\n");

    }
    
    
     
}*/

tree * delete_node(tree *mytree , int val){
    if (mytree == NULL)
    {
        printf("THE TREE IS EMPTY");
    }
    else if (val < mytree->grade)
    {
        mytree->leftnode = delete_node(mytree->leftnode,val);
    }
    else if (val > mytree->grade)
    {
        mytree->rightnode = delete_node(mytree->rightnode,val);
    }
    
    else if (mytree->rightnode != NULL && mytree->leftnode != NULL )
    {
        tree * temp = NULL;
        temp = in_order_P(mytree->leftnode);
        mytree->grade = temp->grade;
        mytree->leftnode = delete_node(mytree->leftnode,temp->grade);
    }else{
        tree * temp = mytree;
        if (mytree->rightnode == NULL && mytree->leftnode == NULL)
        {
            mytree = NULL;
            return mytree;
        }else if (mytree->rightnode != NULL)
        {
            mytree = mytree->rightnode;
            return mytree;
        }else{
            mytree = mytree->rightnode;
            return mytree;
        }
        free(temp);
        
    }


}


void delete_tree(tree **mytree){
    if ((*mytree) != NULL)
    {
        delete_tree(&((*mytree)->leftnode));
        delete_tree(&((*mytree)->rightnode));
        free(*mytree);
    }
    
}








int main(){



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
    //inorder_tree(mytree);
    insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);
    printf("\n");
    //Deleting_nodes(mytree,65);
    //delete_node(mytree,65);
    delete_tree(&mytree);
    printf("\n");
    Front = NULL;
    Rear = NULL;
    insert_queue(&Front,&Rear,mytree,'H',0);
    levelorder_tree(mytree,&Front,&Rear);


}