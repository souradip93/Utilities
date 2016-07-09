/*
MIT License
Copyright (c) 2016 Souradip Guha
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <string.h>

#ifndef TRIM_H
#define TRIM_H

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
char * sa_trim(char * str, char d);

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
void sa_trim_constant(char * out, char * str, char d);

#endif
