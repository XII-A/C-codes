#include <stdio.h>
#include <stdlib.h>
#define unknown 99999
//Correct Version
int paths[15][15];
int unV[10] = {0,1,2,3,4,5,6,7,8,9};
int V[10] = {0};
int VSP[10][2];
int All_V = 0;
int D_F_S;

void VSP_Printer(){
    int i;
    printf("VERTEX\t|SDFA\t|Previous\n");
    for (i = 0; i < 10; i++)
    {
        printf("%c\t|%d\t|%c\n",i+65,VSP[i][0],VSP[i][1]+65);
    }
    
}









void SDFA(int Start_Index){
    int i;
    int j = 0;
    int Shortest_A = unknown;
    int Shortest_AI;
    int Keep_on = 0;
    while (All_V == 0)
    {
        
        for ( i = 0; i < 10; i++)
        {
            if (VSP[i][0]<Shortest_A)
            {
                if (V[i] == 0)
                {
                    Shortest_A = VSP[i][0];
                    Shortest_AI = i;
                    
                    
                }
                
            }
            
            
        }

        for (i = 0; i < 10; i++)
        {
            if (V[i] == 0)
            {
                if (paths[Shortest_AI][i] != -1)
                {
                    D_F_S = paths[Shortest_AI][i] + VSP[Shortest_AI][0];
                    if (D_F_S<VSP[i][0])
                    {
                        VSP[i][0] = D_F_S;
                        VSP[i][1] = Shortest_AI;
                      
                    }
                    
                }
                
            }
            
        }

       V[Shortest_AI] = 1;
       unV[Shortest_AI] = 99;
       Shortest_A = unknown;
        
        for ( i = 0; i < 10; i++)
        {
            if (V[i]==0)
            {
                All_V = 0;
                break;
            }else
            {
                All_V = 1;
            }
            
            
        }
        
        


        
        
        
        
        
        
    }
    
    
    
}


int* functionFindMin(int* array, int row, int cols, char source, char destination){
    
    int i;
    //Preparing VSP----------------------------------------------------
    //Note: VSP[I][0] = Means the SDFA for the index I;
    //Note: VSP[I][1] = Means the Previous for the Index I;
    int Start_Index = source - 65;
    int End_Index = destination - 65;
    for (i = 0; i < 10; i++)
    {
        if (i==Start_Index)
        {
            VSP[i][0] = 0;
        }else
        {
            VSP[i][0] = unknown-1;
        }
        
        
        
    }
    //-------------------------------------------------------------------
    SDFA(Start_Index);
    return VSP[Start_Index];

}




int main(){
    char Space_cheak;
    int Const_Size;

    //Taking input------------------------------
    int i,j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; i < 15; j++)
        {
            scanf("%d",&paths[i][j]);
            scanf("%c",&Space_cheak);

            if (Space_cheak=='\n')
            {
                Const_Size = j;
                break;
            }
            
            
        }
        if (i+1 == j+1)
        {
            break;
        }
        
    }

    char Start,End;
    scanf(" %c",&Start);
    scanf(" %c",&End);
    //------------------------------------------
    if (Start == End)
    {
        printf("%c-%c 0\n",Start,Start);
        return 0;
    }
    
    
    
    int End_Index = End-65;
    int Start_Index = Start-65;
    int * Short_Array; 
    Short_Array = functionFindMin(*paths,Const_Size+1, Const_Size+1,Start,End);
    int prevs[10];
    int num_of_prevs = 0;
    int next_prev = End_Index;
    VSP_Printer();
    
   
    if (VSP[End_Index][0] == unknown-1)
    {
        printf("You cannot travel between two cities");
        
        return 0;
    }

    while (1)
    {
        if (VSP[next_prev][1] != Start_Index)
        {
            prevs[num_of_prevs] = VSP[next_prev][1];
            next_prev = VSP[next_prev][1];
            num_of_prevs++;
        }else if (VSP[next_prev][1] == Start_Index)
        {
            break;
        }
        
            
    }
    
    printf("%c-",Start);
    if (num_of_prevs != 0)
    {
        
        for (i = 1; i <= num_of_prevs; i++)
        {
            printf("%c-",prevs[num_of_prevs-i]+65);
        }
        
    }
    printf("%c %d\n",End,VSP[End_Index][0]);
    
    
    
    
    

    

    return 0;
}