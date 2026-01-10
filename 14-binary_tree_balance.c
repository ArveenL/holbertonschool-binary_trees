#include "binary_trees.h"

/* Helper function: compute the height of a tree */
static size_t tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return 0;

    left_height = tree_height(tree->left);
    right_height = tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree node
 * @tree: pointer to the node
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    size_t left_h = 0, right_h = 0;

    if (!tree)
        return 0;

    if (tree->left)
        left_h = tree_height(tree->left);
    if (tree->right)
        right_h = tree_height(tree->right);

    return (int)(left_h - right_h);
}

