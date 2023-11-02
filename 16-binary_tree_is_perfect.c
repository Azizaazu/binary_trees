#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: 0 if tree is null
 *
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_full = binary_tree_is_full(tree);

	if (!is_full)
		return (0);

	size_t leaf_depth = binary_tree_depth(tree);

	return (binary_tree_depth(tree) == leaf_depth);
}

/**
 * binary_tree_depth -  checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: 0 if tree is null
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_depth = binary_tree_depth(tree->left);
	size_t right_depth = binary_tree_depth(tree->right);

	return ((left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1));
}

/**
 * binary_tree_is_full -  checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: 0 if tree is null
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left == NULL && tree->right == NULL) || (tree->left != NULL && tree->right != NULL))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
