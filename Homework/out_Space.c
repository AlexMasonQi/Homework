#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int trimSpace(char *inbuf, char *outbuf)
{
	int ret = 0;
	char *inTemp = inbuf;
	char *outTemp = outbuf;
	int j = strlen(inTemp) - 1;
	/*char *temp = &(inTemp[j]);*/
	if (inbuf == NULL)
	{
		ret = -1;
		printf("The func trimSpace() err:%d\n", ret);
		exit(0);
	}
	int i = 0;
	
	while (isspace(inTemp[i]))
	{
		i++;
	}
	while (isspace(inTemp[j]))
	{
		j--;
	}
	int len = j - i + 1;
	inTemp = &inTemp[i];
	strncpy(outTemp, inTemp, len);
}

int main()
{
	char buf[] = "    abcdefghi  ";
	char outbuf[128] = { 0 };
	int ret = 0;
	printf("The source string is:%s\n", buf);
	ret = trimSpace(buf, outbuf);
	printf("The dest string is:%s\n", outbuf);

	system("pause");
	return ret;
}