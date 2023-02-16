#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void binarysearch(int *myarray ,int size , int val){
    int found = 0;
    int BEG = 0;
    int END = size - 1;
    printf("\n");
    while (found == 0)
    {
        int MID = (BEG+END)/2;
        if (myarray[MID] == val)
        {
            printf("found at index: %d",MID);
            found = 1;
        }else{
            if (val > myarray[MID])
            {
                BEG = MID + 1;
                printf("wasnt at index: %d\n",MID);
                continue;
            }else{
                END = MID - 1;
                printf("wasnt at index: %d\n",MID);

                continue;
            }
            
        }
        
    }

}






int main(){
    int myarray[11] = {0,1,2,3,4,5,6,7,8,9,10};
    binarysearch(myarray,11,4);
    /*int found = 0;
    int BEG = 0;
    int END = 10;
    int val = 3;
    printf("\n");
    while (found == 0)
    {
        int MID = (BEG+END)/2;
        if (myarray[MID] == val)
        {
            printf("found at index: %d",MID);
            found = 1;
        }else{
            if (val > myarray[MID])
            {
                BEG = MID + 1;
                printf("wasnt at index: %d\n",MID);
                continue;
            }else{
                END = MID - 1;
                printf("wasnt at index: %d\n",MID);

                continue;
            }
            
        }
        
    }*/
    






}