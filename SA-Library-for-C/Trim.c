#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA_TRIM(str, ...) sa_trim(str, (' ', ##__VA_ARGS__))
#define SA_TRIM_CONSTANT(out, str, ...) sa_trim_constant(out, str, (' ', ##__VA_ARGS__))

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
