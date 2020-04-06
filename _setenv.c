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
extern char **environ;
int	main(int argc, char **argv)
{
    int i = 0;
    while (environ[i])
    {
        i++;
    }
    environ[i] = argv[1];
    i = 0; 
    while (environ[i])
    {
    printf("%s\n", environ[i]);
    i++;
    }
    return (0);
}
