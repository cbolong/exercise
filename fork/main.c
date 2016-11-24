#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	//pipe[0] => READ   pipe[1] => WRITE
	int pi[2];
	char buf[80];
	int i = 0;
	printf("I am the Top, ID is %d , Parent ID is %d\n", getpid(), getppid());
	
	pipe(pi);
	//Check fork pid and ppid 
	if(0)
	{
		for(i=0;i<2;i++)
		{
			pid_t fpid = fork();
			
			if(fpid < 0)
				printf("fork fail\n");
			else if(0 == fpid)
				printf("I am the child process, Count is %d , ID is %d , Parent ID is %d , fork id is %d\n", i, getpid(), getppid(), fpid);
			else
				printf("I am the parent process, Count is %d , ID is %d , Parent ID is %d , fork id is %d\n", i,getpid(), getppid(), fpid);
		}
	}
	
	//Send message to child process from parent process by using pipe
	//pipe : communication by two process
	//
	if(1)
	{
		pid_t fpid = fork();
		
		if(fpid < 0)
			printf("fork fail\n");
		else if(0 == fpid)
		{
			printf( "This is in the child process, read a string from the pipe.\n" );
			read( pi[0], buf, sizeof(buf) );
			printf( "%s\n", buf );
			close( pi[0] );
			close( pi[1] );
		}
		else
		{
			printf( "This is in the father process, write a string to the pipe.\n" );
			char s[] = "Message , write by pipe.\n";
			write( pi[1], s, sizeof(s) );
			close( pi[0] );
			close( pi[1] );
		}
	}
	
	return 0;
}
