#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStr1Str2(char *source, char *buf1, char *buf2)//string "1a2b3d4z"
{
	int ret = 0;
	if (source == NULL)
	{
		ret = -1;
		printf("The func getStr1Str2() err:%d\n", ret);
		exit(0);
	}
	char *sorStr = source;
	char *str1 = buf1;
	char *str2 = buf2;
	int i = 0;
	int j = 0, k = 0;
	for (i = 0; i < strlen(sorStr); i++)
	{
		if (i % 2)
		{
			str2[j] = sorStr[i];
			j++;
		}
		else
		{
			str1[k] = sorStr[i];
			k++;
		}
	}
}

int main()
{
	char *testStr = "1a2b3d4z";
	char str1[128] = { 0 };
	char str2[128] = { 0 };
	int ret = 0;
	printf("The source string is:%s\n", testStr);
	ret = getStr1Str2(testStr, str1, str2);
	printf("The odd str2 is:%s\n", str2);
	printf("The even str1 is:%s\n", str1);

	system("pause");
	return 0;
}