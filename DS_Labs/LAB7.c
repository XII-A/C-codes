#include <stdio.h>
#include <stdlib.h>
// NOT WORKING

struct tree
{
    int value;
    int balance_factor;
    struct tree *rightnode;
    struct tree *leftnode;
};
typedef struct tree tree;


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
    new_root->balance_factor = (height(new_root->leftnode)) - (height(new_root->rightnode));
    return new_root;
}



int insert_AVL(tree **mytree,int value){
    
    //inserting
    if((*mytree) == NULL)
    {
        (*mytree) = new_node(value);
        return 1;
    }else{
        if (value < (*mytree)->value )
        {
            insert_search_Btree(&((*mytree)->leftnode),value);
        }else if (value > (*mytree)->value)
        {
            insert_search_Btree(&((*mytree)->rightnode),value);
        }
        
           
    }
    (*mytree)->balance_factor = (height((*mytree)->leftnode)) - (height((*mytree)->rightnode));
    left_height = 0;
    right_height = 0;
    
    //LL case
    if ((*mytree)->balance_factor >= 2 , (*mytree)->leftnode->value > value)
    {
        (*mytree) = LL_rotate(mytree);
    }
    






}
















int main(){
    tree * mytree = NULL;
    
    int value;
    while (1)
    {
        scanf("%d",&value);
        if (value == -1)
        {
            break;
        }else{
            insert_AVL(&mytree,value);
        }
        
    }
    
}