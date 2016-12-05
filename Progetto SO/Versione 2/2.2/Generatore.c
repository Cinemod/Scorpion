#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>

#define FILENAME "settings.cfg"

void leggiFile();
int main(){

	pid_t child_pid;
	pid_t list_pid[3];
	int num_proc=3;
	int num_squadra=0;    
	int i;
	for (i=0; i<num_proc; i++) {
		switch (child_pid = fork()) {
			case -1:
			/* Handle error */

			case 0:
				/*Figlio*/
				
				if(i==0){
					/*Processo Fato*/
                    int tempo;                       
                    int giocata[3];
					printf("Ciao il mio PID e' %d Sono il processo Fato\n",getpid());
                    leggiFile(&tempo, giocata);
				}
				else{
					/*Squadre*/
					printf("Ciao il mio PID e' %d Sono una squadra\n",getpid());
				}
				exit(i);
				break;

			default:
				/*Padre*/
				printf("Ciao sono il padre e mio figlio e' :%d Il mio PID e': %d\n", child_pid,getpid());
				list_pid[i]=child_pid;
				break;
		}	
	}
    while (waitpid(WAIT_ANY, NULL, WUNTRACED | WCONTINUED | WNOHANG) != -1){
    
    }
	return 0;
}

void leggiFile(int* tempo, int* giocata){
    char s [30];
    FILE * fp;
    fp = fopen (FILENAME, "r");
    /*Tempo*/
    fgets(s, 30, fp);
    printf("Tempo: %s secondi \n", s);
    *tempo = atoi(s); 
   
    /*Giocata*/ 
    int i;
    char* token;
    fgets(s, 30, fp);
    /*Split*/
    token = strtok(s, ";");
    while (token != NULL){        
        *(giocata + i) = atoi(token);
        printf("%d\n", *(giocata + i));
        token = strtok(NULL, ";");
        i++;
    }   

    fclose(fp);
}