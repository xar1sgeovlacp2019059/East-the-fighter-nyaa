#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int mode(int i, char* cbuff){
 if ((cbuff[0]=='-') && (cbuff[1]=='b')){ // there we search if the mode is buffer mode
  i=i+1; 
 }
 return i;
}

int buffersize(char* cbuff){

 int buffsize;
 cbuff = memmove(cbuff, cbuff+2, strlen(cbuff)); // here we remove -b 
 buffsize = atoi(cbuff); // make string to int
 
 return buffsize;
}


int main(int argc, char **argv){ // input: argc=argument counter, argv=argument vector, argv[0] is the name of the program, argv[1] is the name of first file the first file

 clock_t timing;
 int i=1; // identifier if i=2 -> buffer mode
 char* buff;
 int buffsize;
 int file1;
 int file2;
 char ch;
 int bytes=0;
 int readchar;
 FILE *fp;
 FILE *gp;
 

 i=mode(i,argv[1]); // the identifier(i) will show us if there is buffer mode or not
 if(i==2){
 
 buffsize=buffersize(argv[1]); // we set size mof custom buffer
 buff=malloc(sizeof(char) * buffsize);
 }
 
 
 if(argc <i+1){ // you forgot the name of file
 printf("give a filename\n");
 return 1;
 }
 
 if (access(argv[i], F_OK)== -1){ //file does not exist
  printf("file %s does not exist\n",argv[i]); 
  return 2;
 }

 if(i==2){ // copy the file with buffer mode
  file1=open(argv[i], O_RDONLY); // readonly
  file2=open(argv[i+1], O_WRONLY | O_CREAT , 0644); // write only | create if not exist write&read-read-read(owner-group-others)
 
  timing=clock();// time start
  
  while((readchar=read(file1,buff,buffsize)) > 0){ // read with buffer size
   if((write(file2, buff, readchar)) > readchar){ // write with buffer
    
    return 0;// everything is ok
   }
   bytes=bytes+readchar; //count bytes
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
   fprintf(gp,"%c",ch);
  }
  fclose(gp);
  fclose(fp);
 }
 return 0;
}
