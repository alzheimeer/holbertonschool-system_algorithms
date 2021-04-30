#include "huffman.h"

/**
 * symbol_create - creates a symbol
 * @data: data
 * @freq: frequency of @data
 * Return: pointer to the created structure, or NULL if it fails
*/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *s;

	s = calloc(sizeof(*s), 1);
	if (!s)
		return (NULL);
	s->data = data;
	s->freq = freq;
	return (s);
}
