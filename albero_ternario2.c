#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define N 3

int livello=1;

int main(int argc,char *argv[])
{

	pid_t pid[N];
	int i=0;


	for(i=0;i<N;i++)
		{
		if((pid[i]=fork())==0)
				{
				pid_t pidi[N];
				int j;
				livello=2;
				for(j=0;j<N;j++)
				{
				if((pidi[i]=fork())==0){
				printf("Concludo %d figlio di %d tra %d secondi\t",getpid(),getppid(),livello);
				
				sleep(livello);
				exit(3);
				}
				printf("\n");
				wait(NULL);
				}
				livello=1;
				printf("Concludo %d figlio di %d tra %d secondi\t",getpid(),getppid(),livello);
				
				sleep(livello);
				exit(2);
				}
				printf("\n");
		wait(NULL);
		}
		printf("Sono il pid %d\n",getpid());
		
	exit(0);

}

