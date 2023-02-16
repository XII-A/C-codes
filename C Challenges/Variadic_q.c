#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*In this problem, you will implement three variadic functions named sum,min,max  
and  to calculate sums, minima, maxima of a variable number of arguments. 
The first argument passed to the variadic function is the count of the number of arguments, which is followed by the arguments themselves.*/

int sum(int count,...){
    va_list args;
    va_start(args,count);
    int SUM_OF_ARGS = 0;
    for (int i = 0; i < count; i++)
    {
        int value = va_arg(args,int);
        SUM_OF_ARGS = SUM_OF_ARGS + value;
    }
    va_end(args);
    return SUM_OF_ARGS;

}

int max(int count,...){
    va_list args;
    va_start(args,count);
    int max = -9999;
    for (int i = 0; i < count; i++)
    {
        int value = va_arg(args,int);
        if (value > max)
        {
            max = value;
        }else{
            continue;
        }
        
    }
    va_end(args);
    return max;
}

int min(int count,...){
    va_list args;
    va_start(args,count);
    int min = 9999;
    for (int i = 0; i < count; i++)
    {
        int value = va_arg(args,int);
        if (value < min)
        {
            min = value;
        }else{
            continue;
        }
        
    }
    va_end(args);
    return min;
    
}




int main(){

    int x = sum(4,1,2,3,4);
    int y = max(4,1,99,3,4);
    int z = min(4,1,2,3,4);
    printf("%d",z);
    return 0;
}