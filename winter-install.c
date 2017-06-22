/* This tool was created by Joaquin Manuel Crespo (aka, ShyanJMC) and are under the GPL v3.*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winter-lib.h"

int main (){
  int a;
  char c[30], b[60];
  int d;
  pthread_t hilo_repositorio;
  system("clear");
  printf("Welcome to winter-install, Do you wanna: \n 1-Install. \n 2-Run images.\n");
  printf("\nSelection: ");
  scanf("%d", &a);
  pthread_create(&hilo_repositorio, NULL, (void *)repository, NULL);
  pthread_join(hilo_repositorio, (void *) &d);
  printf("\n \n Se esta usando el repositorio: %s \n", Back.repository);
  strcpy(b, Back.repository);
  switch(a){
    case 1: {
  printf("\n Please type the dockerfile to install: " );
  scanf("%s", c);
  clone(c);
  docker(1, c);
  break; }
    case 2: {
      docker(2, c);
      break;
    }
    default: printf(" Please type a valid option -_- \n");
    break;
  }
  return 0;
}

