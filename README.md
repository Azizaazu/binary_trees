0. New node
Write a function that creates a binary tree node

Prototype: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
Where parent is a pointer to the parent node of the node to create
And value is the value to put in the new node
When created, a node does not have any child
Your function must return a pointer to the new node, or NULL on failure
1. Insert left
Write a function that inserts a node as the left-child of another node

Prototype: binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
Where parent is a pointer to the node to insert the left-child in
And value is the value to store in the new node
Your function must return a pointer to the created node, or NULL on failure or if parent is NULL
If parent already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.
.
.
.
18. Uncle
Write a function that finds the uncle of a node

Prototype: binary_tree_t *binary_tree_uncle(binary_tree_t *node);
Where node is a pointer to the node to find the uncle
Your function must return a pointer to the uncle node
If node is NULL, return NULL
If node has no uncle, return NULL
