#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>


int squadra(int squadra, pid_t padre){		
	int i,n_giocatori=5;
	pid_t child_pid;
	pid_t list_pid[n_giocatori];
	for (i=0; i<n_giocatori; i++) {
		switch (child_pid = fork()) {
			case -1:
			/* Handle error */

			case 0:
				/*Figlio*/
				printf("Ciao il mio PID e' %d Sono della squadra %d\n",getpid(),squadra);
				exit(i);
				break;

			default:
				/*Padre*/
				printf("Ciao sono la squadra %d e un giocatore e' :%d Il mio PID e': %d\n",squadra,child_pid,getpid());
				list_pid[i]=child_pid;               
				break;
		}	
	}

    while (waitpid(WAIT_ANY, NULL, WUNTRACED | WCONTINUED | WNOHANG) != -1)
    {
    
    }
}


int main(){
	pid_t child_pid;
	pid_t list_pid[2];
	int num_proc=2;
	int num_squadra=0;
	int i;
	for (i=0; i<num_proc; i++) {
		switch (child_pid = fork()) {
			case -1:
			/* Handle error */

			case 0:
				/*Figlio*/
				printf("Ciao il mio PID e' %d Sono una squadra\n",getpid());
				squadra(i, getpid());
				exit(i);
				break;

			default:
				/*Padre*/
				printf("Ciao sono il padre e mio figlio e' :%d Il mio PID e': %d\n", child_pid,getpid());
				list_pid[i]=child_pid;
                int j;
                /*for(j = 0; j < num_proc; j++){
                    waitpid(list_pid[j], NULL, 0);
                }*/                
				break;
		}	
	}
    while (waitpid(WAIT_ANY, NULL, WUNTRACED | WCONTINUED | WNOHANG) != -1)
    {
    
    }
	return 0;
}


