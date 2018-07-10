// The question ask to reverse the vowels in the string
// Thus, we modify the reverse function from the string reverse
// Then, create a hash table to store all the vowels,
//.. 
void reverse(int *a, char *s, int beg, int end)
{
    while(beg<end)
    {
        if(a[s[beg]]==1&&a[s[end]]==1)
        {
            s[beg]=s[beg]^s[end];
            s[end]=s[beg]^s[end];
            s[beg]=s[beg]^s[end];
            beg++;
            end--;
        }
        while(a[s[beg]]!=1&&beg<end)
        {
            beg++;
        }
        while(a[s[end]]!=1&&beg<end)
        {
            end--;
        }
    }       
}
char* reverseVowels(char* s) {
    int i=0;
    int j=strlen(s)-1;
    if(j<1)
    {return s;}
    int a[123]={0};
    a['a']=1;a['e']=1;a['i']=1;a['o']=1;a['u']=1;
    a['A']=1;a['E']=1;a['I']=1;a['O']=1;a['U']=1;
    reverse(a, s, i, j);
    return s;
}
