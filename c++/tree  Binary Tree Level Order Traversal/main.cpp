class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        vector<int> layer_vt;
        if(!root) return ans;    // special case
        qu.push(root);
        qu.push(nullptr);
        TreeNode* p;
        while(!qu.empty())  {
            p = qu.front();
            qu.pop();
            if(p)  {
                // add children node
                layer_vt.push_back(p->val);
                if(p->left) qu.push(p->left);
                if(p->right) qu.push(p->right);
            } else  {
                ans.push_back(layer_vt);
                layer_vt.resize(0);    // empty temorary 
                if(qu.size() > 0)  {
                    qu.push(nullptr);    // `nullptr` flag used in queue, labelling current layer is done! 
                }
            }
        }
        return ans;   
    }
};
