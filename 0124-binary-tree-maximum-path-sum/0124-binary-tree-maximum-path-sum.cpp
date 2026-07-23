/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* node) {
        int maxpath = INT_MIN;
        dfspath(node,maxpath);
        return maxpath;

    }

    int dfspath(TreeNode* node,int &maxpath){
        if (node == NULL) return 0;
        int left = max(0,dfspath(node->left,maxpath));
        int right = max(0,dfspath(node->right,maxpath));
        maxpath = max(maxpath , left+right+node->val);
        return node->val + max(left,right);
    }

};