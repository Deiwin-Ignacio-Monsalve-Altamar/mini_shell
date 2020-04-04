#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int i;
    while (av[i]) /* *av */
    {
        printf("%s\n", av[i]); /*printf("%s\n", av[i]); */
        i++; //av++;
    }
    return (0);
}