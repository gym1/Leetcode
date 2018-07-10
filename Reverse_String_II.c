
// The time complexity is O(n)
// This question is ask to reverse every "k" strings
// For example, s = "abcdefg", k = 2 -> "bacdfeg"
// "abcdefg", k = 3 -> "cbadefg"
// "abcd", k = 4 -> "cba"


// The request from Leetcode is following
// "If there are less than k characters left, reverse all of them."
// "If there are less than 2k but greater than or equal to k characters,"
// "then reverse the first k characters and left the other as original."

// Thus, first we modify liitle from revese string 1 for the string reverse method
// Then, we use for loop to check if k is in which condition

void reverse(char *s, int start, int end){
    while(start < end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start ++;
        end --;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i += 2*k){
        if (i+k>=len){
        // Under condition 1&2
            reverse(s, i, len-1);
        }
        else{
        // Normal request, reverse every 2k
            reverse(s, i, i+k-1);
        }
    }
    return s;
    
}
