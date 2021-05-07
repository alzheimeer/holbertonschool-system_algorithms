#include "huffman.h"

/**
 * cmpF - compare the frequency value stored in each data pointer
 * @p1: pointer 1
 * @p2: pointer 2
 * Return: the difference between the first and second frequency
 */
int cmpF(void *p1, void *p2)
{
	binary_tree_node_t *node1 = p1, *node2 = p2;
	symbol_t *symbol1, *symbol2;

	symbol1 = node1->data;
	symbol2 = node2->data;

	return (symbol1->freq - symbol2->freq);
}

/**
 * huffman_priority_queue - creates priority queue from freq data
 * @data: array of characters
 * @freq: associated frequency of characters
 * @size: size of passed arrays
 * Return: pointer to priority queue
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	symbol_t *symbol;
	binary_tree_node_t *node;
	size_t i;

	heap = heap_create(cmpF);
	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		node = binary_tree_node(NULL, symbol);
		node = heap_insert(heap, node);
	}

	return (heap);
}
