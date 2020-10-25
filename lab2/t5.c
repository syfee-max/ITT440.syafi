#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



void child(){
    char name[30];
    printf("\n Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("\nHello ");
	puts(name);
    printf("Child process => PPID=%d, PID=%d \n\n", getppid(), getpid());
	exit(0);
}

void parent(){
    printf("Parent Process => PID==%d\n", getpid());
    printf("All child process complete\n");
    printf("Job is done\n");
}

void waiting(){
      printf("Waiting for child process\n");
      wait(NULL);
      printf("Child process complete\n");

}

int main(void){
    for(int i = 1; i < 5; i++){
	    pid_t pid = fork();
	    if(pid == 0){
	        child();
	    }else if(i == 4){
	        waiting();
	        parent();
                }else waiting();
    }
    return EXIT_SUCCESS;
}