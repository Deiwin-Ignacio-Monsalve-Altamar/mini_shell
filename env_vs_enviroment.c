#include <stdio.h>

/**
 * main - prints addres of envieron vs env
 *
 * Return: Always 0.
 */
extern char **environ;
int main(int ac, char **av, char **env)
{
    printf("addrees of envieron: %p VS address of env %p\n", *environ, *env);
    return (0);
}