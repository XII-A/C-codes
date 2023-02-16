#include <stdio.h>
#include <stdlib.h>
//  NOT WORKING
struct tree
{
    int grade;
    int student_id;
    struct tree * rightnode;
    struct tree * leftnode;
};
typedef struct tree tree;

void insert_search_Btree(tree **mytree,int grade,int id){
    tree * node = (tree *)malloc(sizeof(tree));
    node->grade = grade;
    node->student_id = id;
    node->rightnode = NULL;
    node->leftnode = NULL;
    
    if ((*mytree) == NULL)
    {
        (*mytree) = node; 
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





/*void space(int numtab){
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
    printf("(%d %d)\n",root->student_id,root->grade);
    space(lvl);
    printf("Left\n");
    printtree(root->leftnode,lvl+1);
    space(lvl);
    printf("Right\n");
    printtree(root->rightnode,lvl+1);
    space(lvl);
    printf("---<Done>---\n");


    
}*/
void lvlorder_right(tree * mytree , int lvl);

void lvlorder_left(tree * mytree , int lvl){
    if (mytree == NULL)
    {
        return;
    }
    if (mytree->leftnode != NULL)
    {
        printf("%d %d (%d L) ",mytree->leftnode->student_id,mytree->leftnode->grade,mytree->grade);
    }
    if (mytree->rightnode != NULL)
    {
        printf("%d %d (%d R)",mytree->rightnode->student_id,mytree->rightnode->grade,mytree->grade);
        printf("\n");  
        lvlorder_right(mytree->rightnode,lvl + 1);  
    }
    if(mytree->rightnode == NULL)
    {
        return;
    }
    
}

void lvlorder_right(tree * mytree , int lvl , tree * prev_left){
    if (lvl == 0)
    {
        printf("%d %d\n",mytree->student_id,mytree->grade);
        if (mytree->leftnode != NULL)
        {
            printf("%d %d (%d L) ",mytree->leftnode->student_id,mytree->leftnode->grade,mytree->grade);
        }
        if (mytree->rightnode != NULL && mytree->leftnode != NULL)
        {
            printf("%d %d (%d R)",mytree->rightnode->student_id,mytree->rightnode->grade,mytree->grade);
            printf("\n");  
            lvlorder_left(mytree->leftnode,lvl + 1);  
        }else if (mytree->rightnode != NULL)
        {
            printf("%d %d (%d R)",mytree->rightnode->student_id,mytree->rightnode->grade,mytree->grade);
            printf("\n");
        }
        
        
    }else if (mytree == NULL)
    {
        return;
    }
    else{
       if (mytree->leftnode != NULL)
        {
            printf("%d %d (%d L) ",mytree->leftnode->student_id,mytree->leftnode->grade,mytree->grade);
        }
        if (mytree->rightnode != NULL && mytree->leftnode != NULL)
        {
            printf("%d %d (%d R)",mytree->rightnode->student_id,mytree->rightnode->grade,mytree->grade);
            printf("\n");  
            lvlorder_left(mytree->leftnode,lvl + 1);  
        }else if (mytree->rightnode != NULL)
        {
            printf("%d %d (%d R)",mytree->rightnode->student_id,mytree->rightnode->grade,mytree->grade);
            printf("\n");
            return;
        }
    }
    
}









int main(){
    tree * mytree = NULL;
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
    printf("\n--------------------\n");
    lvlorder_right(mytree,0);
    
}