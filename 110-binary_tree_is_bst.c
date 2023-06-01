#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to recursively check if a binary tree
 *                is a valid Binary Search Tree.
 * @tree: Pointer to the current node in the binary tree.
 * @min: Minimum value the node's data can take (exclusive).
 * @max: Maximum value the node's data can take (exclusive).
 *
 * Return: 1 if the binary tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

