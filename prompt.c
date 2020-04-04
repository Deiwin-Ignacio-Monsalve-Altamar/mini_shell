#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - that prints "$ ", wait for the user to enter a command, prints it on the next line.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line;
    size_t len = 0;

    line = malloc(sizeof(char));
    if (line == NULL)
    {
        return (0);
    }
    printf("$ ");
    getline(&line, &len, stdin);
    printf("%s", line);

    free(line);
    return (0);
}