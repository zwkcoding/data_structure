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
    vector< vector<int> > m_res;
    void FindPathRecursion(TreeNode* root, int expectNumber, int cumsum, vector<int> path)  {
        if(root == NULL)  return ;
        path.push_back(root->val);
        cumsum += root->val;
        if((cumsum == expectNumber) && (root->left == NULL) && (root->right) == NULL )  {
           // find it!
           m_res.push_back(path);
           return ;
        }
        if(root->left) FindPathRecursion(root->left, expectNumber, cumsum, path);
        if(root->right) FindPathRecursion(root->right, expectNumber, cumsum, path);

    }
    vector< vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        if(root == NULL)
        {
            return m_res;
        }
        vector<int> path;
        FindPathRecursion(root, expectNumber, 0, path);

        return m_res;
    }
};
