#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>



int *merging_SORTED(int First_Array[],int numofe_F,int Second_Array[],int numofe_S){
    int Findex = 0;
    int Sindex = 0;
    int Tindex = 0;
    int i;
    int compare;
    int size = (numofe_F-1) + (numofe_S-1);
    int *Third_Array; 
    Third_Array = (int *)malloc(size*sizeof(int));
    
    //compare = First_Array[Findex];
    while (Tindex < size)
    {
        if (Findex+1 == numofe_F)
        {
            for (i = Sindex; i < numofe_S; i++)
            {
                Third_Array[Tindex] = Second_Array[i];
                Tindex++;
            }
            
        }else if (Sindex+1 == numofe_S)
        {
            for (i = Findex; i < numofe_F; i++)
            {
                Third_Array[Tindex] = First_Array[i];
                Tindex++;
            }
        }
        
        
        else if (First_Array[Findex]<Second_Array[Sindex])
        {
            Third_Array[Tindex] = First_Array[Findex];
            Tindex++;
            Findex++;
        }else if (First_Array[Findex]>Second_Array[Sindex])
        {
            Third_Array[Tindex] = Second_Array[Sindex];
            Tindex++;
            Sindex++;
        }
        
        
        
    }
    
    return Third_Array;
}


int main(){
    //Merging Two sorted arrays
    int sorted1[5] = {20,30,40,50,60};
    int sorted2[7] = {15,22,31,45,56,62,78};
    int upo1 = 5;
    int upo2 = 7;
    int *sorted3 = merging_SORTED(sorted1,upo1,sorted2,upo2);
    int i;
    printf("\nAfter Merging two SORTED Arrays\n");
    for (i = 0; i < (upo1+upo2)-1; i++)
    {
        printf("%d-",sorted3[i]);
    }
    printf("\n");
    return 0;
}