#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *dynamic_string = NULL;
	dynamic_string = (char*)malloc(sizeof(char));

	char input;
	int offset=0;

	while (input = getchar(), input != '\n')
	{
		*(dynamic_string + offset)=input;
		offset ++;
		dynamic_string = realloc(dynamic_string,(offset+1)*sizeof(char));
	}

	printf("%s\n",dynamic_string );

	free(dynamic_string);
	dynamic_string = NULL;

	return 0;
}