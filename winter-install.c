#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winter-lib.h"

int main (){
  short a; 
  char c[30];
  char b[60];
  system("clear");
  printf("Welcome, Do you wanna: \n 1-Install. \n 2-Run images.\n");
  scanf("%d", &a);
  repository();
  printf(" Se esta usando el repositorio: %s \n", Back.repository);
  strcpy(b, Back.repository);
  switch(a){
    case 1: { 
  printf("\n Please type the dockerfile to install: " );
  scanf("%s", &c);
  clone(c);
  docker(1, c); }
    case 2: {
      docker(2, c);
    }
    default: printf(" Please type a valid option -_- \n");
  }
  return 0;
}
