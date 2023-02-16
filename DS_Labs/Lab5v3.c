#include <stdio.h>
#include <stdlib.h>
//Final version of lab5
struct customer
{
    int id;
    int enter_time;
    int proc_time;
    int wait_time;
    struct customer * next;
};
typedef struct customer customer;

struct stack_workers
{
    int id;
    int AVA_t;
    int total_work;
    struct stack_workers *next;
};
typedef struct stack_workers stack_workers;



void push(stack_workers **Top,int id,int ava_t,int total_work){
    stack_workers * newnode = (stack_workers *)malloc(sizeof(stack_workers));
    newnode->id = id;
    newnode->AVA_t = ava_t;
    newnode->total_work = total_work;
    newnode->next = NULL;
    
    if ((*Top) == NULL)
    {
        (*Top) = newnode;
    }else{
        newnode->next = *Top;
        *Top = newnode;
    }
    
}
  


customer * insert_line(customer **Front,customer **rear,int id,int enterT,int proc_t){
    customer *new_customer = (customer *)malloc(sizeof(customer));
    new_customer->id = id;
    new_customer->enter_time = enterT;
    new_customer->proc_time = proc_t;
    new_customer->wait_time = 0;
    new_customer->next = NULL;
    if ((*Front) == NULL)
    {
        (*Front) = new_customer;
        (*rear) = new_customer;
    }else{
        (*rear)->next = new_customer;
        (*rear) = new_customer;
    }
    
}

void Delete(customer **Front){
    customer *ptr = (*Front);
    (*Front) = (*Front)->next;
    free(ptr);
}


stack_workers * pop(stack_workers **Top){
    stack_workers *node = (*Top);
    (*Top) = (*Top)->next;
    return node;
}


void sort_stack(stack_workers **Top){
    stack_workers *temp = NULL;
    stack_workers *nottemp = NULL;
    stack_workers *node = NULL;
    int index = 1;
    int found = 0;
    while (1)
    {
        while ((*Top) != NULL)
        {
            if ((*Top)->id == index)
            {
                node = pop(Top);
                push(&temp,node->id,node->AVA_t,node->total_work);
            }else{
                node = pop(Top);
                push(&nottemp,node->id,node->AVA_t,node->total_work);
            }
            
        }
        index++;
        if (nottemp == NULL)
        {
            while (temp!=NULL)
            {
                node = pop(&temp);
                push(Top,node->id,node->AVA_t,node->total_work);
            }
            break;
            
        }else{
            while (nottemp!=NULL)
            {
                node = pop(&nottemp);
                push(Top,node->id,node->AVA_t,node->total_work);
            }
            continue;
            
        }
        
        
        
    }
    
    
    
}


void job_done(customer **Front,customer **Rear,stack_workers **Top){
    stack_workers *cant_work = NULL;
    stack_workers *still_cant = NULL;
    stack_workers *node = NULL;
    int min = 1;
   
   
    while (1)
    {
        
        if ( (*Front) != NULL && (*Front)->enter_time == min)
        {
               
            if ( (*Top) != NULL && (*Top)->AVA_t <= (*Front)->enter_time)
            {
                
                if ((*Front)->wait_time != 0)
                {   
                    
                    (*Top)->AVA_t = (*Front)->enter_time + (*Front)->proc_time;
                    (*Top)->total_work = (*Top)->total_work + (*Front)->proc_time;
                    printf("%d %d %d %d %d",(*Front)->id,(*Top)->id,(*Front)->enter_time,(*Top)->AVA_t,(*Front)->wait_time);
                    printf("\n");
                    Delete(Front);
                    node = pop(Top);
                    push(&cant_work,node->id,node->AVA_t,node->total_work);
                    continue;
                }else{

                    (*Top)->AVA_t = (*Front)->enter_time + (*Front)->proc_time;
                    (*Top)->total_work = (*Top)->total_work + (*Front)->proc_time;
                    printf("%d %d %d %d %d",(*Front)->id,(*Top)->id,(*Front)->enter_time,(*Top)->AVA_t,(*Front)->wait_time);
                    printf("\n");
                    Delete(Front);
                    node = pop(Top);
                    push(&cant_work,node->id,node->AVA_t,node->total_work);
                    continue;
                }
                
            }else if ((*Top) == NULL)
            {
                (*Front)->wait_time = (*Front)->wait_time + 1;
                (*Front)->enter_time = (*Front)->enter_time + 1;
            }else{
                (*Front)->wait_time = (*Front)->wait_time + 1;
                (*Front)->enter_time = (*Front)->enter_time + 1;
            }
            
        
        }else if ((*Front) == NULL)
        {   
            break;
        }else{
            int index = 0;
           min = (*Front)->enter_time;
           stack_workers *temp = NULL;
        
            while (cant_work != NULL)
            {
                node = pop(&cant_work);
                if (node->AVA_t == min)
                { 
                    push(&temp,node->id,node->AVA_t,node->total_work);
                    index++;
                    continue;
                }else
                {
                    push(&still_cant,node->id,node->AVA_t,node->total_work);
                    continue;
                }
                
              
            }
            if (index >= 2)
            {
                sort_stack(&temp);
            }
            if (temp != NULL)
            {
                while (temp != NULL)
                {
                   node = pop(&temp); 
                   push(Top,node->id,node->AVA_t,node->total_work);
                }
                
            }
            

            

          

            while (still_cant != NULL)
            {
                node = pop(&still_cant);
                push(&cant_work,node->id,node->AVA_t,node->total_work);
                continue;
            }


            
            
        }
        
        
        
        
    }
    while (cant_work != NULL)
    {
        node = pop(&cant_work);
        push(Top,node->id,node->AVA_t,node->total_work);
        continue;
    }
    int index = 6;
    stack_workers *temp = NULL;
    printf("\n");
    while (index != 0)
    {
       while ((*Top)->id != index)
       {
           node = pop(Top);
           push(&temp,node->id,node->AVA_t,node->total_work);
       }
       printf("%d %d\n",(*Top)->id,(*Top)->total_work);
       index--;
       while (temp != NULL)
       {
           node = pop(&temp);
           push(Top,node->id,node->AVA_t,node->total_work);
       }
       
        
    }
    
    
        
        
    
    

}






int main(){
    
    customer *Line_Front = NULL;
    customer *Line_Rear = NULL;

    int id;
    int enterT;
    int proc_t;
    while (1)
    {
        scanf("%d",&id);
        if (id==-1)
        {
            break;
        }else{
            scanf("%d %d",&enterT,&proc_t);
            insert_line(&Line_Front,&Line_Rear,id,enterT,proc_t);

        }
        
    }
    
    stack_workers *Top = NULL;

    int i = 0;

    for ( i = 0; i < 6; i++)
    {
        int id = i+1;
        push(&Top,id,0,0);
    }
    job_done(&Line_Front,&Line_Rear,&Top);
    
    
    
    
    
    return 0;
}