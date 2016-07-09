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

#include<stdlib.h>
#include<assert.h>

#ifndef SA_VECTOR
#define VECTOR_H

#define INITIAL_CAPACITY 4

/*
###########################################################
##################    Data Structures    ##################
###########################################################
*/
/*Vector Data Structure*/
struct Vector{
  int totalNumberOfElements; /*Holds the current number of elements*/
  int maximumNumberOfElements; /*Holds the maximum number of elements*/
  void **head; /*Holds the address of first element*/
};
typedef struct Vector Vector;

/*
###########################################################
#################    Public Functions     #################
###########################################################
*/
/*
  Input     -
  Output    - Pointer to a vector.
  Function  - Creates a new vector.
*/
Vector * create_vector();

/*
  Input     - Pointer to a vector.
  Output    -
  Function  - Deletes a new vector.
*/
void delete_vector(Vector *);

/*
  Input     - Pointer to a vector, Element to be inserted.
  Output    -
  Function  - Inserts a new element to the Vector.
*/
void push_back(Vector *, void * item);

/*
  Input     - Pointer to a vector, Index position.
  Output    - Pointer to vector element.
  Function  - Gets the Element at rovided index.
*/
void * element_at(Vector *, int index);

#endif
