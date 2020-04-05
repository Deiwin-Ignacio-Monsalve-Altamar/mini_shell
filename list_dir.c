#include "holberton.h"
/*
 * _getdir - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */

int _getdir(char *name)
{
    char *token;
    
	while (token != NULL)
	{ 
        printf("%s\n", token);
		token = strtok(NULL, ":");
		return (0);	
		x++;
    }
    return (-1);
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

    return (0);
}
