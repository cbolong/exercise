#include <stdio.h>
void star()
{
	int i,a,b	;
	i = 5;

	//scanf("%d",&i);
	
	for(a=1;a<=i;a++)
	{
		printf("\n");
		for(b=1;b<=a;b++)
		{
			printf("*");
		}
	}
	printf("\n");
	
	int space = i;
	int total = 0;	
	int row = 0;
	
	for(row=1; row<=i; row++)
	{
		//print space
		for(a=1; a<space; a++)
		{
			printf(" ");
		}
		space--;
		for(b=1; b<=(row*2-1); b++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
}

int main(void)
{
	if(1)
	{
		star();
	}
	
	
    return 0;
}