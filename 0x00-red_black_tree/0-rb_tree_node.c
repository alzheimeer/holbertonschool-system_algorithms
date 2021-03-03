#include "rb_trees.h"

/**
 * rb_tree_node - creates a Red-Black Tree node
 * @parent: parent node
 * @value: node value
 * @color: node color
 *
 * Return:  pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
    
	rb_tree_t *newN = (rb_tree_t *) malloc(sizeof(rb_tree_t));

	if (!newN)
		return (NULL);

	newN->n = value;
	newN->parent = parent;
	newN->color = color;
	newN->left = NULL;
	newN->right = NULL;
	return (newN);


}