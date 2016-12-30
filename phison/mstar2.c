#include <stdio.h>
#include <string.h>

void q1(char *s)
{
	//s = malloc(sizeof(char) * 100);
	strcpy(s,"bob");
	printf("q1 in func:[%s]\n",s);
}

union uniondata {
	int a;
	char b;
};

struct structdata {
	int a;
	char b;
};

typedef struct _structdata {
	int a;
	char b;
}_sd;

void q2()
{
	union uniondata ud;
	struct structdata sd;
	_sd sdd;
	ud.a = 1;
	ud.b = 'a';
	sd.a = 2;
	sd.b = 'b';
	sdd.a = 3;
	sdd.b = 'c';
	//4byte 1byte , use the max size 4byte
	printf("union size :[%d] [%d] [%d]\n",sizeof(ud.a), sizeof(ud.b), sizeof(ud));
	printf("union data :[%d] [%c]\n",ud.a, ud.b);
	//4byte 1byte, total 5byte , use 2^3 byte = 8byte
	printf("struct size :[%d] [%d] [%d]\n",sizeof(sd.a), sizeof(sd.b), sizeof(sd));
	printf("struct data :[%d] [%c]\n",sd.a, sd.b);
	
	printf("struct 3 size :[%d] [%d] [%d]\n",sizeof(sdd.a), sizeof(sdd.b), sizeof(sdd));
	printf("struct 3 data :[%d] [%c]\n",sdd.a, sdd.b);
}

int main(void)
{
	if(0)
	{
		char *str = "alice";
		char *name = str;
		q1(name);
		printf("q1:[%s]\n",name);
	}
	
	if(1)
	{
		q2();
	}
    return 0;
}