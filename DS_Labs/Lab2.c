#include <stdio.h>
#include <stdlib.h>
char grid[15][15];
char word[15];
int index_found[15];
char Myo[15][15];

int Word_size(){
    int i = 0;
    while (1)
    {
        if (word[i] == '\0')
        {
            return i;
        }else{
            i++;
        }
        
    }
    
}



void Grid_print(){
    int i;
    int j;
    for ( i = 0; i < 15; i++)
    {
        for ( j = 0; j < 15; j++)
        {
            printf("%c |",grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\n%s",word);
}


int Is_In(char gus){
    int i;
    for ( i = 0; i < 15; i++)
    {
        if (gus == word[i])
        {
            return 1;
        }else
        {
            continue;
        }
        
        
    }
    

}

int Right_Search(int size,int i,int j){
    int z;
    int c = 0;
    char gus_word[15];
    int we_good = 0;

    //Makin the gus word equal till the num of letters infront of the first found letter
    for ( z = 0; z < size; z++)
    {
        gus_word[z] = grid[i][j+z];
    }

    //Not inverse equality-----------------
    for ( z = 0; z < size; z++)
    {
        if (gus_word[z] == word[z])
        {
            we_good = 1;

        }else{
            we_good = 0;
            break;
        }
        
    }

    //Inverse equality-------------------
    if (we_good == 1)
    {
        return 1;

    }else
    {
        for ( z = size - 1; z >= 0; z--)
        {
            if (gus_word[z] == word[c])
            {
                we_good = 1;
                c++;

            }else{
                we_good = 0;
                break;
            }
            
        }
    }

    if (we_good == 1)
    {
        return 1;
    }else{
        return 0;
    }
    
    
        


}

int Down_Search(int size,int i,int j){
    int z;
    int c = 0;
    char gus_word[15];
    int we_good = 0;

    //Makin the gus word equal till the num of letters Under the first found letter
    for ( z = 0; z < size; z++)
    {
        gus_word[z] = grid[i+z][j];
    }

    //Not inverse equality-----------------
    for ( z = 0; z < size; z++)
    {
        if (gus_word[z] == word[z])
        {
            we_good = 1;

        }else{
            we_good = 0;
            break;
        }
        
    }

    //Inverse equality-------------------
    if (we_good == 1)
    {
        return 1;

    }else
    {
        for ( z = size - 1; z >= 0; z--)
        {
            if (gus_word[z] == word[c])
            {
                we_good = 1;
                c++;

            }else{
                we_good = 0;
                break;
            }
            
        }
    }

    if (we_good == 1)
    {
        return 1;
    }else{
        return 0;
    }

}

int DiagRD_Search(int size,int i,int j){
    int z;
    int c = 0;
    char gus_word[15];
    int we_good = 0;

    //Makin the gus word equal till the num of letters DiagRD the first found letter
    if (i+(size - 1) != 15 &&  j+(size - 1) != 15)
    {
        for ( z = 0; z < size; z++)
        {
            gus_word[z] = grid[i+z][j+z];
        }
    }else
    {
        return 0;
    }

    //Not inverse equality-----------------
    for ( z = 0; z < size; z++)
    {
        if (gus_word[z] == word[z])
        {
            we_good = 1;

        }else{
            we_good = 0;
            break;
        }
        
    }

    //Inverse equality-------------------
    if (we_good == 1)
    {
        return 1;

    }else
    {
        for ( z = size - 1; z >= 0; z--)
        {
            if (gus_word[z] == word[c])
            {
                we_good = 1;
                c++;

            }else{
                we_good = 0;
                break;
            }
            
        }
    }

    if (we_good == 1)
    {
        return 1;
    }else{
        return 0;
    }
    
}

int DiagLD_Search(int size,int i,int j){
    int z;
    int c = 0;
    char gus_word[15];
    int we_good = 0;

    //Makin the gus word equal till the num of letters DiagLD the first found letter
    if ( i+(size - 1) != 15  &&  j - (size - 1) >= 0)
    {
        for ( z = 0; z < size; z++)
        {
            gus_word[z] = grid[i+z][j-z];
        }
    }else
    {
        return 0;
    }

    //Not inverse equality-----------------
    for ( z = 0; z < size; z++)
    {
        if (gus_word[z] == word[z])
        {
            we_good = 1;

        }else{
            we_good = 0;
            break;
        }
        
    }

    //Inverse equality-------------------
    if (we_good == 1)
    {
        return 1;

    }else
    {
        for ( z = size - 1; z >= 0; z--)
        {
            if (gus_word[z] == word[c])
            {
                we_good = 1;
                c++;

            }else{
                we_good = 0;
                break;
            }
            
        }
    }

    if (we_good == 1)
    {
        return 1;
    }else{
        return 0;
    }
}


void Output(int Case,int size,int i,int j){
    // case 0 means its to the right
    // case 1 means its under
    // case 2 means its diagRD
    // case 3 means its diagLD
    int z;
    int d;
    if (Case == 0)
    {
        //Putting the chars between the stars
        for ( z = 0; z < size; z++)
        {
            Myo[i][j+z] = grid[i][j+z];
        }
        
        
    }else if (Case == 1)
    {
        for ( z = 0; z < size; z++)
        {
            Myo[i+z][j] = grid[i+z][j];
        }
    }else if (Case == 2)
    {
        for ( z = 0; z < size; z++)
        {
            Myo[i+z][j+z] = grid[i+z][j+z];
        }
    }else if (Case == 3)
    {
        for ( z = 0; z < size; z++)
        {
            Myo[i+z][j-z] = grid[i+z][j-z];
        }


    }
    
    
    
    
    

    
    

}



int Search(int size){
    int i;
    int j;
    for ( i = 0; i < 15; i++)
    {
        for ( j = 0; j < 15; j++)
        {
            if (Is_In(grid[i][j]))
            {
                if (Right_Search(size,i,j))
                {
                    //printf("(Right) we found it starting at: %d - %d\n",i,j);
                    Output(0,size,i,j);
                    break;
                }else if (Down_Search(size,i,j))
                {
                    //printf("(Down) we found it starting at: %d - %d\n",i,j);
                    Output(1,size,i,j);
                    break;
                }else if (DiagRD_Search(size,i,j))
                {
                    //printf("(DiagRD) we found it starting at: %d - %d\n",i,j);
                    Output(2,size,i,j);
                    break;
                }else if (DiagLD_Search(size,i,j))
                {
                    //printf("(DiagLD) we found it starting at: %d - %d\n",i,j);
                    Output(3,size,i,j);
                    break;
                }
                
                
                
                
            }else
            {
                continue;
            }
            
            
        }
        
    }
    
}




int main(){

//Taking input-------------------------------------
int i;
int j;

for ( i = 0; i < 15; i++)
{
    for ( j = 0; j < 15; j++)
    {
        scanf(" %c",&grid[i][j]);
        Myo[i][j] = '*';
    }
    
}

scanf("%s",word);
//--------------------------------------------------

//Searching-------------------
int size = Word_size();

Search(size);

int z,d;

for ( z = 0; z < 15; z++)
        {
            for ( d = 0; d < 15; d++)
            {
                printf("%c",Myo[z][d]);
            }
            printf("\n");
        }

return 0;

}








