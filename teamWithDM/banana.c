#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]){
 int fd[2]; 
 if (pipe(fd) ==-1){
  return 1;
 }
 int pid1 = fork();
 if (pid1 <0 ){
  return 2; 
 }
 
 if (pid1 == 0){ // process(child) cat
  dup2(fd[1], STDOUT_FILENO);// 
  close(fd[0]);
  close(fd[1]);
  
  char* fl1 = (char*)NULL;// 
  int len1 = strlen(argv[1]); 
  
  if ((fl1 = malloc(len1+1)) != NULL){
    bzero(fl1, len1+1);
    strncpy(fl1, argv[1], len1);
   }
  execlp("cat","cat",fl1, NULL);
 
 }
 
 int  pid2 =fork();
 if (pid2 <0){
  return 3;
 }
 
 if (pid2 ==0){
  dup2(fd[0], STDIN_FILENO);
  close(fd[0]);
  close(fd[1]);
  // new
   char *ar1=malloc(sizeof(char)+1);
   char *ar2=malloc(sizeof(char)+1);
   char *full=malloc(sizeof(char)+2);
   char *file=malloc(sizeof(char)+1);
   strcpy(full,"s/");
   char *buffer;
   char command[512];
   int i = 1;
   for(i = 1; i < argc; i++){
     buffer = malloc(strlen(argv[i]) + 5);
     strcpy(buffer,argv[i]);
     if(i==1){
      strcpy(file,buffer);
     }else if(i==2){
      strcat(buffer,"/");
      strcpy(ar1,buffer);
      
     }else if(i==3){
      strcat(buffer,"/g");
      strcpy(ar2,buffer);
     }
     
     free(buffer);
  }
   //printf("%s, %s, %s\n",full,ar1, ar2);
   strcat(ar1,ar2);
   //printf("%s \n",ar1);
   free(ar2);
   strcat(full,ar1);
   
   //printf("%s \n",full);
  //new  
  execlp("sed", "sed","-e","s/^/Data received through pipe /g","-e",full,file, NULL);
 }
 close(fd[0]);
 close(fd[1]);
 
 waitpid(pid1, NULL, 0);
 waitpid(pid2, NULL, 0);
 
 return 0;
}
