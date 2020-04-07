#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct l_path{
char *st;
struct l_path *next;
} list_t;

void freellp(list_t *head);
list_t *lpath(void);
list_t *llist_d(list_t **head, const char *str);
size_t lprint(const list_t *head);

int main()
{
	list_t *list;
	list = lpath();
	lprint(list);
	freellp(list);
	//free(list);
	return (0);
}

list_t *lpath(void)
{
	extern char **environ;
	char *token, *str, *aux, *aux1, *tmp;
	int x = 0;
	list_t **head;
	head = malloc (sizeof(list_t *));
	*head = NULL;
	aux = "PATH";
	while (environ[x])
	{
		tmp = strdup(environ[x]);
		token = strtok(tmp, "=");
		if (strcmp(aux, token) == 0)
		{
			token = strtok(NULL, "=");
			str = strdup(token);
			token = strtok(str, ":");
			while (token != NULL)
			{
				aux1 = strdup(token);
				*head = llist_d(head, aux1);
				token = strtok(NULL, ":");
				free(aux1);
			}
			free(tmp);
			free(str);
			return (*head);
		}
		x++;
		free(tmp);
	}
	return (*head);
}

list_t *llist_d(list_t **head, const char *str)
{
	list_t *new, *curr;
	char *str1;
	curr = *head;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	str1 = strdup(str);
	if (str1 == NULL)
	{
		free(new);
		free(str1);
		return (NULL);
	}
	(*new).st = str1;
	(*new).next = NULL;
	if(*head != NULL)
	{
		while((*curr).next != NULL)
		{
			curr = (*curr).next;
		}
		(*curr).next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

size_t lprint(const list_t *head)
{
	int x;
	const list_t *curr;
	if(head != NULL)
	{
		curr = head;
		for (x = 0; curr != NULL; x++)
		{
			if ((*curr).st == 0)
				printf("(nil)\n");
			else
				printf("%s\n", (*curr).st);
			curr = (*curr).next;
		}
	}
	return (x);
}
void freellp(list_t *head)
{
	list_t *aux;
	if (head != NULL)
	{
		while (head != NULL)
		{
			aux = head;
			head = (*head).next;
			free((*aux).st);
			free(aux);
		}
		free(head);
	}
}
