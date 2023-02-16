#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

/*void insert_mid(int Tarray[],int numofe,int Windex,int value){
    int i;
    for ( i = numofe; i > Windex; i--)
    {
        Tarray[i] = Tarray[i-1];
    }
    Tarray[Windex] = value;

}*/
void insert_mid(int myarray[],int ins_ele,int upper,int index){
    int i;
    for ( i = upper; i >= index ; i--)
    {
        myarray[i+1] = myarray[i];
    }
    myarray[index] = ins_ele;
    
}

int smallest_num(int Tarry[],int numofe){
    int i;
    int smallest;
    smallest = Tarry[0];

    for (i = 1; i < numofe; i++)
    {
        if (Tarry[i] < smallest)
        {
            smallest = Tarry[i];
        }else
        {
            continue;
        }
    }
    return smallest;
}

void delet_num(int Tarry[],int numofe,int Lindex){
    int i;
    for (i = Lindex; i < numofe; i++)
    {
        Tarry[i] = Tarry[i+1];
    }
    
}

int * merging_UNSORTED(int First_Array[],int numofe_F,int Second_Array[],int numofe_S){

    int i;
    int r = 0;
    int size = (numofe_F-1) + (numofe_S-1);
    //creating the third Array
    int *Third_Array; 
    Third_Array = (int *)malloc(size*sizeof(int));
    //puuting the arrays inside of the Third Array
    for ( i = 0; i < numofe_F; i++)
    {
        Third_Array[r] = First_Array[i];
        r++;        
    }
    for (i = 0; i < numofe_S; i++)
    {
        Third_Array[r] =Second_Array[i];
        r++;
    }
    
    return Third_Array;
}

int *merging_SORTED(int First_Array[],int numofe_F,int Second_Array[],int numofe_S){ //didnt cheack if its working just copied it from testmsot
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
    
    int My_Array[11];
    int i;
    int upperbound = 10;
    //int numofe = 10;
    //initalizing the array
    for (i = 0; i < upperbound; i++)
    {
        My_Array[i] = i;
    }
    //prinitng the elments
    for (i = 0; i < upperbound; i++)
    {
        printf("%d-",My_Array[i]);
    }

    printf("\n");

    //isnerting an elment in the mid of the array
    insert_mid(My_Array,200,10,3);


    printf("\nAfter insertion\n");
    upperbound++;
    for (i = 0; i < upperbound; i++)
    {
        printf("%d-",My_Array[i]);
    }

    printf("\n\nAfter finding the smallest num\n");
    int smallestinarray = smallest_num(My_Array,10);
    printf("\nda smallest num is: %d \n",smallestinarray);
    
    //deleting a num
    delet_num(My_Array,upperbound,3);
    upperbound--;
    printf("\nAfter deleting:\n");
    for (i = 0; i < upperbound; i++)
    {
        printf("%d-",My_Array[i]);
    }
    printf("\n\nupperbound is : %d",upperbound);

    int My_SArray[11];
    int inputs = 20;
    //initalizing the second array
    for (i = 0; i < upperbound; i++)
    {

        My_SArray[i] = inputs;
        inputs++;
    }
    printf("\n\nThe second array vlaues:\n");
    for (i = 0; i < upperbound; i++)
    {
        printf("%d-",My_SArray[i]);
    }
    printf("\n");

    //Merging the second array and the first array into one array
    int *My_ThirdArray = merging_UNSORTED(My_Array,upperbound,My_SArray,upperbound);
    printf("\nAfter merging the two arrays:\n");
    for (i = 0; i < upperbound*2; i++)
    {
        printf("%d-",My_ThirdArray[i]);
    }
    printf("\n");

    //Merging Two sorted arrays
    int sorted1[5] = {20,30,40,50,60};
    int sorted2[7] = {15,22,31,45,56,62,78};
    int upo1 = 5;
    int upo2 = 7;
    int *sorted3 = merging_SORTED(sorted1,upo1,sorted2,upo2);
    printf("\nAfter Merging two SORTED Arrays\n");
    for (i = 0; i < upo1+upo2; i++)
    {
        printf("%d-",sorted3[i]);
    }
    printf("\n");
    return 0;
}