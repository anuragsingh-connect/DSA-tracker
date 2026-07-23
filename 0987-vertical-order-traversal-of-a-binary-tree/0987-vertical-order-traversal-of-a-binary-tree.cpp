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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int ,map <int , multiset<int>>> nodes;
    queue<pair<TreeNode* ,pair<int,int>>> todo;
    todo.push({root , {0,0}});

    while(!todo.empty()){
        auto it = todo.front();
        todo.pop();
        TreeNode* nodval = it.first;
        int vertical = it.second.first;
        int level = it.second.second;

        nodes[vertical][level].insert(nodval->val);

        if(nodval->left) todo.push({nodval->left ,{vertical-1,level+1}});
        if(nodval->right) todo.push({nodval->right ,{vertical+1,level+1}});
    }

    vector<vector<int>>  ans;
    for (auto p: nodes){
        vector<int>tempo;
        for(auto q : p.second){
            tempo.insert(tempo.end(),q.second.begin(),q.second.end());
        }

        ans.push_back(tempo);
    }
            return ans;
    }
};