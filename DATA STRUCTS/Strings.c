#include <stdio.h>
#include <stdlib.h>

int String_Length(char String[]){
    int i = 0;
    int Num_of_c = 0;
  
    while (1)
    {
        
        if (String[i] != '\0')
        {
            i++;
            Num_of_c++;
        }else
        {
            break;
        }
        
        
    }
    
    //printf("%s\t Length is: %d\n",String,Num_of_c);
    
    return Num_of_c;
    

}


char * Upper(char String[]){
    int i;
    int length;
    length = String_Length(String) + 1;
    char * Upper_String = (char *)malloc(length*sizeof(char));
    for ( i = 0; i < length; i++)
    {
        if (String[i] >= 'a' && String[i]<= 'z')
        {
            Upper_String[i] = String[i] - 32;
        }else{
            Upper_String[i] = String[i];
        }
        
    }
    
    //printf("%s\tTurned to\t%s\n",String,Upper_String);
    return Upper_String;
    

}


void String_Apender(char Ap_to[],char Ap_From[]){
    int i;
    int j;
    int Length_to = String_Length(Ap_to) + 1;
    int Length_From = String_Length(Ap_From) + 1;
    j = Length_to - 1;
    for ( i = 0; i < Length_From ; i++)
    {
        Ap_to[j] = Ap_From[i];
        j++;
    }
    Ap_to[j] = '\n';
    printf("%s\n",Ap_to);

}

void str_cat(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        i++;
    }
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    printf("%s",s1);
    
    
}




void String_Reverse(char String[]){
    int length = String_Length(String);
    int i = 0;
    int j = length-1;
    char temp;
   while ( i<j )
   {
        temp = String[j]; 
       String[j] = String[i];
       String[i] = temp;
       j--;
       i++;
   }
   printf("%s\n",String);
}



void str_rev(char s1[]){
    int i = 0 , j = 0;
    char temp;
    while (s1[i] != '\0')
    {
        i++;
    }
    i--;
    while (j < i)
    {
        temp = s1[i];
        s1[i] = s1[j];
        s1[j] = temp;
        j++;
        i--;
    }
    
    printf("%s",s1);
}









int main(){
    char String[99] = "Hello";
    char String2[] = " The world said hi back";

    //str_cat(String,String2);
    /*int Length = String_Length(String);
    char *Upper_String = Upper(String); 
    String_Apender(String,String2);*/
    //String_Reverse(String);
 
    str_rev(String);




    return 0;
}