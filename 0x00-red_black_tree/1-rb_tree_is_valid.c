#include "rb_trees.h"


/**
 * rb_tree_is_valid - valildates RB tree properties
 * @tree: pointer to root of tree to validate
 * Return: 1 if valid else 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	size_t b1 = 0, b2 = 0;
	static int x = 0;

	if (x == 0 && tree->color != BLACK)
		return (0);
	x = 1;
	if (!tree)
		return (0);
	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED && tree->left && tree->left->color != BLACK)
		return (0);
	if (tree->color == RED && tree->right && tree->right->color != BLACK)
		return (0);
	b1 = rb_tree_is_valid(tree->left);
	b2 = rb_tree_is_valid(tree->right);

	if (b1 != b2)
		return (0);
	if (b1 == b2 && tree->color == BLACK)
		return (1);
	if (b1 == b2 && tree->color == RED)
		return (b1);
	return (0);
}
