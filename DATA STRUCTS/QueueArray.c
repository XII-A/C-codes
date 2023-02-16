#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
int queue[6];
int Front = 0;
int Max = 7;
int Rear = 0;
//Linear--------------------------------------------------
void insert(int val){                                   
    if ( (Rear  + 1) >= Max)                                
    {
        printf("Overflow");
        return;
    }else{
        queue[Rear] = val;
        Rear++;
    }
    
}

void Delete(){
    if (Rear == 0)
    {
        printf("Underflow");
    }else{
        int i;
        for ( i = 0; i < 6; i++)
        {
            queue[i] = queue[i+1];
        }
        Rear--;
        
    }
    
}
//----------------------------------------------------------

//Cirular array thingy-------------------------------------
void insert_Cir(int val){                                   
    if ( (Rear  + 1) == Max && Front == 0)                                
    {
        printf("Overflow");
        return;
    }else if ((Rear  + 1) == Max && Front != 0)
    {
        Rear = 0;
        queue[Rear] = val;
        Rear++;
    }
    else{
        queue[Rear] = val;
        Rear++;
    }
    
}

void Delete_Cir(){
    if (Rear == 0)
    {
        printf("Underflow");
    }else{
        int i;
        for ( i = 0; i < 6; i++)
        {
            queue[i] = queue[i+1];
        }
        Rear--;
        
    }
    
}
//---------------------------------------------------------









int main(){
    //Linear Array implementation
    /*
    int i;
    for ( i = 0; i < 10; i++)
    {
        insert(i);     
    }
    printf("\n");
    for ( i = 0; i < Rear; i++)
    {
        printf("%d-",queue[i]);
    }
    printf("\n");
    Delete();
    for ( i = 0; i < Rear; i++)
    {
        printf("%d-",queue[i]);
    }
    */
    //Circilar array implementation
    /*
    int i;
    for ( i = 0; i < 10; i++)
    {
        insert_Cir(i);     
    }
    printf("\n");
    for ( i = 0; i < Rear; i++)
    {
        printf("%d-",queue[i]);
    }
    printf("\n");
    Delete_Cir();
    for ( i = 0; i < Rear; i++)
    {
        printf("%d-",queue[i]);
    }
    */
    
   
    
}