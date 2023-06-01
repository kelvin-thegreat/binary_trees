#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor_first = NULL, *ancestor_second = NULL;

	if (!first || !second)
		return (NULL);

	ancestor_first = (binary_tree_t *)first;
	ancestor_second = (binary_tree_t *)second;

	while (ancestor_first != ancestor_second)
	{
		if (ancestor_first)
			ancestor_first = ancestor_first->parent;
		if (ancestor_second)
			ancestor_second = ancestor_second->parent;
	}

	return (ancestor_first);
}
