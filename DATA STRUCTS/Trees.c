#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
struct tree
{
    int value;
    struct tree * rightnode;
    struct tree * leftnode;
};
typedef struct tree tree;

void insert_search_Btree(tree **mytree,int value){
    tree * node = (tree *)malloc(sizeof(tree));
    node->value = value;
    node->rightnode = NULL;
    node->leftnode = NULL;
    
    if ((*mytree) == NULL)
    {
        (*mytree) = node; 
    }else{
        if ((*mytree)->value < value)
        {
            insert_search_Btree(&((*mytree)->rightnode),value);
        }else if ((*mytree)->value > value)
        {
            insert_search_Btree(&((*mytree)->leftnode),value);
        }
        
        
        
    }
    
}

//yt vid
tree * createnode(int value){
    tree *result = (tree *)malloc(sizeof(tree));
    result->leftnode = NULL;
    result->rightnode = NULL;
    result->value = value;
    return result;

}

void space(int numtab){
    int i;
    for ( i = 0; i < numtab; i++)
    {
        printf("\t");
    }
    

}

void printtree(tree *root , int lvl){
    if (root == NULL)
    {
        space(lvl);
        printf("----<empty>-----\n");
        return;
    }
    //preorder
    space(lvl);
    printf("(%d)\n",root->value);
    space(lvl);
    printf("Left\n");
    printtree(root->leftnode,lvl+1);
    space(lvl);
    printf("Right\n");
    printtree(root->rightnode,lvl+1);
    space(lvl);
    printf("---<Done>---\n");


    
}

void preorder_tree(tree * mytree){
    if (mytree != NULL)
    {
        printf("%d-",mytree->value);
    }else{
        return;
    }
    
    preorder_tree(mytree->leftnode);
    preorder_tree(mytree->rightnode);
}

void postorder_tree(tree * mytree){
   
    if (mytree == NULL)
    {
        return;
    }
    
   
    postorder_tree(mytree->leftnode);
    postorder_tree(mytree->rightnode);
    
    if (mytree != NULL)
    {
        printf("%d-",mytree->value);
    }
    
}

void inorder_tree(tree * mytree){
    if (mytree == NULL)
    {
        return;
    }
    inorder_tree(mytree->leftnode);
    printf("%d-",mytree->value);
    inorder_tree(mytree->rightnode);

    
}





int main(){
    int i;
    tree *mytree = NULL;
    for ( i = 3; i < 5; i++)
    {
        if (i==3)
        {
            insert_search_Btree(&mytree,i);
            insert_search_Btree(&mytree,i+1);
            insert_search_Btree(&mytree,i-1);

        }else
        {
            insert_search_Btree(&mytree,i+1);
            insert_search_Btree(&mytree,i-4);
        }
        
        
    }
    //yt vid
    tree *n1 = createnode(10);
    tree *n2 = createnode(11);
    tree *n3 = createnode(12);
    tree *n4 = createnode(13);
    tree *n5 = createnode(14);
    n1->leftnode = n2;
    n1->rightnode = n3;
    n3->leftnode = n4;
    n3->rightnode = n5;
    preorder_tree(n1);
    printf("\n");
    postorder_tree(n1);
    printf("\n");
    inorder_tree(n1);

    
}
