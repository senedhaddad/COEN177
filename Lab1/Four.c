#include <stdio.h>

// Fourth Programming Task:
// Keeps track of height and makes sure it doesn't pass a height of four,
// 	starting off with the inital parent process with a height of one.
// Has cases for each position essentially; height, which keeps track of it going up
// 	and down, and then change i to keep track of how the for loop and going
// 	horizontally in the graph.
// Used a flag to have the first child process to create two children processes that
// 	create three children each.


int main(){

        int status;
        int i;
        int maxHeight  = 4;
        int height = 1;
        int children = 3;
	int flag = 0;

        for(i = 0; i < children; i++)
        {
		// Fork and if returns 0
                if(fork() == 0){
			// Print out ID's and update height to account for new child
                        printf("Parent is...%d Child is....%d\n",  getppid(), getpid());
                        height++;
			
			if(i==0 && height==2)
			{
				flag = 1;
				children = 2;
			}
			else if(i==0 && height==3)
			{
				children = 3;
			}
			else if(i==1 && height==3)
			{
				children = 3;
			}
                
			if(flag==0 && height==3){
                        	children = 0;
	                }
	
			i = -1;
		} else {
			waitpid(-1, &status, 0);
		}

		// If reaches maxHeight, go back to parent process
		if(height >= maxHeight)
		{
			return 0;
		}
	}
}
