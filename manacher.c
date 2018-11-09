#pragma GCC optimize ("O3")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 1e6+10
#define EXTSTR ((MAXSTR*2)+2)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

inline static char* extend(char*,const char*);
inline static int palind(const char*);

int main(void)
{
	char *str_input;
	str_input= (char*)malloc(MAXSTR*sizeof(char));
	char *str;
	str= (char*)malloc(EXTSTR*sizeof(char));
	scanf("%s",str_input);
	str=extend(str,str_input);
	printf("%d\n",palind(str));

	free(str);
	free(str_input);

	return 0;
}

inline static char* extend(char* str,const char *str_input)
{
	int i,len=strlen(str_input);
 	str[0]='@';
 	for(i=1;i<=2*len;i+=2)
   	{
      str[i]='#';
     	str[i+1]=str_input[i/2];
   	}
 	str[2*len+1]='#';
 	str[2*len+2]='$';
 	str[2*len+3]='\0';

	return str;
}

inline static int palind(const char *str)
{
	int result=0;
	int status[strlen(str)];
	int right = 0, mid = 0;
	memset(status, 0, sizeof(status));
	for (int i = 1; str[i] != '\0'; i++) 
	{
   	status[i] = right > i ? MIN(status[2*mid-i], right-i) : 1;
		while (str[i + status[i]] == str[i - status[i]]) status[i]++;
   		if (i + status[i] > right) 
   		{
       	right = i + status[i];
       	mid = i;
   		 }
   	result = MAX(result,status[i]);
	}

	return result-1;
}

