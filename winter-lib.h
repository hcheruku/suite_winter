/* This tool was created by Joaquin Manuel Crespo (aka, ShyanJMC) and are under the GPL v3.*/

/* For support threads*/
#include <pthread.h>
/* Standar lib*/
#include <stdio.h>
/* SysCalls*/
#include <stdlib.h>
/* Strings support*/
#include <string.h>

/*Support for sockets */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

/* Struct for sockets and their bridge vars*/
struct sockaddr *sock_bridge;

/* Alias/
#define UDP SOCK_DGRAM
#define TCP SOCK_STREAM

/* ~/ */

/* Struct for backup names and other resources in the programs that use, */
struct Cache
{
        char name[20];
        char repository[60];
        short docker_function;
        char winter__search_used_or_not;
        char winter_search_conf[30];
        char *winter_repository_conf[35];
        char socket_protocol;
        char ip_adress[15];
        int socket_port;
        int socket_file_descriptor;
	int is_root; /* 0 for yes, 1 for no */
}cache;

char check_user(){ 
	if (geteuid() = 0 ) { printf("Using root privilegies");return (cache.is_root = 0); }
	return (cache.is_root = 1);
}

/* In future versiones I will atach support for RAW sockets.*/
int socket-client(int type, char protocol[3], char ip[15], int port){
        getaddrinfo(ip, port, const struct addinfo *hints, struct addrinfo **res);
        int a; 
        char *messege;
        char buffer[7000];
        a = socket(PF_INET, protocol, 0);
        if (a = -1) { printf("Error in socket"); return 1; }
        printf("Opened socket in Ipv4 with protocol; %s", protocol);
        strcpy(cache.socket_file_descriptor, a);
	strcpy(cache.socket_protocol, protocol);
        printf("Please insert the messege to send to target: \n");
        scanf("%s", buffer);
        messege = malloc(strlen(buffer));
        strcpy(messege, buffer);
        buffer= 0;
        printf("Connecting to target and sending messege\n");
        connect("a, sock_bridge.ai_addr, sock_bridge.ai_addrlen);
        if (a = -1){ printf("Error in socket\n");
        int send_file;
        int msg-len = strlen(messege);
        send_file = send(a, *messege, msg-len, 0);
        if (send_file = -1){ printf("error in sending \n"); return 1;}
        printf("Waiting answer ...\n");
        int recv_file;
        recv_file = recv(a, buffer, 7000, 0);
        switch(recv_file){
                case(-1+0): printf("Error in recv \n");
                case(0+0): printf("The target close the conecttion \n");
                default: printf("%s \n", buffer);
	return 0;
        pthread_exit(NULL);
}

/* Clone the package "a" from the repository in the struct.*/
void clone(char a[10]){
	char *b = malloc(strlen(Back.repository) + 20);
	strcpy(b, "git clone ");
	strcat(b, Back.repository);
	strcat(b, "/");
	strcat(b, a);
	system(b);
}

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
    char *user_to_docker = malloc(strlen("sudo usermod -a -G docker ") + 10);
    char user[10];
    system("clear");
    printf("\n \t Docker initialization \nRecuerde que para ejecutar docker usted debe tener soporte de aufs-4 en el kernel.\n");
    printf("Ingrese su usuario, por favor: ");
    scanf("%s", user);
    strcpy(user_to_docker, "sudo usermod -a -G docker ");
    strcat(user_to_docker, user);
    system(user_to_docker);
    printf("\nAñadido a %s al grupo de docker\n", user);
    system("sudo dockerd");
    printf("\nIniciado el demonio docker. \n");
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
