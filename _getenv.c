#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _getenv - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
extern char **environ;
char *_getenv(const char *name)
{ 
    unsigned int i = 0;
    char *token;
    char *s = malloc(sizeof(char) * 64);
    while(environ[i])
    { 
        s = strdup(environ[i]);
        token = strtok(s, "=");
        if (strcmp(token, name) == 0)
        {
            token = strtok(NULL, "=");  
            return (token);
        }
       i++;
    }
    free(s);
    return (NULL);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    const char *name = av[1];
    char *enve = _getenv(name);

    printf("%s\n", enve);
    return (0);

}