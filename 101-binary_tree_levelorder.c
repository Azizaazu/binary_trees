#include "binary_trees.h"

typedef struct queue_node_s {
    const binary_tree_t *node;
    struct queue_node_s *next;
} queue_node_t;

const binary_tree_t *dequeue(queue_node_t **front);
levelorder_queue_t *create_queue_node(const binary_tree_t *node);
void enqueue(queue_node_t **front, queue_node_t **rear, const binary_tree_t *node);


/**
 * create_queue_node - creates a new levelorder_queue_t node.
 * @node: The binary tree node
 *
 * Return: If an error occurs, NULL, Otherwise, a pointer to the new node.
 */

levelorder_queue_t *create_queue_node(const binary_tree_t *node)
{
	levelorder_queue_node_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_node_t));
	if (new_node)
	{
		new_node->node = node;
		new_node->next = NULL;
	}
	return (new_node);
}

/**
 * enqueue - Frees a levelorder_queue_t queue.
 * @front: front
 * @rear: A pointer to the head of the queue.
 * @node: node
 */

void enqueue(queue_node_t **front, queue_node_t **rear, const binary_tree_t *node)
{
	queue_node_t *new_node = create_queue_node(node);

	if (new_node)
	{
		if (*rear == NULL)
			*front = *rear = new_node;
		else
			(*rear)->next = new_node;
			*rear = new_node;
	}
}

/**
 * binary_tree_t *dequeue - tree a levelorder_queue_t queue.
 * @front: A pointer
 * Return: node or NULL
 */

const binary_tree_t *dequeue(queue_node_t **front)
{
	if (*front == NULL)
		return (NULL);

	const binary_tree_t *node = (*front)->node;

	queue_node_t *temp = *front;
	*front = (*front)->next;
	free(temp);
	return (node);
}

/**
 * binary_tree_levelorder - Traverses a binary tree usinglevel-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_node_t *front = NULL;
	queue_node_t *rear = NULL;

	enqueue(&front, &rear, tree);

	while (front != NULL)
	{
		const binary_tree_t *current = dequeue(&front);

		func(current->n);

		if (current->left)
			enqueue(&front, &rear, current->left);

		if (current->right)
			enqueue(&front, &rear, current->right);
	}
}
