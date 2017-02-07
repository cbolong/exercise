#include <stdio.h>
#include <string.h>

void foo(int *a)
{
	int c = 5566;
	*a = c;
}

void foo_string(char **dt, int len)
{
	int i = 0;
	printf("foo_String:[%s]\n",*dt);
	printf("1.[%X]\n",&dt);
	*dt = "bingo";
}

int main()
{
	if(0)
	{
		//assign address for ptr. Ex: value [xxx] address [12FF54]
		int *ptr;
		//assign value for i. Ex: value [10] address [12FF80]
		int i = 10;
		//assign i address to ptr value. Ex: value [12FF80] address [12FF54]
		ptr = &i;

		printf("i value:[%d]\n", i);
		printf("i address:[%0X]\n", &i);	
		//Use "&" to get address, use "*" to get value.
		printf("ptr value:[%0X]\n", ptr);
		printf("ptr get value from i:[%d]\n", *ptr);
		printf("ptr address:[%X]\n", &ptr);
		
		
		int ptr2;
		foo(&ptr2);
		printf("ptr2 :[%d]\n",ptr2);
		printf("=====================\n");
		//pass array to function
		//http://stackoverflow.com/questions/5611832/changing-an-array-with-a-function-in-c
		char *data="abcde";
		int len = strlen(data);
		printf("1.[%X]\n",&data);
		foo_string(&data,len);
		printf("2.[%X]\n",&data);
		printf("main:[%s]\n",data);
	}
	if(0)
	{
		int arr2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
		printf("%p\n", arr2);
		printf("%p\n", arr2 - 1);
		printf("%p\n", *(arr2+1));
		printf("%d\n", *(*(arr2+1)));
	}
	if(0)
	{
		int i=5, j=2;
		//j = ((++i)++) + (++j);
		printf("j: %d", j);
	}
	if(1)
	{
		int i=0;
		printf("i++:%d\n",i++);
		printf("i:%d\n",i);
		printf("i++:%d\n",++i);
		printf("i:%d\n",i);
		printf("i--:%d\n",i--);
		printf("i:%d\n",i);
		printf("--i:%d\n",--i);
		printf("i:%d\n",i);
		//int a=2,b=5;
		//int x=++(a*b);
		//printf("x:%d\n",x);
	}
	if(0)
	{
		int i = 0;
		int j = (++i, i++); 
		printf("%d\n",j);
	}
	return 0;
}