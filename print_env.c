#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char **environ;
int main(void)
{
    int i = 0;
    while(environ[i])
    {
         printf("%s\n", environ[i++]);
    }
    return (0);
}