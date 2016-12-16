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
	
	return 0;
}