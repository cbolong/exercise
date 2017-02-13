#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char *strReplace(char *source, char *find, char *rep)
{
	int len_find = strlen(find);
	int len_rep = strlen(rep);
	int length = strlen(source);
	
	char *result = (char*)malloc(sizeof(char*)*length);
	
	strcpy(result, source);
	
	char *tmp=NULL;
	int gap = 0;
	char *former=source;
	char *location=strstr(former, find);
	
	printf("former===[%s]\n",former);
	printf("location===[%s]\n",location);
	printf("length===[%d]\n",length);
	
	while(NULL!=location)
	{
		printf("++++++++++\n");
		gap += (location - former);
		printf("gap===[%d]\n",gap);
		result[gap] = '\0';
		printf("result[gap]===[%s]\n",result);
		length += (len_rep - len_find); //3-2
		printf("length===[%d]\n",length);
		tmp=(char*)realloc(result, sizeof(char*)*length);
		
		result = tmp;  //change result to tmp for alloc new length
		strcat(result, rep);
		gap+=len_rep;
		
		former = location + len_find;
		strcat(result, former);
		location = strstr(former, find);
	}
	return result;
}

int main()
{
	char *str = "/storage/ipad\0405";
	char *change = " ";
	
	printf("###[%s]\n",str);
	printf("###[%s]\n",strReplace(str, "\040", change));
	
	return 0;
}

