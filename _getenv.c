#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _getenv - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
char *_getenv(const char *name)
{ 
	extern char **environ;
	char *token;
	int x = 0;
	char *tmp, *str;

	while (environ[x])
	{
		tmp = strdup(environ[x]);
		token = strtok(tmp, "=");
		if (strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
			str = strdup(token);
			free(tmp);
			return (str);
		}
		free(tmp);
		x++;
	}
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

    if (enve)
    {
    printf("%s\n", enve);
    free(enve);
    }
    else
        printf("Error\n");
    return (0);

}

