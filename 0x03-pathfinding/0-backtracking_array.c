#include "pathfinding.h"

/**
 * backtracking_array - searches for first path from starting point to target
 *						within a two-dimensional array
 * @map: pointer to read-only 2D array (0 is walkable, 1 is blocked cell)
 * @rows: number of rows
 * @cols: number of columns
 * @start: coordinates of starting point
 * @target: coordinates of ending point
 * Return: queue in which each node is a point in the path from start to end
 */
queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target)
{
	queue_t *path;
	int x, y;

	if (rows < 0 || cols < 0)
		return (0);

	path = queue_create();
	if (path == NULL)
		return (0);

	path = malloc(1 * sizeof(queue_t));
	if (path == NULL)
		return (0);
	x = start->x;
	y = start->y;
	backtracking((char **)map, 'Z', x, y, start, target, &path);

	return (path);
}

int backtracking(char **map, char before, int x, int y, point_t const *start,
		 point_t const *target, queue_t **path)
{
	int right = 0, bottom = 0, left = 0, up = 0;
	point_t *current;

	current = malloc(sizeof(*current));
	if (!current)
		return (0);
	current->x = x;
	current->y = y;
	printf("Checking coordinates [%d, %d]\n", x, y);
	if (target->x == x && target->y == y)
	{
		queue_push_front(*path, current);
		return (1);
	}
	if (map[y][x + 1] == '0' && before != 'l')
		right = backtracking((char **)map,
				     'r', x + 1, y, start, target, path);
	if (map[y + 1][x] == '0' && before != 'u' && right != 1)
		bottom = backtracking((char **)map,
				      'd', x, y + 1, start, target, path);
	if (map[y][x - 1] == '0' && before != 'r' && right != 1 && bottom != 1)
		left = backtracking((char **)map,
				    'l', x - 1, y, start, target, path);
	if (map[y - 1][x] == '0' && before != 'd' &&
	    right != 1 && bottom != 1 && left != 1)
		up = backtracking((char **)map,
				  'u', x, y - 1, start, target, path);
	if (right == 0 && bottom == 0 && left == 0 && up == 0)
	{
		return (0);
	}
	queue_push_front(*path, current);
	return (1);
}
