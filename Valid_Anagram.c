// Need to edit later
//
bool isAnagram(char* s, char* t) {
    if(s==NULL && t==NULL) return true;
    if(strlen(s) != strlen(t)) return false;
    
    int a[26]={0};
    for(int i=0;i<strlen(s);i++){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(a[i]<0) return false;
    }
    return true;
}
/*
bool isAnagram(char* s, char* t) {

if(!s || !t) return false;

int x,y,i;
int p[26] = {1,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
//prime numbers
x = 0;
y = 0;

for(i = 0; s[i] != '\0' && t[i] != '\0'; i++){
    x += s[i] * p[s[i] - 'a'];
    y += t[i] * p[t[i] - 'a'];
}

return x == y && s[i] == t[i];
}
*/
