#include "binary_trees.h"

/**
 * is_ancestor - Test ancestor function and print informations
 * @node: node
 * @ancestor: pointer
 * Return: 0
 */

int is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	while (node != NULL)
		if (node == ancestor)
			return (1);

	node = node->parent;

	return (0);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: first node
 * @second: Second node
 * Return: return pointer or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor = first;

	while (ancestor != NULL)
	{
		if (is_ancestor(ancestor, second))
			return ((binary_tree_t *)ancestor);

		ancestor = ancestor->parent;
	}
	return (NULL);
}
