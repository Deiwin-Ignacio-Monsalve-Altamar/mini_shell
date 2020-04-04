#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - print all args
 *
 * Return: Always 0.
 */
char **_str(char *str)
{  
    char *new;
    char **text, *token;
    int i = 0;
    new = strdup(str);
    token = strtok(str, " ");
    i = 0;
    while (token != NULL)
    {
            i++;
            token = strtok(NULL, " ");
    } 
    text = malloc(sizeof(char *) * (i + 1));
        
    token = strtok(new, " ");
    i = 0;
    while (token != NULL)
    {
        text[i] = malloc(sizeof(char) * strlen(token));
        text[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    text[i] = '\0'; 
    return (text);
}
int main(int ac, char **av)
{
    char *str, **tmp;

    int j = 0;
    str = av[1];
    if (ac != 1)
    {
        tmp = _str(str);

        for(j = 0; tmp[j]; j++)
        {
            printf("%s\n", tmp[j]);
        }
        free(tmp);
    }
    return (0);
}