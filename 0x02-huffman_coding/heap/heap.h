#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

/**
 * struct stack_s - stack style linked list for inserting into heap
 *
 * @prev: previous node
 * @next: next node
 * @direction: direction to traverse heap
 */
typedef struct stack_s
{
	struct stack_s *prev;
	struct stack_s *next;
	int direction;
} stack_t;

/* Prototypes */
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);

/* Insert Prototypes */
binary_tree_node_t *iwithIndex(binary_tree_node_t *root, int value, size_t idx, size_t nNode);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);

/* Extract Prototypes */
void heapify_down(heap_t *heap);
void *heap_extract(heap_t *heap);

/* Delete Prototypes */
void heap_delete(heap_t *heap, void (*free_data)(void *));
void free_tree(binary_tree_node_t *root, void (*free_data)(void *));

#endif /* _HEAP_H_ */
