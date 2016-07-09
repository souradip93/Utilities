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

#include "../include/sa_vector.h"

Vector *create_vector(){
  Vector *v;
  v = malloc(sizeof(Vector));
  v->totalNumberOfElements = 0;
  v->maximumNumberOfElements = INITIAL_CAPACITY;
  v->head = malloc(v->maximumNumberOfElements * sizeof(void *));
  assert(v->head);
  return v;
}

void delete_vector(Vector *v){
  free(v->head);
  free(v);
}

void push_back(Vector *v, void * item){
  if(v->totalNumberOfElements == v->maximumNumberOfElements){
    void **head = realloc(v->head, v->maximumNumberOfElements * 2 * sizeof(void *));
    assert(head);
    v->maximumNumberOfElements = v->maximumNumberOfElements*2;
    v->head = head;
  }
  v->head[v->totalNumberOfElements] = item;
  v->totalNumberOfElements++;
}

void * element_at(Vector *v, int index){
  return v->head[index];
}

