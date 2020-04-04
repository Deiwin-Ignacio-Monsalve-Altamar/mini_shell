#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(void)
{
    char *line;
    size_t len = 0;
    int status, read = 0;
    pid_t pid;
    char *text[2], *token;

    text[1] = NULL;
    line = malloc(sizeof(char));
    if (line == NULL)
    {
        return (0);
    }
    printf("#cisfun$ ");
    read = getline(&line, &len, stdin);
    while (read > 1)
    {
        token = strtok(line, "\n");
        text[0] = token;
        
        pid = fork();
        if (pid == -1)
        {
            perror("Error");
            return (1);
        }
        
        if (pid == 0)
        {
            if (execve(text[0], text, NULL) == -1)
            {
                perror("Error: \n");
            }
        }
        else
        {
            wait(&status);
        }
          
        printf("#cisfun$ ");
        getline(&line, &len, stdin);
    }
    free(line);
    return (0);
}
