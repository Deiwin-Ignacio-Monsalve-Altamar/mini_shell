#ifndef Holberton
#define holberton

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct - search enviroment
 * 
 *@name: cons char
 *Return: char.
 */
typedef struct dir
{
    char *dir;
    struct dir *next;
} dir_t;

char *_getenv(const char *name);
char **_getdir(char *str);
#endif