#include <stdio.h>

int fib(int i)
{
	if(i==0)
		return 0;
	if(i==1)
		return 1;
	return (fib(i-1)+fib(i-2));
}

int main(void)
{
	int i = 10;
	if(1)
	{
		for(i=0; i<=10; i++)
		{
			printf("[%d]\n",fib(i));
		}
		
	}
    return 0;
}