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
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> inorder;
     TreeNode* cur = root;
     while(cur!= NULL){
        // edge case if left do not exists
        // steps- > push  root -> move cur to right
        if(cur->left == NULL){
            inorder.push_back(cur->val);
            cur = cur -> right;
        }
        else{
            
            // once create connection then go for left -> to go right first remove connection
            TreeNode* prev = cur -> left;
            // go to right most of left
            // && prev-> right !=curr  -> exit the left side as connection was made
            while(prev->right && prev-> right !=cur){
                prev = prev->right;
            }

            //  if no connection -> make connection -> move cur to left
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
             // if connection is there it means we are visiting for second time 
             // remove connenction ->push root ->  move cur->right
            else{

                prev-> right = NULL;
                inorder.push_back(cur->val);
                cur  = cur->right;
            }
        }
     }
            return inorder;
    }
};