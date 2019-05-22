/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        if(!root) return ans;
        qu.push(root);
        qu.push(nullptr);  // null marker for layer
        TreeNode* cur;
        while(!qu.empty())  {
            cur = qu.front();
            qu.pop();
            if(!cur)  {
                // 截止到一层了
               if (!qu.empty())
               qu.push(nullptr);    // leave marker if has next layer
            }
            else {
                // 还在一层中
                ans.push_back(cur->val);
                // 插入其左右节点
                if(cur->left)  qu.push(cur->left);
                if(cur->right)  qu.push(cur->right);
            }
        }
        return ans;
    }
};
