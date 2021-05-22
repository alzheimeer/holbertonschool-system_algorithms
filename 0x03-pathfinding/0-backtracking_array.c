#include "pathfinding.h"

/**
 * backtracking_array - function that searches for the first path from a 
 * starting point to a target point within a two-dimensional array.
 *
 * @map:  is the pointer to a read-only two-dimensional array
 * A 0 represents a walkable cell
 * A 1 represents a blocked cell
 * @rows: and cols are respectively the number of rows and columns of map
 * @cols: and cols are respectively the number of rows and columns of map
 * @start: stores the coordinates of the starting point
 * @target: stores the coordinates of the target point
 * For each visited cell, you’ll have to explore neighbour cells in the
 * following order:RIGHT, BOTTOM, LEFT, TOP
 */
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
}