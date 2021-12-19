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
 
 if (pid1 == 0){ // process of
  dup2(fd[1], STDOUT_FILENO);
  close(fd[0]);
  close(fd[1]);
  execlp("cat","cat","one.txt", NULL);
 
 }
 
 int  pid2 =fork();
 if (pid2 <0){
  return 3;
 }
 
 if (pid2 ==0){
  dup2(fd[0], STDIN_FILENO);
  close(fd[0]);
  close(fd[1]);
  execlp("sed", "sed", "s/dao/tia/g", NULL);
 }
 close(fd[0]);
 close(fd[1]);
 
 waitpid(pid1, NULL, 0);
 waitpid(pid2, NULL, 0);
 
 return 0;
}
