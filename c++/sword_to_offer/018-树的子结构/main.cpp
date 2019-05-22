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
private:
    bool DoesParentHaveChild(TreeNode* pRoot1, TreeNode* pRoot2)  {
        if(!pRoot2)  {
            return true;
        }
        
        if(!pRoot1)  {
            return false;
        }

        if(pRoot1->val == pRoot2->val)  {
            // 判断左右子节点
            return (DoesParentHaveChild(pRoot1->left, pRoot2->left) && 
                DoesParentHaveChild(pRoot1->right, pRoot2->right));
        } else  {
            return false;
        }
        
    }

public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)  {
            return false;  // sp case
        }
        if(!pRoot1)  {
            return false;  // 没有找到
        }
        bool ans = false;
        if(pRoot1->val == pRoot2->val)  {
            // 判断子树
            ans =  DoesParentHaveChild(pRoot1, pRoot2);
        }
        if(!ans)  {
            // 试图找到节点相同
            return (HasSubtree(pRoot1->left, pRoot2) ||
                　HasSubtree(pRoot1->right, pRoot2));
        }　else {
            return true;
        }

    }
};
