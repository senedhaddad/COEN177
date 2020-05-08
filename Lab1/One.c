#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char in[28];
	char x;
	int status;

	while(1)
	{
		printf("Enter something: ");
		scanf("%s", in);		
		
		// Checks to see if input is exit, if so, quits out
		if(strcmp("exit", in)  == 0)
		{
			return (0);

		}
		
		// Fork() and store value in pid
		pid_t pid = fork();
		
		// If fork() returns nonzero
		if(pid != 0)
		{
			waitpid(-1, &status, 0);
		} else {
			// Will call the print program that prints "Hello World"
			execve("hello", NULL, NULL);
		}
	}

	return 0;
}
