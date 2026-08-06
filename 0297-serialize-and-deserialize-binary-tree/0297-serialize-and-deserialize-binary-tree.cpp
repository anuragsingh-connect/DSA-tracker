class Codec {
public:
    string serialize(TreeNode* root) {
        string s;
        if (root == nullptr) return "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == nullptr) {
                s += "#,";
            } else {
                s += to_string(cur->val) + ",";
                q.push(cur->left);   // push null children too
                q.push(cur->right);
            }
        }
        return s;  // ✅ outside the loop
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();  // ✅ .front() not .top()
            q.pop();
            // left child
            getline(s, str, ',');
            if (str == "#") {            // ✅ str not s
                curr->left = nullptr;
            } else {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            // right child
            getline(s, str, ',');
            if (str == "#") {            // ✅ str not s
                curr->right = nullptr;
            } else {
                curr->right = new TreeNode(stoi(str));  // ✅ right not left
                q.push(curr->right);
            }
        }
        return root;  // ✅ outside the loop
    }
};