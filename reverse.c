#include "file_utils.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(int argc, char** argv){

// Declaring buffer variable for storing file data
  char* buffer;

// Reading file into buffer
  int readSuccess = read_file(argv[1], &buffer);

// true if successful read
  if(readSuccess){

    // allocating memory for reverseBuffer
    char* reverseBuffer = malloc(readSuccess * sizeof(char));

    // Storing the reverse of buffer in reverseBuffer
    for(int i = 1; i <= readSuccess; i++) {
      *(reverseBuffer + i -1) = *(buffer + readSuccess -i);
    }

// writing reverseBuffer in output file
    int writeSuccess = write_file(argv[2], reverseBuffer,readSuccess);

  // true if the write was not successful
    if(!writeSuccess){
      perror("Can't write a file with size 0\n");
    }
    // freeing memory for buffers
    free(reverseBuffer);
    free(buffer);
 }
 else{
   perror("Failed to read file\n");
 }

 return 0;
}
