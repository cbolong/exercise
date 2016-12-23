#include <stdio.h>
//https://goo.gl/DGpUXy
#define SUM(x,y) x+y
#define SUM2(x,y) (x+y)

int strcmpp(char *str1, char *str2)
{
	char a = *(str1);
	int count = 1;

	while(a != '\0')
	{
		printf("[%c] ",a);
		a = *(str1+count);
		if(a != *(str2+count))
			return 1;
		count++;
	}
	
	if(a == '\0' && *(str2+count-1) == '\0')
		return 0;
	else
		return 1;
	
}

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
	//2+3*5
	if(0)
	{
		printf("SUM:[%d]\n",SUM(2,3)*5);
		printf("SUM2:[%d]\n",SUM2(2,3)*5);
	}
	
	if(0)
	{
		char *str1 = "abcef";
		char *str2 = "abcd";
		if(strcmpp(str1,str2))
			printf("\nstrcmpp : fail\n");
		else
			printf("\nstrcmpp : sucess\n");
	}
	
	if(1)
	{
		star();
	}
	
	
    return 0;
}