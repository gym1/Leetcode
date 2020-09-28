
# include <bits/stdc++.h>
using namespace std;

#define OUT 0;
#define IN 1;

unsigned countwords (char * str)
{
    int state = OUT;
    unsigned wc = 0;
    
    // read through each word in the string
    while (*str)
    {
        // If next character is a separator, set the  
        // state as OUT
        if (*str == ' ' || *str == '\n' || *str == '\t')
        {
            state = OUT;
        }
        
        // If next character is not a word separator and  
        // state is OUT, then set the state as IN and  
        // increment word count 
        else if (state == OUT)
        {
            state = IN;
            ++ wc;
         }
         ++str;
     }
     return wc;
}

int main(void)  
{  
    char str[] = "One two     three\n four\tfive ";  
    cout<<"No of words : "<<countWords(str);  
    return 0;  
} 
