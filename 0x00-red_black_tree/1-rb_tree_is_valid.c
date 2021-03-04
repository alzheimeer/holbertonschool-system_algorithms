#include "rb_trees.h"

/**
 * recursion - recursively valildates RB tree properties
 * @tree: pointer to root of tree to validate
 * @num_black: number of black nodes, passed by address
 * Return: 1 if valid else 0
 */
int recursion(const rb_tree_t *tree, size_t *num_black)
{
	size_t num_black_right = 0;
	int l, r;

	if (!tree)
		return (*num_black = 1);
	if ((tree->color != RED && tree->color != BLACK)
	 || (tree->color == RED && ((tree->left && tree->left->color != BLACK)
	  || (tree->right && tree->right->color != BLACK))))
		return (0);
	l = recursion(tree->left, num_black);
	r = recursion(tree->right, &num_black_right);
	if (!l || !r || *num_black != num_black_right)
		return (0);
	if (tree->color == BLACK)
		*num_black += 1;
	return (1);
}

/**
 * rb_tree_is_valid - valildates RB tree properties
 * @tree: pointer to root of tree to validate
 * Return: 1 if valid else 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	size_t num_black = 0;

	if (!tree || tree->color != BLACK)
		return (0);
	return (recursion(tree, &num_black));
}
