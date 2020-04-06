#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
/**
 * _getenv - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
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
