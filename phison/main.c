#include <stdio.h>
#include <string.h>
void question1()
{
	int a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};
	int len = (sizeof(a)/sizeof(int));
	int i = 0;
	int index = 0;
	//list 0~500, doesn't include a[20] value
	
	for(index=0; index<len; index++)
	{
		while(i<a[index])
		{
			printf("[%d] ",i);
			i++;
		}
		//pass a[i]
		i++;
	}
	while(i<501)
	{
		printf("[%d] ",i);
		i++;
	}
	printf("\n");
}

void question2()
{
	int a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};
	int b = 0;
	int len = (sizeof(a)/sizeof(int));
	int index = 0;
	//list 0~500, doesn't include a[20] value
	
	scanf("%d",&b);
	int min = 100*b;
	int max = min + 99;
	printf("min:[%d] max:[%d]\n",min,max);
		
	for(index=0; index<len; index++)
	{
		if(a[index]>max)
			break;
		/**yo**/
		if(min>a[index])
			continue;
		/**yo-end**/
		while(min<a[index])
		{
			printf("[%d] ",min);
			min++;
		}
		//pass a[i]
		min++;
	}
	while(min<max)
	{
		printf("[%d] ",min);
		min++;
	}
	printf("\n");
}

struct ListStruct{
	unsigned int DataH;
	unsigned int DataL;
	unsigned int NextPtr;
};

struct ListStruct ListArray[10];
//#define NULL 0xFFFF

void question3()
{
	
	return;
}

int main()
{
	//printf("question1\n");
	//question1();
	//printf("question2\n");
	//question2();
	printf("question3\n");
	question3();	
	return 0;
}