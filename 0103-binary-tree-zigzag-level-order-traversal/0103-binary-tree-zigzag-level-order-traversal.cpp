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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode* >st;
        vector<vector<int>>result;
        st.push(root);
        bool Left_Right = true;
        while(!st.empty()){
            if (root == NULL) return result;
            int size = st.size();
            vector<int>level(size);
            for(int i  = 0; i< size ; i++){
                TreeNode* current  =st.front();
                st.pop();
                int Index = Left_Right ? i : size - i -1;
                level[Index]  = current->val;

                if(current -> left) st.push(current->left);
                if(current -> right) st.push(current->right);
      
            }
            Left_Right = !Left_Right;
            result.push_back(level);
            
        }

            return result;
        
    }
};