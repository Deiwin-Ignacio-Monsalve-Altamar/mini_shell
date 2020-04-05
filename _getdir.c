#include "holberton.h"
char **_getdir(char *str)
{
	char *new;
    char **text, *token;
    int i = 0;
    new = strdup(str);
    token = strtok(str, ":");
    i = 0;
    while (token != NULL)
    {
            i++;
            token = strtok(NULL, ":");
    } 
    text = malloc(sizeof(char *) * (i + 1));
        
    token = strtok(new, ":");
    i = 0;
    while (token != NULL)
    {
        text[i] = malloc(sizeof(char) * strlen(token));
        text[i] = token;
        i++;
        token = strtok(NULL, ":");
    }
    text[i] = '\0'; 
    return (text);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    const char *name = av[1];
    char *enve = _getenv(name);
    char **tmp;

    int j = 0; 
    tmp = _getdir(enve);

    for(j = 0; tmp[j]; j++)
    {
        printf("%s\n", tmp[j]);
    }

    free(tmp);
    return (0);
}