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
void freellp(list_t *head);
list_t *lpath(void);
list_t *llist_d(list_t **head, const char *str);
size_t lprint(const list_t *head);
#endif