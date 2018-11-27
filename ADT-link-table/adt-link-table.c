#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n",item.title,item.rating);
}

char* s_get(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr,"No memory available!\n");
        exit(1);
    }

    puts("Enter the first movie titile:");
    while(s_get(temp.title,TSIZE)!=NULL&&temp.title[0]!='\0')
    {
        puts("Enter yout rating <0-10>:");
        scanf("%d",&temp.rating);
        while(getchar()!='\n')
            continue;

        if(AddItem(temp,&movies)==false)
        {
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        puts("Enter the next movie titile (empty line to stop):");
    }

    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies,showmovies);
    }
    printf("You entered %d movies. \n", ListItemCount(&movies));

    EmptyTheList(&movies);
    printf("Done!\n");

    return 0;
}