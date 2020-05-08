#include <stdio.h>

int main(){
	
	int status;
	int i;
	int maxHeight  = 3; 	// Max height of graph can't pass 3
	int height = 1;		// Height will start off at 1
	int children = 3;	// Children max is 3

	for(i = 0; i < children; ++i)
	{
		if(fork() == 0){
			printf("Parent is...%d Child is....%d\n",  getppid(), getpid());
			height++;	// Update height because of the fork
			i = -1;		// There was a fork so change i
		} else {
			waitpid(-1, &status, 0);
		}
	if(height >= maxHeight) 	// If reaches max height, go back to parent
		return 0;	
	}
}
