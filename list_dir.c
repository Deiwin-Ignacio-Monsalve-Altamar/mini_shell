#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
/**
 * struct - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

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
/**
 * add_node - print cotaing in list
 * @head: pointrs list_t
 * @str: const char
 * Return: list
 */
void add_node(list_t *s)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	(*new).str = *s;
	(*new).next = head;

    head = new;
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
        add_node(tmp[j]);
    }

    free(tmp);
    return (0);
}