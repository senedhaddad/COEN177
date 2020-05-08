#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int page_frame = atoi(argv[1]);

	int i;
	int A[100];
	int key;
	int count = 0;
	int page_faults = 0;
	int works = 1; 		// 0 if number is in page frame, 1 if not
	
	int j;

	// Making sure all items in array are set to 0
	for(j = 0; i < 100; i++)
		A[i] = 0;
	
	// Goes through file
	while(scanf("%d", &key) != EOF)
	{
		
		// Goes through array
		works = 1;
		for(i = 0; i < page_frame; ++i)
		{
			// If array holds the input, then it works and we keep track of that
			if(A[i] == key)
			{
				works = 0;
			}
				
		}
		// If array does NOT hold input, we keep track of that
		// We need to switch the input with the oldest element in the array.
		if(works == 1)
		{
			A[count] = key;
			page_faults++;		// Increments amount of page faults
			printf("%d\n", key);
			count++;		
			count = count % page_frame;
		}
	}
	
	printf("%d\n", page_faults);
	
	return 0;
}
