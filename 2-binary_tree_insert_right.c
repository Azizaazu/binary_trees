#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node
 * @parent: A pointer to the node
 * @value: value to store in the new node.
 *
 * Return: If parent is (NULL), pointer to the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;

	if (parent->right != NULL)
	{
		new_node->left = parent->left;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
