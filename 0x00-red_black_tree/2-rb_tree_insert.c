#include "rb_trees.h"

/**
 * rb_tree_insert - inserts a value in a Red-Black Tree
 *
 * @tree: double pointer to root node of Red-Black tree to insert the value in
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *x = NULL;
	rb_tree_t *y = NULL;
	rb_tree_t *new = NULL;

	if (!tree)
		return (NULL);

	x = *tree;
	while (x != NULL)
	{
		y = x;
		if (x->n == value)
			return (NULL);
		if (value < x->n)
			x = x->left;
		else if (value > x->n)
			x = x->right;
	}
	new = rb_tree_node(y, value, RED);
	if (!new)
		return (NULL);

	if (y == NULL)
		*tree = new;
	else if (new->n < y->n)
		y->left = new;
	else
		y->right = new;
	rb_insert_fixup(tree, new);
	return (new);
}

/**
 * rb_insert_fixup - rotate nodes and recolor to fix violation
 *
 * @tree: double pointer to root node
 * @new: new node to fix
 *
 */
void rb_insert_fixup(rb_tree_t **tree, rb_tree_t *new)
{
	while (new->parent && new->parent->color == RED)
	{
		if (new->parent->parent && new->parent == new->parent->parent->left)
			new = rb_insert_fixup_RIGHT(tree, new);
		else
			new = rb_insert_fixup_LEFT(tree, new);
	}
	(*tree)->color = BLACK;
}

/**
 * rb_insert_fixup_LEFT - fixes when p->p->left
 *
 * @tree: root node
 * @new: node to be fixed
 *
 * Return: pointer to new node
 */
rb_tree_t *rb_insert_fixup_LEFT(rb_tree_t **tree, rb_tree_t *new)
{
	rb_tree_t *y = NULL;

	y = new->parent->parent->left;
	if (y && y->color == RED)
	{
		new->parent->color = BLACK;
		y->color = BLACK;
		new->parent->parent->color = RED;
		new = new->parent->parent;
	}
	else
	{
		if (new == new->parent->left)
		{
			new = new->parent;
			rb_rotate_right(tree, new);
		}
		new->parent->color = BLACK;
		new->parent->parent->color = RED;
		rb_rotate_left(tree, new->parent->parent);
	}
	return (new);
}

/**
 * rb_insert_fixup_RIGHT - fixes when p->p->right
 * @tree: root node
 * @new: node to be fixed
 *
 * Return: pointer to new node
 */
rb_tree_t *rb_insert_fixup_RIGHT(rb_tree_t **tree, rb_tree_t *new)
{
	rb_tree_t *y = NULL;

	y = new->parent->parent->right;
	if (y && y->color == RED)
	{
		new->parent->color = BLACK;
		y->color = BLACK;
		new->parent->parent->color = RED;
		new = new->parent->parent;
	}
	else
	{
		if (new == new->parent->right)
		{
			new = new->parent;
			rb_rotate_left(tree, new);
		}
		new->parent->color = BLACK;
		new->parent->parent->color = RED;
		rb_rotate_right(tree, new->parent->parent);
	}
	return (new);
}
