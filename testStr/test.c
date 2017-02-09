#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *temp = "afhajkbvsa";
	char *tmp = strchr(temp, 'f');
	printf("The str is:%s\n", tmp);
	
	system("pause");
	return 0;
}