#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    // If file name was not provided, then exit
    if(argc != 2){
        printf("File Name Expected.\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *file;
    file = fopen(argv[1], "r");
    
    // If there is an error in opening the file
    if(file == NULL){
        printf("Error in opening file!\n");
        exit(EXIT_FAILURE);
    }
    
    char * myStr = NULL;
    size_t len = 0;
    ssize_t read;
    
    while((read = getline(&myStr, &len, file)) != -1);
    fclose(file);
    if(myStr)
        free(myStr);
    exit(EXIT_SUCCESS);
}
