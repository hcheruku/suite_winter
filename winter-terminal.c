/* The program is development by Joaquin Crespo (ShyanJMC) and the program is under GPLv3*/


#include <pthread.h>	/* Posix Threads */
#include <stdio.h>	/*Standar */
#include <stdlib.h>	/* Systemcalls and other linux things */
#include <string.h>	/* Strings*/
#include "winter-lib.h" /*for all functions */
#include <time.h>	/*Time support */


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void help(){
	printf(ANSI_COLOR_CYAN "0 - Check if the user are root\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "1 - Socket function in client mode\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "2 - Exiftool. Metadata analyzer\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "3 - Photorec. The best data rescure\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "4 - Shutdown system\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "5 - Reboot system\n" ANSI_COLOR_RESET);



}
int loop(){
	char comand[300];
	while (1 != 0){
	printf(ANSI_COLOR_GREEN "> " ANSI_COLOR_RESET);
        fgets(comand, 60, stdin);
	int c= strlen(comand);
	switch(comand[0]){
	case ('0'): {
		check_user();
		break;}
	case ('1'): {
		char protocol;
		printf("What type of protocol that you will use for the socket?\nT: TCP\nU: UDP\n>:");
		scanf("%c", &protocol);
		socket_client(protocol);
		break;}
	case ('2'): {
		exiftool();
		break;}
	case ('3'): {
		char dev[9];
		printf("Type the path of the disk to rescure data: ");
		fgets(dev, 9, stdin);
		photorec(dev);
		break;}
	case ('4'): {
		system("sudo shutdown -t 0");
		break;}
	case ('5'): {
		system("sudo shutdown -r -t 0");
		break;}
	case ('h'): { help(); break;}
	case ('<'): {return 0; break;}
        default: {
		system(comand);
		break; }}}
}


int main(){
	system("clear");
	printf(ANSI_COLOR_CYAN " Winter Terminal.\n Version: 0.63.2 BETA\n GPLv3.\n\n\n" ANSI_COLOR_RESET);
	system("date");
	help();
	loop();
	return 0;
}

