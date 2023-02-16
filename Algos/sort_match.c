#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    int j;
    int currMin;
    int x[5] = {5, 3, 1, 2, 4};

    int index;
    int change = 0;

    //Selection Sort
    // for ( i = 0; i < 5-1; i++)
    // {
    //     currMin = x[i];
        
        
    //     for (j = i + 1; j < 5; j++)
    //     {
    //         if (x[j] < currMin)
    //         {
    //             currMin = x[j];
    //             index = j;
    //             change = 1;
    //         }
            
    //     }
    //     if (change == 1)
    //     {
    //         x[index] = x[i];
    //         x[i] = currMin;
    //         change = 0;
    //     }
        
        
    // }

    
    // for ( i = 0; i < 5; i++)
    // {
    //     printf("%d-",x[i]);
    // }

    //Bubble Sort  
    // for ( i = 0; i < 5 - 1; i++)
    // {
    //     for ( j = 0; j < 5-i; j++)
    //     {
    //         if (x[j] > x[j+1])
    //         {
    //             int value = x[j+1];
    //             x[j+1] = x[j];
    //             x[j] = value;
    //         }
            
    //         for ( int z = 0; z < 5; z++)
    //         {
    //             printf("%d-",x[z]);
    //         }
    //         printf("\n");
            
    //     }
        
    // }
    
    // for ( i = 0; i < 5; i++)
    // {
    //     printf("%d-",x[i]);
    // }

    //string matching
    char txt[] = "nboiamslkdma;skfvpanvpiqwenaopindscv";
    char patt[] = "vpi";
    int eq = 0;
    int found = 0;
    
    for ( i = 0; i < 37-4 + 1; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if (txt[i+j] != patt[j]){
                break;
            }
            printf("%d\n",j);
            if (j == 2)
            {
                found = 1;
                printf("\nfound at index:%d\n",i);
                
            }
            printf("%d under\n",j);
            
        }
        
        
    }
    if (found == 0)
    {
        printf("nothing");
    }
    
    
    

    
    
    return 0;
}
