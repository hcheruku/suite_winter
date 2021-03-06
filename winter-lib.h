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

/*Alias */
#define HTTP "80"
#define HTTPS "443"

/*Struct for backup names and other resources in the programs that use */

struct Cache
{
        char name[20];
        char repository[60];
        short docker_function;
        char winter__search_used_or_not;
        char winter_search_conf[30];
        char *winter_repository_conf[35];
	int is_root; /* 0 for yes, 1 for no */
	char directory_image[300];
	short photorec; /* For data rescure */
	short adb_listen; /*Android Debug Bridge*/
	short adb_install; /* "" */
	short adb_uninstall; /* "" */
	short adb_copy_to_local; /* "" */
	short adb_copy_to_device; /* "" */
	short adb_backup; /* "" */
	short adb_shell; /* "" */
	short systrace; /* For analyze the performance of an app in Android Device */
	char android_device[30]; /* As the name say, the name of the android device */
}cache;

int adb_listen(){
	cache.adb_listen = 1;
	char temporal1[60];
	printf("----\nAndroid Debug Bridge initializated\n");
	char adb[82] = "sudo ./android-platform-tools/adb";
	printf("Listing Android devices detected\n");
	strcpy(temporal1, adb);
	strcat(temporal1, " get-state get-serialno get-devpath devices -l ");
	system(temporal1);
	return 0;}

int adb_install(char device[30], char apk[100]){
	cache.adb_install = 1;
	char temporal1[100] = "sudo ./android-platform-tools/adb -s";
	printf("----\nAndroid install apk to device tool\n");
	strcat (temporal1, device);
	strcat (temporal1, " install ");
	strcat (temporal1, apk);
	system(temporal1);
	return 0;}

int adb_remove(char device[30], char apk[100]){
        cache.adb_uninstall = 1;
        char temporal1[100] = "sudo ./android-platform-tools/adb -s";
        printf("----\nAndroid uninstall apk from device\n");
        strcat (temporal1, device);
        strcat (temporal1, " uninstall ");
        strcat (temporal1, apk);
        system(temporal1);
        return 0;}

int adb_copy_to_local(char device[30], char file_android[100], char file_host[100]){
	cache.adb_copy_to_local = 1;
        char temporal1[200] = "sudo ./android-platform-tools/adb -s ";
	strcat(temporal1, device);
	strcat(temporal1, " pull ");
	strcat(temporal1, file_android);
	strcat(temporal1, file_host);
	system(temporal1);
	return 0;}

int adb_copy_to_device(char device[30], char file_android[100], char file_host[100]){
       	cache.adb_copy_to_device = 1;
        char temporal1[200] = "sudo ./android-platform-tools/adb -s ";
       	strcat(temporal1, device);
       	strcat(temporal1, " push ");
        strcat(temporal1, file_host);
       	strcat(temporal1, file_android);
       	system(temporal1);
       	return 0;}

int adb_backup_function(char device[30]){
	cache.adb_backup = 1;
        char temporal1[180] = "sudo ./android-platform-tools/adb -s ";
	strcat(temporal1, device);
	strcat(temporal1, " backup -f backup_android -apk -obb -shared -system -all");
	system(temporal1);
	return 0;}

int adb_shell(char device[30]){
	cache.adb_shell = 1;
        char temporal1[180] = "sudo ./android-platform-tools/adb shell -s ";
	strcat(temporal1, device);
	system(temporal1);
	return 0;}

int photorec(char dev[9]){
	cache.photorec = 1;
	printf("----\nPhotorec function initializated\nDisk to rescure data;%s", dev);
	system("sleep 2");
	char photorec_and_disk[44] = "sudo ./testdisk/photorec_static ";
	strcat(photorec_and_disk, dev);
	system(photorec_and_disk);
	return 0;}

int exiftool(){
	char temporal[200] = ".";
	strcat(temporal, "/exiftool/exiftool ");
	printf("---------\nExiftool.\n");
	printf("Image path: ");
	fgets(cache.directory_image, 300, stdin);
	strcat(temporal,cache.directory_image);
	system(temporal);
	return 0;
}

int check_user(){
	if ( geteuid() == 0 ) { printf("Using root privilegies\n");return (cache.is_root = 0); }
	printf("You are not root\n");
	return (cache.is_root = 1);
}

/* In future versions I will atach support for RAW sockets.*/

int socket_client(char protocol){
	/* Struct for sockets and their bridge vars*/
	struct addrinfo hints, *res;
	int a, send_file, recv_file, msg_len;
	char buffer[7000];
	printf("\nSocket function initializated \n");
	hints.ai_family = AF_UNSPEC;
	printf("IPv6 / IPv4 unspec\n");
	getaddrinfo("google.com", "443", &hints, &res);
	if (protocol == 'U'){ a = socket(PF_INET, SOCK_DGRAM, 0); printf("Opening UDP socket\n"); }
	else { a = socket(PF_INET, SOCK_STREAM, 0); printf("Opening TCP socket \n"); }
        if (a == -1) { printf("Error in socket\n"); return 1; }
	else { printf("Socket succesfull opened\n");}
        printf("---------------\nPlease insert the messege to send to target: \n");
        scanf("%s", buffer);
        printf("\n\nConnecting to target and sending messege\n");
        connect(a,res->ai_addr, res->ai_addrlen);
        if (a == -1){
			printf("Error in socket\n Closing socket\n");
			close(a);
			return 1;}
        msg_len = strlen(buffer);
        send_file = send(a, buffer, msg_len, 0);
        if (send_file == -1){
			printf("Error in sending \nClosing socket\n");
			close(a);
			return 1; }
        printf("Waiting answer ...\n");
        recv_file = recv(a, buffer, 7000, 0);
        switch(recv_file){
                case(-1+0):
			printf("Error in recv \nClosing socket\n");
			close(a);
			break;
                case(0+0):
			printf("The target close the conecttion \nClosing socket\n");
			close(a);
			break;
                default:
			printf("%s \n", buffer);
			close(a);
			break;}
	return 0;
        /*pthread_exit(NULL);*/ }


/* Clone the package "a" from the repository in the struct.*/
void clone(char a[10]){
	char *b = malloc(strlen(cache.repository) + 20);
	strcpy(b, "git clone ");
	strcat(b, cache.repository);
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
	return strcpy(cache.repository, b);
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
	    cache.docker_function = 1;
		printf("Building dockerfile, please wait....\n");
		strcpy(c, "docker build -t ");
		strcat(c, b);
		strcat(c, " .");
		system(c);
		printf(" \n Dockerfile installed. If you wish list your images please type: 'docker images' \n");
		break;
    case (2 + 0):
        cache.docker_function = 2;
		printf("\n \t Listening docker images: \n");
		system("docker images");
		printf("\n \n If you wanna start some of that please type; 'docker run -i -t [IMAGE ID] /bin/bash' \n");
		break;
	}

}

