#include <stdio.h>
#include <unistd.h>

int main()
{
	int status;	

	int i;	

	for(i=0; i<8; ++i){
		// Forks and if returns nonzero, wait
		if(fork() != 0){
			waitpid(-1, &status, 0);
			break;
		} else {
			// Print the parent and child ID's
			printf("Parent is...%d Child is....%d\n",  getppid(), getpid());
		}
	}

	return 0;
}
