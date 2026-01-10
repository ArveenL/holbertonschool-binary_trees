#include "binary_trees.h"

/**
 * binary_tree_height_full - Helper function to measure tree height
 * @tree: Pointer to the root
 * Return: Height of the tree
 */
static size_t binary_tree_height_full(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);

    left = binary_tree_height_full(tree->left);
    right = binary_tree_height_full(tree->right);

    return (1 + (left > right ? left : right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    if (!tree->left || !tree->right)
        return (0);

    return (binary_tree_is_perfect(tree->left) &&
            binary_tree_is_perfect(tree->right) &&
            (binary_tree_height_full(tree->left) ==
             binary_tree_height_full(tree->right)));
}

