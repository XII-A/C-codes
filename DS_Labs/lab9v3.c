#include <stdio.h>
#include <stdlib.h>
// NOT WORKING

#define ORDER 3
#define MIN 1

struct tree {
  int nodes[ORDER + 1];
  int nodes_num;
  struct tree *childs[ORDER + 1];
};

struct tree *root;


struct queue
{
    int value[ORDER + 1];
    int count;
    struct tree *child[ORDER + 1];
    struct queue * next_node;
};
typedef struct queue queue;


void insert_queue(queue **Front,queue **Rear,struct tree * mytree){
    queue * newnode = (queue *)malloc(sizeof(queue));
    if (mytree == NULL)
    {
        return;
    }
    newnode->count = mytree->nodes_num;
    if (mytree->nodes != NULL)
    {
        for (int i = 0; i < mytree->nodes_num; i++)
        {
            newnode->value[i+1] = mytree->nodes[i+1];
        }
        
    }

	for (int i = 0; i <= mytree->nodes_num; i++)
	{
	    
	    newnode->child[i] = mytree->childs[i];
	      
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

int number_nodes = 0;

void levelorder_tree(struct tree * mytree,queue **Front,queue **Rear,int lvl){
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
        }else
        {
            if (lvl == 0)
            {
                nodes_printed++;
                if ((*Front)->count != 0)
                {
                    for (int i = 0; i < (*Front)->count; i++)
                    {
                        if (i+1 == (*Front)->count)
                        {
                            printf("%d",(*Front)->value[i+1]);
                            break;
                        }
                        printf("%d-",(*Front)->value[i+1]);
                    }
                    
                }
                for (int i = 0; i <= (*Front)->count; i++)
                {

                   

                    insert_queue(Front,Rear,root->childs[i]);

                    lvl_child++;
                }
                lvl++;

                
                
                delete_queue(Front);
                
                continue;
            }else
            {
                if (prev_lvl_child == 0)
                {
                    prev_lvl_child = lvl_child;
                    lvl_child = 0;
                    printf("\n");
                }else{
                    printf(", ");
                }
                
                if ((*Front)->count != 0)
                {
                    for (int i = 0; i < (*Front)->count; i++)
                    {
                        if (i+1 == (*Front)->count)
                        {
                            printf("%d",(*Front)->value[i+1]);
                            break;
                        }
                        printf("%d-",(*Front)->value[i+1]);
                    }
                    prev_lvl_child--;
                }

                
                int i;
                



                for (i = 0; i <= (*Front)->count; i++)
                {
                    
                    insert_queue(Front,Rear,(*Front)->child[i]);   
                    lvl_child++;
                }
                
                
                
                
                delete_queue(Front);
                
                continue;


            }
            
            
        }
        
        
    }
    
}




struct tree *new_node(int value, struct tree *child) {
  struct tree *newnode;
  newnode = (struct tree *)malloc(sizeof(struct tree));
  newnode->nodes[1] = value;
  newnode->nodes_num = 1;
  newnode->childs[0] = root;
  newnode->childs[1] = child;
  return newnode;
}


void node_insert(int value, int position, struct tree *node,struct tree *child)                           
{
  int i = node->nodes_num;
  while (i > position) 
  {
    node->nodes[i + 1] = node->nodes[i];
    node->childs[i + 1] = node->childs[i];
    i--;
  }
  node->nodes[i + 1] = value;
  node->childs[i + 1] = child;
  node->nodes_num++;
}


void fixer(int value, int *prevval, int position, struct tree *node,struct tree *child, struct tree **newnode) 
{
  int med; 
  int j;

  if (position > MIN)
    med = MIN + 1;
  else
    med = MIN;

  *newnode = (struct tree *)malloc(sizeof(struct tree));
  j = med + 1;
  while (j <= ORDER) 
  {
    (*newnode)->nodes[j - med] = node->nodes[j];
    (*newnode)->childs[j - med] = node->childs[j];
    j++;
  }
  node->nodes_num = med;
  (*newnode)->nodes_num = ORDER - med;

  if (position <= MIN) {
    node_insert(value, position, node, child);
  } else {
    node_insert(value, position - med, *newnode, child);
  }
  *prevval = node->nodes[node->nodes_num];
  (*newnode)->childs[0] = node->childs[node->nodes_num];
  node->nodes_num--;
}


int value_changer(int value, int *prevval,struct tree *node, struct tree **child)
{
  int pos;
  if (!node) {
    *prevval = value;
    *child = NULL;
    return 1;
  }

  if (value < node->nodes[1]) {
    pos = 0;
  } else 
  {
    for (pos = node->nodes_num;
       (value < node->nodes[pos] && pos > 1); pos--)
      ;
    if (value == node->nodes[pos]) 
    {
      return 0;
    }
  }
  if (value_changer(value, prevval, node->childs[pos], child)) 
  {
    if (node->nodes_num < ORDER) 
    {
      node_insert(*prevval, pos, node, *child);
    } else 
    {
      fixer(*prevval, prevval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}


void insertval(int value) {
  int bool; 
  int i;
  struct tree *child;

  bool = value_changer(value, &i, root, &child);
  if (bool)
    root = new_node(i, child);
}






int main() {
  int value;
  queue * Front = NULL;
  queue * Rear = NULL;


  while (1)
  {
      scanf("%d",&value);
      if (value == -1)
      {
        break;
      }
      else
      {
        insertval(value);
      }
      
  }
  
  

  insert_queue(&Front,&Rear,root);
  levelorder_tree(root,&Front,&Rear,0);
}
