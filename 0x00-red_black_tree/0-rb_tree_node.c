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

	rb_tree_t *newN = (rb_tree_t *)malloc(sizeof(rb_tree_t));

	if (!newN)
		return (NULL);

	newN->n = value;
	newN->parent = parent;
	newN->color = color;
	newN->left = NULL;
	newN->right = NULL;
	return (newN);
}





/**
 * rb_rotate_left - rotates subtree to left
 *
 * @tree: root node
 * @x: node to rotate
 */
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *x)
{
	rb_tree_t *y = NULL;

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		*tree = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

/**
 * rb_rotate_right - rotates subtree to right
 *
 * @tree: root node
 * @y: node to rotate
 */
void rb_rotate_right(rb_tree_t **tree, rb_tree_t *y)
{
	rb_tree_t *x = NULL;

	x = y->left;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL)
		*tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}
