#include <pthread.h>    /* Posix Threads */
#include <stdio.h>	/*Standar */
#include <stdlib.h>     /* Systemcalls and other linux things */
#include <string.h>     /* Strings*/
#include "winter-lib.h" /*for all functions */
#include <time.h>	/*Time support */


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int loop(){
	char *command;
        while (1 != 0){
        command = malloc(300);
        if (command == NULL){ return 1;}
        printf(ANSI_COLOR_GREEN "> " ANSI_COLOR_RESET);
        fgets(command, 299, stdin);
        switch(command[0]){
        case ('-'): {command[0] = ' '; system(command); break;}
        case ('<'): {return 0; break;}
        case ('w'): {cache.len_winter_interpreter= strlen(command); winter_interpreter(command); break;}}
        free(command);}
}

int main(){
	system("clear");
        printf(ANSI_COLOR_CYAN "Welcome. This is a beta for Winter Terminal. The Suite_winter is development by Joaquin Crespo (ShyanJMC). \nVersion 0.1\nThis program and all Suite_winter is under GPLv3.\n\n\n" ANSI_COLOR_RESET);
        loop();
        return 0; }

