// Searching a key on a B-tree in C
// not workıng
#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

// Create a node
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

// Insert node
void insertNode(int val, int pos, struct BTreeNode *node,
        struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct BTreeNode *node,
         struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// Set the value
int setValue(int val, int *pval,
           struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

// Insert the value
void insert(int val) {
  int flag, i;
  struct BTreeNode *child;

  flag = setValue(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

// Traverse then nodes
/*
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      printf("%d ", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}
*/



typedef struct BTreeNode tree;

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














int main() {
  int val, ch;

   while (1)
    {
        scanf("%d",val);
        if (val == -1)
        {
            break;
        }else{
            insert(val);
            
        }
        
    }
  traversal(root);

  printf("\n");
}