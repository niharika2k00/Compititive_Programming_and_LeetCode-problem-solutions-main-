/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * The MINIMUM DEPTH is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    Note: A leaf is a node with no children.
 */
class Solution
{
public:
    int shortestPath(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right) //  NO Children
            return 1;

        if (!root->right) //  root->right === NULL
            return (1 + shortestPath(root->left));

        if (!root->left) // root->left === NULL
            return (1 + shortestPath(root->right));

        return 1 + min(shortestPath(root->left), shortestPath(root->right)); //  when right + left both exsist
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return shortestPath(root);
    }
};
// @lc code=end
