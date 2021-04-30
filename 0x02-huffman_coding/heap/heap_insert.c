#include "heap.h"

/**
 * iwithIndex - Inserts node level ordered
 * @root: Type binary_tree pointer of the parent node
 * @value: Type int value of value inserted into node
 * @idx: Type int index of the node
 * @nNode: number the nodes + 1
 * Return: Node inserted
 */
binary_tree_node_t *iwithIndex(binary_tree_node_t *root, void *value, size_t idx, void *nNode)
{
	binary_tree_node_t *nodel, *noder;
	size_t parent = nNode / 2;

	if (!root)
		return (NULL);
	if (idx == parent)
	{
		if (nNode % 2)
			return (root->right = binary_tree_node(root, &value));
		else
			return (root->left = binary_tree_node(root, &value));
	}
	nodel = iwithIndex(root->left, value, 2 * idx, nNode);
	noder = iwithIndex(root->right, value, 2 * idx + 1, nNode);
	if (nodel)
		return (nodel);
	else
		return (noder);
}

/**
 * heap_insert - insert into min heap
 * @heap: heap data structure
 * @data: data for a new node
 * Return: pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node, *parent;

	if (!heap)
		return (NULL);
	heap->size++;
	if (!heap->root)
		return (heap->root = binary_tree_node(NULL, data));
	new_node = iwithIndex(heap->root, data, 1, heap->size);
	while (new_node && new_node->parent && new_node->data > new_node->parent->data)
	{
		new_node->data = new_node->parent->data;
		new_node->parent->data = data;
		new_node = new_node->parent;
	}
	return (new_node);
}
