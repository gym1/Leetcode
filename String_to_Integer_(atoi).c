int myAtoi(char* str) {   
    int i = 0;    
    while (str[i]==' ') 
        i++;    
    int sign = 1;   
    if (str[i]=='-') {
        i++;
        sign = -1;
    } 
    else if (str[i]=='+')
        i++;   
    if (str[i] < '0' || (int)str[i] > '9')
        return 0;    
    long long number = 0;
    while ((str[i]>='0' && (int)str[i]<='9')) {        
        number = number*10 + (int)(str[i]-'0');        
        if (sign*number>INT_MAX)
            return INT_MAX;
        if (sign*number<INT_MIN)
            return INT_MIN;        
        i++;        
    }    
    return sign*(int) number;        
}


/*
int myAtoi(char* str) {
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
      
    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;  
        i++;  // Also update index of first digit
    }
      
    // Iterate through all digits and update the result
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
    
    // Return result with sign
    return sign*res;
}
*/
