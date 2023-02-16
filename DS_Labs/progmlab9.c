// Searching a key on a B-tree in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 1

int data[100][5];
int height = 0;

struct BTreeNode
{
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

struct queue
{
  int value[MAX + 1];
  int count;
  struct BTreeNode *child[MAX + 1];
  struct queue *next_node;
};
typedef struct queue queue;

void insert_queue(queue **Front, queue **Rear, struct BTreeNode *mytree)
{
  queue *newnode = (queue *)malloc(sizeof(queue));
  if (mytree == NULL)
  {
    return;
  }
  // newnode->value = NULL;
  newnode->count = mytree->count;
  // newnode->child = NULL;
  if (mytree->val != NULL)
  {
    for (int i = 0; i < mytree->count; i++)
    {
      newnode->value[i + 1] = mytree->val[i + 1];
    }
  }
  if (mytree->link != NULL)
  {
    // newnode->child[[] = mytree->link[0];
    for (int i = 0; i <= mytree->count; i++)
    {

      newnode->child[i] = mytree->link[i];
    }
  }

  newnode->next_node = NULL;

  if ((*Front) == NULL)
  {
    (*Front) = newnode;
    (*Rear) = newnode;
  }
  else
  {
    (*Rear)->next_node = newnode;
    (*Rear) = newnode;
  }
}
void delete_queue(queue **Front)
{
  queue *ptr = (*Front);
  (*Front) = (*Front)->next_node;
  free(ptr);
}

int number_nodes = 0;

void levelorder_tree(struct BTreeNode *mytree, queue **Front, queue **Rear, int lvl)
{
  int current_rear_value;
  int changed = 0;
  int nodes_printed = 0;
  int prev_lvl_child = 0;
  int lvl_child = 0;

  while (1)
  {
    if ((*Front) == NULL)
    {
      break;
    }
    else
    {
      if (lvl == 0)
      {
        nodes_printed++;
        if ((*Front)->count != 0)
        {
          for (int i = 0; i < (*Front)->count; i++)
          {
            if (i + 1 == (*Front)->count)
            {
              printf("%d", (*Front)->value[i + 1]);
              break;
            }
            printf("%d-", (*Front)->value[i + 1]);
          }
        }
        for (int i = 0; i <= (*Front)->count; i++)
        {

          if ((*Front)->child[i + 1] == NULL)
          {
            break;
          }

          insert_queue(Front, Rear, root->link[i]);

          lvl_child++;
        }
        // printf("\nlvl child:%d\n",lvl_child);
        lvl++;

        // current_rear_value = (*Rear)->value;
        delete_queue(Front);

        continue;
      }
      else
      {
        if (prev_lvl_child == 0)
        {
          prev_lvl_child = lvl_child;
          lvl_child = 0;
          printf("\n");
        }
        else
        {
          printf(",");
        }
        // printf("going to the next child: 1\n");
        if ((*Front)->count != 0)
        {
          for (int i = 0; i < (*Front)->count; i++)
          {
            if (i + 1 == (*Front)->count)
            {
              printf("%d", (*Front)->value[i + 1]);
              break;
            }
            printf("%d-", (*Front)->value[i + 1]);
          }
          prev_lvl_child--;
        }

        // printf("\ngoing to the next child: 2\n");
        int i;

        for (i = 0; i <= (*Front)->count; i++)
        {

          insert_queue(Front, Rear, (*Front)->child[i]);
          lvl_child++;
        }
        // printf("\nlvl child:%d & front_count:%d\n",lvl_child,(*Front)->count);

        // printf("going to the next child: 3\n");
        delete_queue(Front);
        // printf("going to the next child");
        continue;
      }

    } // big else

  } // while

} // func

// Create a node
struct BTreeNode *createNode(int val, struct BTreeNode *child)
{
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
                struct BTreeNode *child)
{
  int j = node->count;
  while (j > pos)
  {
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
               struct BTreeNode *child, struct BTreeNode **newNode)
{
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  while (j <= MAX)
  {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN)
  {
    insertNode(val, pos, node, child);
  }
  else
  {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// Set the value
int setValue(int val, int *pval,
             struct BTreeNode *node, struct BTreeNode **child)
{
  int pos;
  if (!node)
  {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1])
  {
    pos = 0;
  }
  else
  {
    for (pos = node->count;
         (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos])
    {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child))
  {
    if (node->count < MAX)
    {
      insertNode(*pval, pos, node, *child);
    }
    else
    {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

// Insert the value
void insert(int val)
{
  int flag, i;
  struct BTreeNode *child;

  flag = setValue(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

// Search node
void search(int val, int *pos, struct BTreeNode *myNode)
{
  if (!myNode)
  {
    return;
  }

  if (val < myNode->val[1])
  {
    *pos = 0;
  }
  else
  {
    for (*pos = myNode->count;
         (val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos])
    {
      printf("%d is found", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);

  return;
}

// Traverse then nodes

/*int traversal(struct BTreeNode *myNode,int H) {
  int i;
  int d = 0;
  if (myNode) {
    d++;
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i],H+1);
      data[d][i] = myNode->val[i + 1];

    }
    d++;
    traversal(myNode->link[i],H+1);
  }
}*/

// Traverse then nodes
/*
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);

      //printf("%d ", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}


*/

int main()
{
  int value, ch;
  queue *Front = NULL;
  queue *Rear = NULL;
  /*
  insert(1);
  insert(5);
  insert(6);
  insert(2);
  insert(8);
  insert(12);
  insert(14);
  insert(15);
  insert(20);
  insert(7);
  insert(10);

//choosen 1

  insert_queue(&Front,&Rear,root);
  /*int H = 0;
  //traversal(root);
  /*for (int i = 0; i < 100; i++)
  {
      for (int j = 0; j < 4 ; j++)
      {
          printf("%d-",data[i][j]);
      }
      printf("\n");
  }*/
  while (1)
  {
    scanf("%d", &value);
    if (value == -1)
    {
      break;
    }
    else
    {
      insertval(value);
    }
  }

  insert_queue(&Front, &Rear, root);
  levelorder_tree(root, &Front, &Rear, 0);
  printf("\n");
  // search(11, &ch, root);
}