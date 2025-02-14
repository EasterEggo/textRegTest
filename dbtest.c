#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define DATA "registers.data"
#define MAX_MEM 256
FILE *TABLE;

int ls() {
  TABLE = fopen(DATA, "r");
  if(TABLE == NULL) {
    printf("ERROR! File not found");
    return 1;
  }
  char *text = malloc(sizeof(text));
  while(fgets(text,sizeof(text), TABLE) != NULL){
    printf("%s", text);
  }
  fclose(TABLE);
  free(text);
  return 0;
}
int wrt() {
  TABLE = fopen(DATA, "a");
  char *input = malloc(MAX_MEM);
  printf("write the data separated by spaces:");
  fgets(input, MAX_MEM, stdin);
  fputs(input, TABLE);
  printf("successfully appended data!\n");
  printf("-------------------- %s --------------------\n", DATA);
  fclose(TABLE);
  free(input);
  ls();
  return 0;
}
int del() {
  TABLE = fopen(DATA, "w");
  if(TABLE == NULL) {
    printf("ERROR! File not found");
    return 1;
  }
  fputs("", TABLE);
  fclose(TABLE);
  return 0;
}
int edit() {
  printf("edit function\n");
  
  if (system(NULL)){
    system("vim registers.data");
  }
  else {
    printf("ERROR! Command processor doesn't exist");
  }
  return 0;
}
int help() {
  printf("dbtest.c - v0.0.1\ntool for editing a "
         "file\n---\nwrite	write a register to the file\nclear	clear "
         "the file\nedit	edit the "
         "file\nls	list the entries of the file");
  return 0;
}

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "write") == 0) {
    wrt();
  } else if (strcmp(argv[1], "clear") == 0) {
    del();
  } else if (strcmp(argv[1], "edit") == 0) {
    edit();
  } else if (strcmp(argv[1], "help") == 0) {
    help();
  } else if (strcmp(argv[1], "ls") == 0) {
    ls();
  } else {
    printf("ERROR! Command not found\n\n");
    help();
    return 1;
  }
  return 0;
}
