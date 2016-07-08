#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA_TRIM(str, ...) sa_trim(str, (' ', ##__VA_ARGS__))
#define SA_TRIM_CONSTANT(out, str, ...) sa_trim_constant(out, str, (' ', ##__VA_ARGS__))
/*
    Input       - Pointer of type char * that will point to the String, character d which is the character to be trimmed.
    Output      - Return a pointer of type char * which points to the substring after trimming.
    Function    - Trims the second input parameter from string pointed by str and returns a pointer that is pointing
                    to a string with trimming done from begining and ending.
    
    NOTE :- 1) Never override the input pointer with the output of this function.
            2) This function will work only for inputs where the string can be modified.
*/
char * sa_trim(char * str, char d){
    
    size_t len = strlen(str);
    
    int start = 0;
    int end = len - 1;
    
    while(str[start]==d && start<len) start++;
    
    while(str[end]==d && end>=0) end--;

    str = str+start;
    str[end-start+1] = 0;
    
    return str;
}

/*
    Input       - Pointer of type char * that will point to the output String, Pointer 
                    of type char * that will point to the input String, character d which 
                    is the character to be trimmed.
    Output      - 
    Function    - Trims the third input parameter from string pointed by str and sets the 
                    pointer of first parameter to a string with trimming done from begining and ending.
    
    NOTE :- 1) This function will work for inputs where the string cannot be modified.
            2) The ouput string must be long enough to hold the trimmed characters.
*/
void sa_trim_constant(char * out, char * str, char d){
    size_t len = strlen(str);
    
    int start = 0;
    int end = len - 1;
    
    while(str[start]==d && start<len) start++;
    
    while(str[end]==d && end>=0) end--;

    str = str+start;
    
    memcpy(out, str, end-start+1);
    out[end-start+1] = 0;
}

/*
    TEST CASES
*/
void main() {
     
    char str[14] = " Souradip    ";
    char * str1 = SA_TRIM(str, 's');
    printf("<%s>",str1);
    
    char str3[64]; 
    char *str2 = " Souradip    ";
    SA_TRIM_CONSTANT(str3, str2, 'd');
    printf("<%s>",str3);
    *str3 = 'I';
    printf("<%s>",str3);
}
