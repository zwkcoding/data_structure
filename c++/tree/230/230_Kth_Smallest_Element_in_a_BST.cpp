/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
int find(TreeNode* root, int& k) {
    if(root)  {
        int x = kthSmallest(root->left, k);
        return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
    }
    return 0;
}
    
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);       
    }
};


// common method
class Solution {
    
public:
     int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        // push all left node
        while(p)  {
            stk.push(p);
            p = p->left;
        }
        
        while(k)  {
        TreeNode* tmp = stk.top();
        stk.pop();    // pop the current min node
        k--;
        if(k==0) return tmp->val;
        // delete min node sequencently
        if(tmp->right != NULL)  {
            // push all left node of right subtree
            tmp = tmp->right;  
            while(tmp)  {
                stk.push(tmp);
                tmp = tmp->left;
            }
        }
       
        }
        return -1;
    }
};
