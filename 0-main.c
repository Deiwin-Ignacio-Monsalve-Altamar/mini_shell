#include "holberton.h"
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