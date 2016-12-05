#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


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
					printf("Ciao il mio PID e' %d Sono il processo Fato\n",getpid());
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
	return 0;
}
