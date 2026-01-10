#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: number of leaves, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    /* A node is a leaf if it has no left and right children */
    if (!tree->left && !tree->right)
        return 1;

    /* Sum the leaves of left and right subtrees */
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}

