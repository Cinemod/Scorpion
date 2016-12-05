#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(){

	pid_t child_pid;
	int num_proc=2;
	int i;
	for (i=0; i<num_proc; i++) {
		switch (child_pid = fork()) {
			case -1:
			/* Handle error */

			case 0:
				/* Perform actions specific to child */
				printf("Ciao il mio PID e'%d e sono una squadra\n",getpid());
				exit(i);
				break;

			default:
				/* Perform actions specific to parent */
				printf("Ciao sono il padre e mio figlio e' :%d Il mio PID e': %d\n", child_pid,getpid());
				break;
		}	
	}
	return 0;
}
