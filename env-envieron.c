#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example &  
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid;
    char *argv[] = {"/bin/ls", NULL};
    int status;
    size_t i = 0;


    while (i < 5)
    {
        pid = fork();
        if (pid == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error: \n");
            }
        }
        else
        {
            wait(&status);
            printf("Process father n: %i \n",(int) i);
        }
    i++;
    }
    return (0);
}