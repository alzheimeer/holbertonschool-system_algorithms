#include "huffman.h"

/**
 * huffman_extract_and_insert - extracts two node and inserts as one
 * @priority_queue: our huffman priorty queue to act upon
 * Return: 1 on success else 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1, *node2, *newnode;
	symbol_t *symbol;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	node1 = heap_extract(priority_queue);
	node2 = heap_extract(priority_queue);
	if (!node1 || !node2)
		return (0);
	symbol = symbol_create(-1,
						   ((symbol_t *)node1->data)->freq + ((symbol_t *)node2->data)->freq);
	if (!symbol)
		return (0);
	newnode = binary_tree_node(NULL, symbol);
	if (!newnode)
		return (free(symbol), 0);
	newnode->left = node1;
	newnode->right = node2;
	node1->parent = newnode;
	node2->parent = newnode;
	if (heap_insert(priority_queue, newnode))
		return (1);
	return (0);
}
