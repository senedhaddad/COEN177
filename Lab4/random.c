#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    // If file name wasn't provided, then exit
    if(argc != 3){
        printf("File Name and File Size Expected.\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *file;
    file = fopen(argv[1], "r");	// Opens file that is in the Linux command
    
    // If there is an error in opening the file
    if(file == NULL){
        printf("Error in opening file!\n");
        exit(EXIT_FAILURE);
    }
    
    unsigned long long size = atoi(argv[2]);	// Given size to read randomization
    unsigned long long bitRead = 0;
    
    
    
    char * myStr[1024];
    memset(&myStr, '0', 1024);
    while(bitRead < size){
        fseek(file, rand()%(size-1024), SEEK_SET);
        bitRead += 1024;							// Updating how many bits have been read
        fread(myStr, sizeof(myStr[0]), 1024, file);
        
    }
    fclose(file);
    exit(EXIT_SUCCESS);
}
