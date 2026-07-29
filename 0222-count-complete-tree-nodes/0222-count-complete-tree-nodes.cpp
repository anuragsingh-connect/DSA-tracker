/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = countleft(root);
        int rightHeight = countright(root);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1+ countNodes(root->left) + countNodes( root->right);
    }

    int countleft(TreeNode* node) {
        int cnt = 0;
        if (node == NULL)
            return cnt;
        while (node) {
            cnt++;
            node = node->left;
        }
        return cnt;
    }

    int countright(TreeNode* node) {
        int cnt = 0;
        if (node == NULL)
            return cnt;
        while (node) {
            cnt++;
            node = node->right;
        }
        return cnt;
    }
};