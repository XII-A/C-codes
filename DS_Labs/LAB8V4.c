#include <stdio.h>
#include <stdlib.h>
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

tree * tree_root = NULL;
tree * temp = NULL;

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
    node->leftnode = NULL;
    return node;
}
void rightrotate(tree* newnode)
{
	tree * new_root = newnode->leftnode;
	newnode->leftnode = new_root->rightnode;
	if (newnode->leftnode)
		newnode->leftnode->parent = newnode;
	new_root->parent = newnode->parent;
	if (!newnode->parent)
		tree_root = new_root;
	else if (newnode == newnode->parent->leftnode)
		newnode->parent->leftnode = new_root;
	else
		newnode->parent->rightnode = new_root;
	new_root->rightnode = newnode;
	newnode->parent = new_root;
}

// Function performing left rotation
// of the passed node
void leftrotate(tree * newnode)
{
	tree* new_root = newnode->rightnode;
	newnode->rightnode = new_root->leftnode;
	if (newnode->rightnode)
		newnode->rightnode->parent = newnode;
	new_root->parent = newnode->parent;
	if (!newnode->parent)
		tree_root = new_root;
	else if (newnode == newnode->parent->leftnode)
		newnode->parent->leftnode = new_root;
	else
		newnode->parent->rightnode = new_root;
	new_root->leftnode = newnode;
	newnode->parent = new_root;
}

void fixup(tree * ROOTF, tree* newnode)
{
	tree* parent_pt = NULL;
	tree* grand_parent_pt = NULL;

	while ((newnode != ROOTF) && (newnode->color != 'B')
		&& (newnode->parent->color == 'R'))
	{
		parent_pt = newnode->parent;
		grand_parent_pt = newnode->parent->parent;

		/* Case : A
			Parent of pt is left child
			of Grand-parent of
		pt */
		if (parent_pt == grand_parent_pt->leftnode)
		{

			tree* uncle_pt = grand_parent_pt->rightnode;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == 'R')
			{
				grand_parent_pt->color = 'R';
				parent_pt->color = 'B';
				uncle_pt->color = 'B';
				newnode = grand_parent_pt;
			}

			else {

				/* Case : 2
					pt is right child of its parent
					Left-rotation required */
				if (newnode == parent_pt->rightnode) {
					leftrotate(parent_pt);
					newnode = parent_pt;
					parent_pt = newnode->parent;
				}

				/* Case : 3
					pt is left child of its parent
					Right-rotation required */
				rightrotate(grand_parent_pt);
				char new_color = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = new_color;
				newnode = parent_pt;
			}
		}

		/* Case : B
			Parent of pt is right
			child of Grand-parent of
		pt */
		else {
			tree* uncle_pt = grand_parent_pt->leftnode;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == 'R'))
			{
				grand_parent_pt->color = 'R';
				parent_pt->color = 'B';
				uncle_pt->color = 'B';
				newnode = grand_parent_pt;
			}
			else {
				/* Case : 2
				pt is left child of its parent
				Right-rotation required */
				if (newnode == parent_pt->leftnode) {
					rightrotate(parent_pt);
					newnode = parent_pt;
					parent_pt = newnode->parent;
				}

				/* Case : 3
					pt is right child of its parent
					Left-rotation required */
				leftrotate(grand_parent_pt);
				char new_color = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = new_color;
				newnode = parent_pt;
			}
		}
	}

	tree_root->color = 'B';
}



tree * insert_search_Btree(tree *mytree,int value,tree *parent){
    if( mytree == NULL)
    {
        temp = new_node(value,parent,'R');
        return temp;
    }else{
        if (value < mytree->value )
        {
            mytree->leftnode = insert_search_Btree(mytree->rightnode,value,mytree);
        }else if (value > mytree->value)
        {
            mytree->rightnode = insert_search_Btree(mytree->leftnode,value,mytree);

        }else{
            return mytree;
        }
        
           
    }
    

}




int main(){
  
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
            tree_root = insert_search_Btree(tree_root,value,NULL);
            fixup(tree_root,temp);
            //insert_RBT(&mytree,value,NULL);
            
        }
        
    }
    inorder_tree(tree_root);
    /*insert_queue(&Front,&Rear,mytree,'H',0);
    printf("\n");
    levelorder_tree(mytree,&Front,&Rear);*/

    return 0;
}