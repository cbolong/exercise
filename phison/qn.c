#include <stdio.h>
//https://goo.gl/vU384q
//https://goo.gl/TW3zJJ
int main()
{
	FILE *fp;
	char str[1024] = {0};
	
	//write
	if(0)
	{
		//append
		fp = fopen("data.txt","a");
		fprintf(fp, "abc\n");
	}
	
	//read
	if(0)
	{
		//read
		fp = fopen("data.txt","r");
		fread( str, 1024, 1, fp );
		printf("%s\n",str);
	}
	//fgets
	if(1)
	{
		//read
		fp = fopen("data.txt","r");
		/*while(fgets(str, 1024, fp)!=NULL)
		{
			printf("%s",str);
		}*/
		//end-of-file
		while(!feof(fp))
		{
			fgets(str, 1024, fp);
			fputs(str, stdout);
		}
	}
	
	//fseek
	if(0)
	{
		//read
		fp = fopen("data.txt","r");
		fseek(fp, 5, SEEK_SET);
		int len = ftell(fp);
		printf("fseek:[%d]\n",len);
		rewind(fp);
		len = ftell(fp);
		printf("rewin:[%d]\n",len);
		fread( str, sizeof(char), 1024, fp );
		printf("%s",str);
	}	
	
	fclose(fp);
	
    return 0;
}