#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define strings for all alphabets.
static struct _StringMap {
	char *name;
	char *number;
} StringMap[] = {
	{"aaa",    "111"},
	{"bbb",    "222"},
	{"ccc",    "333"},
	{"ddd",    "444"},
	{"eee",    "555"},
	{"fff",    "666"},
	{NULL,     NULL}
};

static char *GetValue(char *str)
{
	int i;
	
	for(i==0; StringMap[i].name != NULL; i++)
	{
		if(!strncmp(str,StringMap[i].name,strlen(StringMap[i].name)))
			return StringMap[i].number;
	}
}

int main()
{
	char *GetReturn;
	
	GetReturn = GetValue("aaa");
	printf("###[%s]\n",GetReturn);
	
	return 0;
}

