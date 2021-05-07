
#include "huffman.h"

/**
 * huffman_extract_and_insert - extracts two node and inserts as one
 * @priority_queue: our huffman priorty queue to act upon
 * Return: 1 on success else 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *newnode, *node1, *node2;
	symbol_t *symbol, *s1, *s2;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	node1 = (binary_tree_node_t *)heap_extract(priority_queue);
	node2 = (binary_tree_node_t *)heap_extract(priority_queue);
	if (!node1 || !node2)
		return (0);
	symbol = symbol_create(-1,
						   ((symbol_t *)node1->data)->freq + ((symbol_t *)node2->data)->freq);
	if (symbol == NULL)
		return (0);
	newnode = binary_tree_node(NULL, symbol);
	if (newnode == NULL)
		return (0);
	newnode->left = node1;
	newnode->right = node2;
	node1->parent = newnode;
	node2->parent = newnode;
	if (heap_insert(priority_queue, newnode) == NULL)
		return (0);
	return (1);
}
