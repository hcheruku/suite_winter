#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winter-lib.h"

int main (){
  short a; 
  char b[60], c[60];
  strcpy(b, "git clone https://github.com/ShyanJMC/EkoLinux-repo/");
  system("clear");
  printf("Welcome, Do you wanna: \n 1-Install. \n 2-Run images.\n");
  scanf("%d", &a);
  if (a = 1){
  printf("\n Please type the dockerfile to install: " );
  scanf("%s", &c);
  strcat(b, c);
  system(b);
  docker(1, c); }
  else {
    docker(2, c);
  }
  return 0;
}
