#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int page_frame = atoi(argv[1]);

	int i;
	int key;
	int works = 1;		// 0 if number is in page frame, 1 if not
	int count = 0;
	int page_faults = 0;
	int A[100];
	int B[100];

	// Making sure all items in arrays are set to 0
	for(i=0;i<100;i++){
		A[i] = 0;
		B[i] = 0;
	}

	// Goes through file
	while(scanf("%d",&key)!= EOF){
		works = 1;
		// If array already holds the input
		for(i=0;i<page_frame;++i){
			if(A[i] == key){
				works = 0;
				B[i] = 1;
				i = page_frame;
			}
		}
		
		// If array doesn't hold the input
		while(works > 0){	
				if(B[count] == 1){
					B[count] = 0;
					count++;
					count = count % page_frame;
				}
				else{		
					A[count] = key;
					B[count] = 0;
					page_faults++;
					printf("%d\n",key);
					count++;
					count = count % page_frame;
					works = 0;
				}
		}
		
	}
	printf("%d\n", page_faults);
	return 0;
}

