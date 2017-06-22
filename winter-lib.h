/* This tool was created by Joaquin Manuel Crespo (aka, ShyanJMC) and are under the GPL v3.*/

/* For support threads*/
#include <pthread.h>
/* Standar lib*/
#include <stdio.h>
/* SysCalls*/
#include <stdlib.h>
/* Strings support*/
#include <string.h>

/* ~/ */

/* Struct for backup names and other resources in the programs that use, */
struct Backup
{
	char name[20];
	char repository[60];
	short docker_function;
	char winter__search_used_or_not;
	char winter_search_conf[30];
	char *winter_repository_conf[35];
}Back;

/* Clone the package "a" from the repository in the struct.*/
void clone(char a[10]){
	char *b = malloc(strlen(Back.repository) + 20);
	strcpy(b, "git clone ");
	strcat(b, Back.repository);
	strcat(b, "/");
	strcat(b, a);
	system(b);
}

/* Open the file that conteins the repository but if don't exist, he create it.*/
/* When read the file that conteins the repository he test if the file can be inside the var.*/
char *repository(){
	int eleccion;
	char *b = malloc(strlen("https://github.com/ShyanJMC/EkoLinux-repo"));
	printf("\n\n\nElección del repositorio del desarrollador.\n");
	printf("1- Joaquin Manuel Crespo (Shyan) \n2- Ivan Oudkerk \n\nRepositorio a utilizar:");
	scanf("%d", &eleccion);
	switch(eleccion){
	case (1+0): {strcpy(b, "https://github.com/ShyanJMC/EkoLinux-repo"); break;}
    case (2+0): {strcpy(b, "https://github.com/ioudkerk/EkoLinux-repo"); break;}
    default: printf("Por favor ingrese el nº de repo correcto."); break;}
	return strcpy(Back.repository, b);
	pthread_exit(NULL);
	}


/* Docker function. 1 - instalation 2-run*/
void docker(short e, char b[60]){
    printf("\n \t Docker initialization \n");
    system("sudo systemctl start docker");
	char c[60];
	switch(e){
	case (1 +0):
	    Back.docker_function = 1;
		printf("Building dockerfile, please wait....\n");
		strcpy(c, "docker build -t ");
		strcat(c, b);
		strcat(c, " .");
		system(c);
		printf(" \n Dockerfile installed. If you wish list your images please type: 'docker images' \n");
		break;
    case (2 + 0):
        Back.docker_function = 2;
		printf("\n \t Listening docker images: \n");
		system("docker images");
		printf("\n \n If you wanna start some of that please type; 'docker run -i -t [IMAGE ID] /bin/bash' \n");
		break;
	}

}
