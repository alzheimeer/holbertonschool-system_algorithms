#include "nary_trees.h"

/**
 * nary_tree_insert -  inserts a node in a N-ary tree.
 * @parent:  is a pointer to the parent node.
 * If parent is not NULL, the created node must be added at the beginning of
 * the parent’s children linked list.
 * @str: is the string to be stored in the created node. It must be duplicated.
 * Return: a pointer to the created node, or NULL on failure. 
*/
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *newNode = calloc(1, sizeof(*newNode));
	char *str = strdup(_str);

	if (!newNode || !str)
		return (free(newNode), free(str), NULL);

	newNode->content = str;
	if (!parent)
		return (newNode);
	newNode->next = parent->children;
	parent->children = newNode;
	parent->nb_children++;
	return (newNode);
}
