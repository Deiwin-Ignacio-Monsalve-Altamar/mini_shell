#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
// *
//  * struct - search enviroment
//  * 
//  *@name: cons char
//  *Return: char.
//  */
// char *strcpyconst(char *dest, const char *src, int n)
// {
//     int i;

//     for (i = 0; i < n && src[i] != '\0'; i++)
//         dest[i] = src[i];
    
//     while (i < n)
//     {
//         dest[i] = '\0';
//         i++;
//     }
//     return (dest);
//}
/**
 * struct - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
/* char *_strcpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
} */
/**
 * *_strcmp - print character
 * @s1: pointr character
 * @s2 : poinr character
 * Return: int
 */
/* int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		return (0);
	}
	return (s1[i] - s2[i]);
} */
/**
 * struct - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
char *_getenv(const char *name, char **environ)
{
    char *token, copy;
    unsigned int i, len;

    while (name[len])
    {
        ++len;
    }
    copy = malloc((sizeof(char) * len) + 1);
    if(copy)
        return (NULL);

    strcpyconst(copy, name, len);

    i = 0;

    token = strtok(environ[i], "=");
    while (environ[i])
    {
        if (_strcmp(token, copy) == 0)
        {
            token = strtok(NULL, "\n");
            free(copy);
            return(token);
        }
        ++i;
        token = strtok(environ[i], "=");
    }
    free(copy);
    return (NULL);

}
/**
 * struct - search enviroment
 * 
 *@name: cons char
 *Return: char.
**/
extern char **environ;
int _setenv(const char *name, const char *value, int overwrite)
{
    if (getenv(name) != NULL)
    {
        if (overwrite == 0)
        {
            return (0);
        }
    }
    char **new, *token;
    int i = 0;
    char *s = malloc(sizeof(char) * 1024);
    new = malloc(sizeof(char) * 100);
    printf("dd");
    if(new == NULL|| s == NULL)
        return (0);
    while(environ[i])
    { 
        printf("dd");
        s = strdup(environ[i]);
        token = strtok(s, "=");
        strcpy(new[i], token);
        new[i] = malloc(sizeof(char) * 64);
        if (strcmp(token, name) == 0 && overwrite == 1)
        {
            token = strtok(NULL, "=");
          
            strcpy(token, value);
            strcpy(new[i++], token);
            return (1);
        }
        else
        {
            strcpy(new[i], value);
            return(1);
        }
        i++;
    }

    new[i] = '\0';
    i = 0;
    while (new[i])
    {
        printf("%s\n", new[i]);
        i++;
    }
    free(s);
    return (1);
}    

int	main(int argc, char **argv)
{
    int i;

    i = _setenv("PATH", "ELYESP", 1);
    printf("%i\n", i);
    return 0;
}
