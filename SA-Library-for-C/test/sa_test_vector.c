#include<stdio.h>

#include "../include/sa_vector.h"

/*
###########################################################
#####################    Test Case    #####################
###########################################################
*/
void main(){
  Vector *v = create_vector();
  printf("Vector address - %p\n",v);
  printf("Vector head address - %p\n",v->head);
  printf("First element address - %p\n",*v->head);
  push_back(v,"Souradip");
  printf("Vector address - %p\n",v);
  printf("Vector head address - %p\n",v->head);
  printf("First element address - %p\n",*v->head);
  printf("%s",(char *)element_at(v, 100));
  delete_vector(v);
}
