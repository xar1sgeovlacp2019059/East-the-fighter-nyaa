#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){ // input: argc=argument counter, argv=argument vector, argv[0] is the name of the program, argv[1] is the name of first file the first file
 char ch;
 FILE *fp;
 //FILE *gp;
 if(argc <2){
 printf("give a filename\n");
 return 1;
 }

 if (access(argv[1], F_OK)== -1){ //file does not exist
  printf("file %s does not exist\n",argv[1]); //file does not exist

 }

 fp=fopen(argv[1],"r"); // open the file to read
 while((ch = fgetc(fp)) != EOF){ //until end of file
   printf("%c",ch);// show every char
 }

 fclose(fp);

 return 0;
}