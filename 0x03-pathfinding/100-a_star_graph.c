#include "pathfinding.h"

/**
 * a_star_graph - function that searches for the shortest and fastest path 
 * from a starting point to a target point in a graph.
 *
 * @graph: is a pointer to the graph to go through
 * @start: is a pointer to the starting vertex
 * @target: is a pointer to the target vertex
 * return: a queue, in which each node is a char * corresponding to a vertex,
 *  forming a path from start to target
 * You’ll have to use A* algorithm to find the shortest and fastest path,
 *  using the Euclidean distance to the target vertex as the heuristic
 * You’ll have to print each visited vertex as in the example below
 * You are allowed to use the math library (math.h).
 *  Your code will be linked with the math library using -lm
 */

queue_t *a_star_graph(graph_t *graph, vertex_t const *start, vertex_t const *target)
{
}