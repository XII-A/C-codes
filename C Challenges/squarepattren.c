#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void push_arr(int ** array,int n,int fill){
    int i;
    int j;
    for (i = 0; i < 2*n; i++) {
        
        for (j = 0; j < 2*n ; j++) {
            if (i >= n-fill && i < ((2*n)-1) - (n-fill))
            {
                if (j >= n-fill && j < ((2*n)-1) - (n-fill) ) {
                    array[i][j] = fill;
                }
            }
            
        }
    }
}


int main() 
{

    int n;
    scanf("%d", &n);
    printf("\n");
    int **array;
    
    array = (int **)malloc( (2*n) *sizeof(int *));
    
    for (int i = 0; i < (2*n); i++) {
     *(array+i) = (int *)malloc((2*n)*sizeof(int));
    }
  	
    for(int i = n; i > 0 ; i--){
        
        push_arr(array,n,i);
    }
    for (int i = 0; i < (2*n)-1; i++)
    {
        for (int j = 0; j < (2*n)-1 ; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
        
    }
    
      
      
    return 0;
}