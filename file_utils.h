#include <stdio.h>

/*******************************************************
* This function reads a file and stores the contents in
* memory. *buffer points to these contents.
* @param filename - The name of the file being reads
* @param buffer - a pointer to a pointer of the memory
* location where the file contents are being stored.
* @return - 0 upon failure, file size upon successful
********************************************************/
int read_file(char* filename, char** buffer);

/*******************************************************
* This function writes to file the contents of buffer to
* an output file with the name "filename"
* @param filename - The name of the file being written to
* @param buffer - a pointer to the information being written
* to the file.
* @return - 0 upon failure, 1 upon success
********************************************************/
int write_file(char* filename, char *buffer, int size);
