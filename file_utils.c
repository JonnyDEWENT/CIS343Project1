#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>


/*******************************************************
* This function reads a file and stores the contents in
* memory. *buffer points to these contents.
* @param filename - The name of the file being reads
* @param buffer - a pointer to a pointer of the memory
* location where the file contents are being stored.
* @return - 0 upon failure, file size upon successful
********************************************************/
int read_file(char* filename, char** buffer){

// retrieving file size
  struct stat st;
  stat((filename), &st);
  int size = st.st_size;
// borrowed from woodring cis 343 project 1 description

// opening file
  FILE *file = fopen(filename,"r");

// reading file into buffer
  if(file != NULL){
    *buffer = malloc(size * sizeof(char*));
    fread(*buffer,size+1,1, file);
    fclose(file);

    // return size after file is read
return size;
}

// if file doesn't exist return 0
  return 0;
}

/*******************************************************
* This function writes to file the contents of buffer to
* an output file with the name "filename"
* @param filename - The name of the file being written to
* @param buffer - a pointer to the information being written
* to the file.
* @return - 0 upon failure, 1 upon success
********************************************************/
int write_file(char* filename, char *buffer, int size) {
  // If size is 0 return
  if(!size)
    return 0;
    //opening file
  FILE *file = fopen(filename,"w");
  //writing buffer to file
  for(int i = 0; i < size; i++) {
    fputc(*(buffer+i), file);
  }
  //closing file after successful write
  fclose(file);
  return 1;
}
