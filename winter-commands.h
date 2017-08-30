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
        printf(ANSI_COLOR_CYAN "4 - List Android devices with adb\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "5 - Install an APK throught adb\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "6 - Copy file from Android to PC Host\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "7 - Copy file from Host to Android device\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "8 - Uninstall an APK\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "s - Shutdown system\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "r - Reboot system\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "< - Exit of Winter-terminal\n" ANSI_COLOR_RESET);

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
		adb_listen();
		break;}
	case ('5'): {
		char path[100], device[30];
		printf("Insert the path of the apk: ");
		fgets(path, 100, stdin);
		printf("What is the name of the device?: ");
		fgets(device, 30, stdin);
		adb_install(device, path);
		break;}
	case ('6'): {
		char device[30], file_android[100], file_host[100];
                printf("What is the name of the device?: ");
               	fgets(device, 30, stdin);
		printf("Insert the path of file in the Android: ");
		fgets(file_android, 100, stdin);
		strcat(file_android, " ");
		printf("Insert the path where the file will be saved: ");
		fgets(file_host, 100, stdin);
		adb_copy_to_local(device, file_android, file_host);
		break;}
	case ('7'): {
		char device[30], file_android[100], file_host[100];
                printf("What is the name of the device?: ");
                fgets(device, 30, stdin);
               	printf("Insert the path where the file will be in the Android: ");
               	fgets(file_android, 100, stdin);
               	printf("Insert the path of the fail: ");
               	fgets(file_host, 100, stdin);
                strcat(file_host, " ");
               	adb_copy_to_device(device, file_android, file_host);
               	break;}
       	case ('8'): {
               	char apk[100], device[30];
                printf("Insert the full name of the apk: ");
               	fgets(apk, 100, stdin);
                printf("What is the name of the device?: ");
               	fgets(device, 30, stdin);
               	adb_remove(device, apk);
               	break;}
	case ('s'): {
		system("sudo shutdown -t 0");
		break;}
	case ('r'): {
		system("sudo shutdown -r -t 0");
		break;}
	case ('h'): { help(); break;}
	case ('<'): {return 0; break;}
        default: {
		system(comand);
		break; }}}
}

