#ifndef C7C3570E_179A_4EA8_AACD_039567CD4226
#define C7C3570E_179A_4EA8_AACD_039567CD4226


#include <stdlib.h>
#include <stdio.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double Black node
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
void rb_tree_print(const rb_tree_t *tree);


int rb_tree_is_valid(const rb_tree_t *tree);


void rb_rotate_right(rb_tree_t **tree, rb_tree_t *y);
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *x);
rb_tree_t *rb_insert_fixup_RIGHT(rb_tree_t **tree, rb_tree_t *new);
rb_tree_t *rb_insert_fixup_LEFT(rb_tree_t **tree, rb_tree_t *new);
void rb_insert_fixup(rb_tree_t **tree, rb_tree_t *new);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);

rb_tree_t *array_to_rb_tree(int *array, size_t size);

/* rb_tree_remove.c */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);
void rb_tree_remove_node(rb_tree_t **tree, rb_tree_t *z);
void rb_tree_remove_fixup(rb_tree_t **tree, rb_tree_t *x, rb_tree_t *x_parent);
rb_tree_t *rb_tree_fix_right_sibling(rb_tree_t **tree, rb_tree_t *x,
	rb_tree_t *x_parent);
rb_tree_t *rb_tree_fix_left_sibling(rb_tree_t **tree, rb_tree_t *x,
	rb_tree_t *x_parent);
void rb_tree_replace(rb_tree_t **tree, rb_tree_t *before, rb_tree_t *after);
rb_tree_t *inorder_successor(rb_tree_t *z);

#endif /* C7C3570E_179A_4EA8_AACD_039567CD4226 */
