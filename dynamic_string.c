#include <stdio.h>
#include <stdlib.h>
#define STRING_END '\0'
int main(void)
{
	char *dynamic_string = NULL;
	dynamic_string = (char*)malloc(sizeof(char));

	char input;
	int offset=0;

	while (input = getchar())
	{
		if(input != '\n')
		{
			*(dynamic_string + offset)=input;
			offset ++;
			dynamic_string = (char*)realloc(dynamic_string,(offset+1)*sizeof(char));
		}
		else
		{
			*(dynamic_string + offset)= STRING_END;
			break;
		}
	}

	printf("%s\n",dynamic_string );

	free(dynamic_string);
	dynamic_string = NULL;

	return 0;
}
