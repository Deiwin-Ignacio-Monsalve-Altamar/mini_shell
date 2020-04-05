#include "holberton.h"
/**
 * _getenv - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
char *_getenv(const char *name)
{ 
    extern char **environ;
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
