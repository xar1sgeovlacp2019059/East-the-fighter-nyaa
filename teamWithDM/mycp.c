#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int mode(int i, char* cbuff){
 if ((cbuff[0]=='-') && (cbuff[1]=='b')){
  i=i+1; 
 }
 return i;
}

int buffsize(char* cbuff){

 int buffsize;
 cbuff = memmove(cbuff, cbuff+2, strlen(cbuff));
 buffize = atoi(cbuff);
 
 return buffsize;
}


int main(int argc, char **argv){ // input: argc=argument counter, argv=argument vector, argv[0] is the name of the program, argv[1] is the name of first file the first file

 clock_t timing;
 int i=1; // identifier
 char* buff;
 int buffsize;
 int file1;
 int file2;
 char ch;
 int bytes=0;
 int readchar;
 FILE *fp;
 FILE *gp;
 

 i=mode(i,argv[1]);
 if(i==2){
 
 buffsize=buffmode(argv[1]);
 buff=malloc(sizeof(char) * buffsize);
 }
 
 
 if(argc <i+1){
 printf("give a filename\n");
 return 1;
 }
 
 if (access(argv[i], F_OK)== -1){ //file does not exist
  printf("file %s does not exist\n",argv[i]); //file does not exist
  return 2;
 }

 if(i==2){
  file1=open(argv[i], O_RDONLY);
  file2=open(argv[i+1], O_WRONLY | O_CREAT , 0644);
 
  timing=clock();// time start
  while((readchar=read(file1,buff,buffsize)) > 0){
   if((write(file2, buff, readchar)) > readchar){
    
    return 0;
   }
   bytes=bytes+readchar;
  }
  bytes=bytes-1;
  timing=clock() - timing;//timer stop
  
  close(file2);
  close(file1);
 }
 
 if(i==1){
  fp=fopen(argv[i],"r"); // open the file to read
  gp=fopen(argv[i+1],"w");
  while((ch = fgetc(fp)) != EOF){ //until end of file
   fprintf(gp,"%c",ch);// show every char
  }
  fclose(gp);
  fclose(fp);
 }
 return 0;
}
