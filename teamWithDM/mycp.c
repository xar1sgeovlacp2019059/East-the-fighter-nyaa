#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){ // input: argc=argument counter, argv=argument vector, argv[0] is the name of the program, argv[1] is the name of first file the first file
 int i=1; // identifier
 char ch;
 char* buff;
 char* cbuff = argv[1];
 int buffsize;
 FILE *fp;
 FILE *gp;
 
 if((cbuff[0]=='-') && (cbuff[1]=='b')){
 
  cbuff=memmover(cbuff, cbuff+2, strlen(cbuff));
  buffsize= atoi(cbuff);
  i=i+1;
 }
 
 if(argc <i+1){
 printf("give a filename\n");
 return 1;
 }
 
 if (access(argv[i], F_OK)== -1){ //file does not exist
  printf("file %s does not exist\n",argv[i]); //file does not exist

 }

 fp=fopen(argv[i],"r"); // open the file to read
 gp=fopen(argv[i+1],"w");
 while((ch = fgetc(fp)) != EOF){ //until end of file
   fprintf(gp,"%c",ch);// show every char
 }
 fclose(gp);
 fclose(fp);

 return 0;
}
