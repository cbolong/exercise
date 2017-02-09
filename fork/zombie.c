/* zombie.c */
#include <sys/types.h>
#include <unistd.h>  
#include <stdio.h>
#include <unistd.h>
int main()
{

    pid_t pid; 

    pid=fork();

    if(pid<0) { 

        printf("error occurred!\n");

    }else if(pid==0){ 

        return 0;

    }else{ 

        sleep(60); 

        wait(NULL);

    }
	return 0;
}
