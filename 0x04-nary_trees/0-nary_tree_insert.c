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
    nary_tree_t *newNode;

    newNode = malloc(sizeof(*newNode));
	if (!newNode)
		return (NULL);
    newNode->content = strdup(str);
    if (!parent)
	    return (newNode);
	newNode->parent = parent;
    newNode->next = parent->children;
	parent->nb_children++;
	parent->children = newNode;
	return (newNode);
}
