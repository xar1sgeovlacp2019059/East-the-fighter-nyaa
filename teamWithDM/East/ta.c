#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc, char* argv[]) {

 int fd[2]; 
 char buffer[4096];
  if (argc >4){
   return 3;
  }
  if (pipe(fd) ==-1){
   printf("problem occured while opening the file");
   return 1;
  }
 
  int  pid2 =fork();// create a child procces
  if (pid2 <0){
   return 2; // if pid2==-1 
  }
  if (pid2 ==0){ // child procces 
   dup2(fd[1],STDOUT_FILENO);// parent takes std_out of child
   close(fd[0]);// we don't need to read or write anithing
   close(fd[1]);
   char *ar1=malloc(sizeof(char)+1);
   char *ar2=malloc(sizeof(char)+1);
   char *full=malloc(sizeof(char)+2);// from argv to string cause sed needs them
   char *file=malloc(sizeof(char)+1);
   strcpy(full,"s/");// sizeof(char)+2
   char *buf; //another buffer, but for certain work
   int i = 1;
   for(i = 1; i < argc; i++){
     buf = malloc(strlen(argv[i]) + 5);
     strcpy(buf,argv[i]);
     if(i==1){
      strcpy(file,buf);
     }else if(i==2){
      strcat(buf,"/");
      strcpy(ar1,buf);
      
     }else if(i==3){
      strcat(buf,"/g");
      strcpy(ar2,buf);
     }
     
     free(buf);
  }
   //printf("%s, %s, %s\n",full,ar1, ar2);
   strcat(ar1,ar2);
   //printf("%s \n",ar1);
   free(ar2);
   strcat(full,ar1);
   execlp("sed", "sed","-e","s/^/Data received through pipe /g","-e",full,file, NULL);
   
  }else{
   
   close(fd[1]);
   
   read(fd[0],buffer,sizeof(buffer));// read the std_out and save it to buffer
   printf("%s\n",buffer);
   waitpid(pid2, NULL, 0); // wait for child procces to finish
  }
  
  
  
  return 0;
}
