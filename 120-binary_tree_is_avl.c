#include "binary_trees.h"
int bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	int is_avl = 1;
	int height_diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	if (height_diff > 1 || height_diff < -1)
		is_avl = 0;

	if (!binary_tree_is_bst(tree))
		is_avl = 0;

	if (tree->left)
		is_avl = binary_tree_is_avl(tree->left) && is_avl;
	if (tree->right)
		is_avl = binary_tree_is_avl(tree->right) && is_avl;

	return is_avl;
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return 0;

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return left_height + 1;
	else
		return right_height + 1;
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 1;

	return bst_helper(tree, NULL, NULL);
}

/**
 * bst_helper - Recursive helper function to check if a binary tree is a valid BST.
 * @tree: Pointer to the current node being checked.
 * @min: Pointer to the minimum allowed value in the subtree.
 * @max: Pointer to the maximum allowed value in the subtree.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return 1;

	if (min && tree->n <= min->n)
		return 0;

	if (max && tree->n >= max->n)
		return 0;

	return bst_helper(tree->left, min, tree) && bst_helper(tree->right, tree, max);
}

