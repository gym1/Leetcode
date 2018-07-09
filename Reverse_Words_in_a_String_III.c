// The time complexity is O(n)?
// the question ask to reverse each work in the string
// For example, "Let's take LeetCode contest" -> "s'teL ekat edoCteeL tsetnoc"


// Thus, we use the same method from string reverse 
// Then, we detect the whole string wehter it has space or at the end
// if it has the space then reverse the word before space 
// Then move on to the next word
// until it at the end


void string_reverse(char* s, int len)
{
   char temp;
   for (int i = 0; i < len/2; i++)
   {
       temp = s[len-i-1];
       s[len-i-1] = s[i];
       s[i] = temp;
   }
}

char* reverseWords(char* s)
{
    int wordslen = strlen(s);
    int wordhead = 0;
    bool inword = false;
    char* result = (char*)malloc((wordslen+1)*sizeof(char *));
    memcpy(result, s, wordslen+1);
    for(int i=0; i<=wordslen; ++i)
    {
        
        if(result[i] == ' ' || result[i] == '\0')
        {
            //printf("%d\n", i);
            if(inword)
            {
                printf("########################\n");
                printf("%d %d\n", i, wordhead);
                printf("%s\n", result+wordhead);
                
                string_reverse(result+wordhead, i-wordhead);
                
                inword = false;
            }
        }
        else
        {
            if(!inword)
            {
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("%d\n", i);
                printf("%s\n", result+wordhead);                
                wordhead = i;
                inword = true;
            }
        }
    }   
    return result;
}

// Another method from the disscussion.
// Need some time to understand
/*
void string_reverse(char arr[], int start, int end)
{
    int i=0;
    int mid = (start+end)/2;
    char temp;
    
    for(i=start; i<=mid; i++)
    {
        temp = arr[i];
        arr[i] = arr[end+start-i];
        arr[end+start-i] = temp;
    }
}

char* reverseWords(char* s) {
    int i=0;
    int word_start = 0;
    int word_end = 0;
    int n = sizeof(s);
    char *str = (char *)malloc(sizeof(n));
    str = s;
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            word_end = i-1;
            string_reverse(s, word_start, word_end);
            word_start = i+1;
        }
        i++;
    }
    word_end = i-1;
    string_reverse(s, word_start, word_end);
    return str;
    
}
*/
