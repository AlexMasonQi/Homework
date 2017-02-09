/*Use the key to obtain the value 
  For example:"Key1=value1"
              "key2=          value2"
			  "key3=     value3     "
			  "key4=value4          "
			  "key5    =value5"
			  "key6    =   value6"
			  "key7    =    value7  "
			  "key8    =value8      "
*/

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag = 0;

///<summary>
///out of space
///</summary>
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

///<summary>
///Use the key to obtain the value
///</summary>
int getValue(char *keyvalue, char *keybuf, char *valuebuf, int *valuelen)
{
	int ret = 0;
	if (keyvalue == NULL || keybuf == NULL)
	{
		ret = -1;
		printf("The func getValue() err:%d\n", ret);
		exit(0);
	}
	char *keyAndValue = keyvalue;
	char *key = keybuf;
	char *value = valuebuf;
	int *valueLength = valuelen;
	char *tempKey = strstr(keyAndValue, key);
	char *tmp = NULL;
	int len = 0;
	if (tempKey)
	{
		tmp = strchr(keyAndValue, '=');
		tmp++;
		trimSpace(tmp, value);
		*valueLength = strlen(value);
	}
	else
	{
		printf("Error key!\n");
		flag = 1;
	}
}

int main()
{
	int ret = 0;
	char keyOrValue[256] = { 0 };
	char key[128] = { 0 };
	char value[256] = { 0 };
	int valueLen = 0;
	printf("Please input the key and value\n");
	//scanf("%s ", keyOrValue);
	gets_s(keyOrValue, 255);
	printf("Please input the key\n");
	scanf("%s", key);
	ret = getValue(keyOrValue, key, value, &valueLen);
	if (flag == 0)
	{
		printf("The value of %s is %s\n", key, value);
	}	
	system("pause");
	return ret;
}