
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *reverseString(char* s)
{
    // The time complexity is O(logn)
    // This question is ask to reverse strings
    // For example, Hello->olleH
    
    // Thus, we can swap between front and end.
    // That means we only need to do length of string/2 times
    
   int len = strlen(s);
   char temp;
   for (int i = 0; i < len/2; i++)
   {
       temp = s[len-i-1];
       s[len-i-1] = s[i];
       s[i] = temp;
   }


   // we can also use XOR to swap string
   for (int i = 0; i < len/2; i++)
   {
       s[i] = s[i]^s[len-i-1];
       s[len-i-1] = s[i]^s[len-i-1];
       s[i] = s[i]^s[len-i-1];
   }
   return s;
}

int main(int argc, char const *argv[])
{
	char temp[5] = "abs";
	reverseString(temp);
	printf("%s\n", temp);

	return 0;
}
