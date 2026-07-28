class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return {};

        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParentNodes(root, parentMap);

        return bfsNodeDistance(target, parentMap, k);
    }

private:
    void mapParentNodes(TreeNode* root,
                         unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> bfsNodeDistance(TreeNode* target,
                                 unordered_map<TreeNode*, TreeNode*>& parentMap,
                                 int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int curLen = 0;

        while (!q.empty() && curLen < k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
            curLen++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};