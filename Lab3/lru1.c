#include <stdio.h>
#include <stdlib.h>

int lru(int time[], int n){
	int i;
	int min = time[0];
	int j = 0;

	for(i = 1; i < n; ++i){
		if(time[i] < min){
			min = time[i];
			j = i;
		}
	}
	return j;
}

int main(int argc, char* argv[]){
	
	int page_frame = atoi(argv[1]);
	int i;
	int key;
	int works = 0;			// Acts as boolean for when key is NOT in page table
	int empty = 0;			// Acts as boolean for when key is in page table
	int count = 0;
	int page_faults = 0;
	int A[page_frame];
	int time[page_frame];
	int j;
	int pos = 0;
	int minimum;

	for(i=0;i<100;i++){
		A[i] = -1;
	}

	while(scanf("%d",&key)!= EOF){

		works = 0;
		empty = 0;
		for(i = 0; i < page_frame; ++i){
			if(A[i] == key){
				count++;
				time[i] = count;
				works = 1;
				empty = 1;
				break;
			}
		}
	
		if(works == 0){ 					// If key isn't in page table
			for(i = 0; i < page_frame; ++i){
				if(A[i] == -1){
					count++;
					page_faults++;
					A[i] = key;
					printf("%d\n",key);
					time[i] = count;
					empty = 1;
					break;
				}
			}
		}
			
		if(empty == 0){ 					// If key is in page table
			pos = lru(time, page_frame);	// Call LRU to update time
			page_faults++;
			count++;
			A[pos] = key;
			printf("%d\n",key);
			time[pos] = count;
		}
	}
	
	printf("%d\n", page_faults);
	return 0;
}


