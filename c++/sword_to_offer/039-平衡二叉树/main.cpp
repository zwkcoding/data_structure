class Solution {
private:
    // 计算树的深度
    int calcDepth(TreeNode* pRoot)  {
        if(pRoot == NULL) return 0;
        int left_depth = 1 + calcDepth(pRoot->left);
        int right_depth = 1 + calcDepth(pRoot->right);
        return max(left_depth, right_depth);
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        int left_depth = calcDepth(pRoot->left);
        int right_depth = calcDepth(pRoot->right);
        if(abs(left_depth - right_depth) > 1)  {
            return false;
        } else {
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        }


    }
};
