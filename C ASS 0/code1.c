#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid=fork();

	if (pid==0){
		printf("[!] I am Child Process\n");
		sleep(2);

		printf("[!] Executing Bash Command\n");
		sleep(1);

		char *prog[]={"echo","I am Bash!"};
		execv("/bin/echo",prog);
	}
	else{
		printf("[!] Waiting for Child Process to End\n");
		waitpid(pid,0,0);
	}

	return 0;
}
