#ifndef _HEADER_LINKED2_
#define _HEADER_LINKED2_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int _putchar(char c);
size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *swap_nodes(listint_t **head, unsigned int index);

#endif