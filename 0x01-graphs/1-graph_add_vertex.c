#include "graphs.h"

/**
 * graph_add_vertex - adds a new vertex to @graph
 * @graph: graph
 * @str: content of a new vertex
 * Return: pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new, *vertex;

	if (!graph || !str)
		return (NULL);
	vertex = graph->vertices;
	while (vertex)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		if (!vertex->next)
			break;
		vertex = vertex->next;
	}
	new = calloc(1, sizeof(vertex_t));
	if (!new)
		return (NULL);
	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->index = graph->nb_vertices++;
	if (vertex)
		vertex->next = new;
	else
		graph->vertices = new;
	return (new);
}
