#include <stdio.h>
#include <stdlib.h>
#include "../include/sa_trim.h"

/*
###########################################################
#####################    Test Case    #####################
###########################################################
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
