#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winter-lib.h"

int main (){
  char a[30], b[60], c[60];
  strcpy(b, "git clone https://github.com/ShyanJMC/EkoLinux-repo/");
  system("clear");
  printf("Welcome, Do you wanna: \n 1-Install. \n 2-Run images.\n");
  scanf("%d", &a);
  if (a = "1"){
  printf("\n Please type the dockerfile to install: " );
  scanf("%s", &c)
  docker(1, b, c); }
  else {
    docker(2);
  }
  return 0;
}
