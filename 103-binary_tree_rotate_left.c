#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: ...
 *
 * Return: pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	tmp != NULL ? (tmp->parent = tree) : 0;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	tmp != NULL ? (tmp->left == tree ? (tmp->left = pivot) : (tmp->right = pivot)) : 0;

	return (pivot);
}

