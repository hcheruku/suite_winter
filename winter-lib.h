/* This tool was programed by Joaquin Manuel Crespo (aka Shyan) and are under the GPLv3 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Struct for backup names and other resources in the programs that use, */

struct Backup
{
	char name[20];
	char repository[60];
	short docker_function;
	char winter__search_used_or_not;
	char winter_search_conf[30] = "/etc/winter/wintersearch.conf";
	char winter_repository_conf[35] = "/etc/winter/winter-repository.conf";
}Back;

/* Clone the package "a" from the repository in the struct.*/
void clone(char a[20]){
	char b[35];
	strcpy(b, "git clone ");
	strcat(b, Back.repository);
	strcat(b, a);
	system(b);
}

/* Open the file that conteins the repository but if don't exist, he create it.*/
void repository(){
	FILE *c;
	char b[60];
	c = fopen("/etc/winter/winter-repository.conf" , "r");
	if (c = NULL ) {
		fclose(c);
		char crear[60];
		strcpy(crear, "touch /etc/winter/winter-repository.conf");
		system(crear);
		char repo_shyan[90];
		strcpy( repo_shyan ,"echo 'https://github.com/ShyanJMC/EkoLinux-Repo/' > /etc/winter/winter-repository.conf");
		system(repo_shyan);
	}
	while(!feof(c)){
		fscanf(c, "%s", &b);
	}
	system("clear");
	strcpy(Back.repository, b);
}

/* Docker function. 1 - instalation 2-run*/
void docker(short e, char b[60]){
	char c[60];
	printf("\n \t Docker initialization \n");
	if (e = (1 + 0)){
		Back.docker_function = 1;
		printf("Building dockerfile, please wait....\n");
		strcpy(c, "docker build -t ");
		strcat(c, b);
		strcat(c, " .");
		system(c);
		printf(" \n Dockerfile installed. If you wish list your images please type: 'docker images' \n");
	}
	else if (e = (2 + 0))
	{
		Back.docker_function = 2;
		printf("\n \t Listening docker images: \n");
		system("docker images");
		printf("\n \n If you wanna start some of that please type; 'docker run -i -t [IMAGE ID] /bin/bash' \n");
	} 
}

