
struct tree
{
    /* data */
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