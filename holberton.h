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
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;
extern char **environ;
char *_getenv(const char *name);
char **_getdir(char *str);
#endif