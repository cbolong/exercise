#include <stdio.h>

char* func() {
	//array放在DATA區， 之後把值移去stack內
	//結束function後，data會被清掉
	//a[]如果有被用走就會變成亂碼
	char a[] = "Hello";
	//https://goo.gl/XJtS1G
	//char* a = "Hello";
	//printf("address of a: %p\n", a);
	return a;
}

int main(void)
{
    char* s = func();
	printf("address of s: %p\n", s);
    printf("[%s]\n", s);

    return 0;
}
