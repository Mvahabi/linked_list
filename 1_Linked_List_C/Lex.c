/*
Mahyar Mike Vahabi
mvahabi
Winter 22 - CSE101
pa1 - Lex.c - File Input/Output
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>
#include "List.h"
#define MAX_LEN 300

// Citation: Professor Tantalo's prompt for FileI/O

int main(int argc, char* argv[]){

    int line_count;
    FILE *in, *out;
    char line[MAX_LEN];
    List in_order = newList();
    int item, data;
    // check command line for correct number of arguments
    if(argc != 3){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    // open files for reading and writing 
    in = fopen(argv[1], "r");
    if(in==NULL){
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }

    out = fopen(argv[2], "w");
    if(out==NULL){
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }

    // read each line of input file,count lines, fill in tokens in the array
    line_count = 0;
    while(fgets(line, MAX_LEN, in) != NULL)  {
        line_count++;
    }

    // close and reopen now that we have line counts
    fclose(in);
    in = fopen(argv[1], "r");  
  
    // copy the tokens from line to our buffer; dynamically allocate our buffer size with the size of line 
    int lineSize = 0;
    int lines = 0;
    char* buff[line_count];
    while (fgets(line, MAX_LEN, in) != NULL) {
        lineSize = strlen(line);
        buff[lines] = (char *) malloc (sizeof(char) * (lineSize + 1));
        strcpy(buff[lines], line);
        lines++;
    }

    // start organizing in order:
    // iterate through the line count; set cursor on the front of the list
    // iterate through the list as long as cursor position is correct; then get the cursor index element
    // compare if the buffer's data at the cursor index is less than the buffer with loop index
    // if cursor index is out of place, set the element of the loop index at the back
    // if the comparison between the loop index and curser index was vise versa, check if cursor index is 0
    // then set that loop index element at the front; if cursor index is higher, insert it before the cursor
    data = 0;
    append(in_order, 0);
    for (int iter = 1; iter < lines; iter++) {
        moveFront(in_order);
        while (index(in_order) > -1) {
            data = get(in_order);
            if (strcmp(buff[iter], buff[data]) > 0) {
                moveNext(in_order);
                if (index(in_order) < 0) {
                    append(in_order, iter);
                }
            } else {
                if (index(in_order) == 0) {
                    prepend(in_order, iter);
                } else {
                    insertBefore(in_order, iter);
                }
                break;
            }
        }
    }
    
    // print out the list items to out
    moveFront(in_order);
    while (index(in_order) > -1)
    {
        item = get(in_order);
        fprintf(out, "%s", buff[item]);
	moveNext(in_order);
    }   

    // close files and free the list
    freeList(&in_order); 
    in_order = NULL;
    fclose(in);
    fclose(out);

    return 0;
}
