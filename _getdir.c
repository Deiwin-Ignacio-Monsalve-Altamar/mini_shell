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
int _getdir(const char *name)
{
	char *token, *str, *tmp;
	int x = 0;

	
	while (environ[x])
	{
		tmp = strdup(environ[x]);
		token = strtok(tmp, "=");
		if (strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
			str = strdup(token);
			token = strtok(str, ":");
			while (token != NULL)
			{   printf("%s\n", token);
				token = strtok(NULL, ":");
			}
			return (0);
		}
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
    _getdir(name);
    return (0);
}