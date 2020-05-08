// First Programming Task
- Checks to see if input is exit, and if so, it quits out by returning 0.
- If input is anything else, you fork(), and if the fork() returns a nonzero, you make
	the parent wait (using waitpid).
- When fork returns 0, you use the execve, calling the hello program, which prints
	out "Hello World!"


// Second Programming Task
- For loop to run 8 times.
- Forks, and if it returns nonzero, you make the parent wait and make the code break
	because we don't want any process to have more than two child processes,
	but I made it so that each parent would only have one child process each.
- If it returns 0, you print the parent and child ID's.


// Third Programming Task:
- Keep track of height with the maximum height being 3. Height starts off at 1.
- Max children is 3.
- Fork and if the fork returns 0, print the parent and child ID's as well as
	increment the height and restart i for the child process.
- If fork returns a nonzero, make parent wait.
- If height reaches or exceeds max height, go back to parent process.


// Fourth Programming Task:
- Keeps track of height and makes sure it doesn't pass a height of four,
	starting off with the inital parent process with a height of one.
- Made cases for each position essentially; height, which keeps track of it going up
	and down, and then change i to keep track of how the for loop and going
 	horizontally in the graph. Each case will set the amount of children
	to determine how many times to run the for loop for each process.
- Used a flag to have the first child process to create two children processes that
 	create three children each. This is a one time case.
- At end of for loop, restart i for child process.
- If height reaches or exceeds max height, go back to parent process.


// Testing:
- While writing the code, I added statements to print the parent and child ID's
	that were being created to know what's going on at each step.
- I also kept the printing of the parent and child processes and drew the graph
	out to make sure that the graph follows the description of each task.
