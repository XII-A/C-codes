#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char my_string[100];
    int freq[10] = {0};
    scanf("%s",my_string);
    int num = strlen(my_string);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< num; j++) {
            if (my_string[j] - '0' == i)
            {
                freq[i] = freq[i] + 1;
            }
                       
        }
    }
    for ( int i = 0; i < 10; i++)
    {
        printf("%d ",freq[i]);
    }
        
    return 0;
}