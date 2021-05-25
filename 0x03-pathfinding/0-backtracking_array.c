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
	int x, y, i, ret;
	char **map2;

	if (!map || !*map || !start || !target || rows < 1 || cols < 1)
		return (NULL);
	map2 = malloc(rows * sizeof(char *));
	if (!map2)
		exit(1);
	for (i = 0; i < rows; i++)
	{
		map2[i] = malloc(cols + 1);
		if (!map2[i])
			exit(1);
		strcpy(map2[i], map[i]);
	}
	path = queue_create();
	if (path == NULL)
		return (0);
	x = start->x;
	y = start->y;
	ret = backtracking(map2, x, y, rows, cols, start, target, &path);
	if (!ret)
		queue_delete(path), path = NULL;
	for (i = 0; i < rows; i++)
		free(map2[i]);
	free(map2);
	return (path);
}

int backtracking(char **map, int x, int y,  int rows, int cols,
		 point_t const *start, point_t const *target, queue_t **path)
{
	int right = 0, bottom = 0, left = 0, up = 0;
	point_t *current;

	current = malloc(sizeof(*current));
	if (!current)
		return (0);
	current->x = x;
	current->y = y;
	printf("Checking coordinates [%i, %i]\n", x, y);
	map[y][x] = '1';
	if (target->x == x && target->y == y)
	{
		queue_push_front(*path, current);
		return (1);
	}
	if (x + 1 < cols)
		if (map[y][x + 1] == '0')
			right = backtracking((char **)map, x + 1, y,
					     rows, cols, start, target, path);
	if (y + 1 < rows)
		if (map[y + 1][x] == '0' && right != 1)
			bottom = backtracking((char **)map, x, y + 1,
					      rows, cols, start, target, path);
	if (x - 1 >= 0)
		if (map[y][x - 1] == '0' && right != 1
		    && bottom != 1)
			left = backtracking((char **)map, x - 1, y,
					    rows, cols, start, target, path);
	if (y - 1 >= 0)
		if (map[y - 1][x] == '0' && right != 1
		    && bottom != 1 && left != 1)
			up = backtracking((char **)map, x, y - 1,
					  rows, cols, start, target, path);
	if (right == 0 && bottom == 0 && left == 0 && up == 0)
	{
		free(current);
		return (0);
	}
	queue_push_front(*path, current);
	return (1);
}
