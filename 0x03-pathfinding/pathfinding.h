#ifndef D57937A9_B092_4C05_8A99_588D2A08DFEE
#define D57937A9_B092_4C05_8A99_588D2A08DFEE

#include "graphs.h"
#include "queues.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * enum direction_s - which way to go
 * @RIGHT: go east
 * @BOTTOM: go down
 * @LEFT: go west
 * @TOP: go up
 */
enum direction_s
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;


queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target);

int backtracking(char **map, char before, int x, int y, point_t const *start,
		 point_t const *target, queue_t **path);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
					  vertex_t const *target);

#endif /* D57937A9_B092_4C05_8A99_588D2A08DFEE */
