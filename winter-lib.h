#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Docker function. 1 - instalation 2-run*/
char docker(short a, char b[60], char c[60]){
	printf("\n \t Docker initialization \n");
	if (a = (1 + 0)){
		printf("Building dockerfile, please wait....\n");
		char c[60];
		strcpy(c, "docker build -t ");
		strcat(c, b);
		strcat(c, ".");
		system(c);
		printf(" Dockerfile installed. If you wish list your images please type: 'docker images' \n");
	}
	else if (a = (2 + 0))
	{
		printf("\n \t Listening docker images: \n");
		system("docker images");
		printf("\n \n If you wanna start some of that please type; 'docker run -i -t [IMAGE ID] /bin/bash' \n");
	} 
	return 0;
}
