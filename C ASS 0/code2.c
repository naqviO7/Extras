#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int a=0, b=1, n=a+b,range;
    double time_spent=0.0;
    pid_t pid;

    clock_t begin = clock();

    printf("Enter Number for Fibonacci: ");
    scanf("%d", &range);
	
	pid = fork();
    if (pid == 0) {
        printf("[!] Child Process\n");
        sleep(2);

        printf("[!] Fibonacci Sequence: ");
        for (int i=0;i<range;i++){
            n=a+b;
            printf("%d ", n);
            a=b;
            b=n;
        }
        printf("\n[!] Child Ends\n"); 
      	sleep(2);
    }
    else {
    	printf("[!] Parent Waiting for Child to End\n");
        wait(NULL);
        sleep(2);
        
        printf("[!] Parent Ends\n");
    	sleep(1);
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("[!] Execution Time %f seconds\n", time_spent);

    return 0;
}
