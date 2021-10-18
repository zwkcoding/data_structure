#include "../../include/base.h"

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    bool isCousins(TreeNode *root, int x, int y)
    {
        int depth, cnt, parent, level_cnt, last_level_cnt;
        int x_depth, y_depth, x_parent, y_parent;

        queue<TreeNode *> que;

        if (NULL == root) return false;
        que.push(root);
        depth = 0;
        last_level_cnt = 1;
        level_cnt = 0;
        cnt = 0;
        while (!que.empty())
        {
            TreeNode *pre = que.front();
            que.pop();
            if (pre)
            {
                cnt++;
                que.push(pre->left);
                que.push(pre->right);
                if (pre->left) level_cnt++;
                if (pre->right) level_cnt++;
                if (pre->left && pre->left->val == x)
                {
                    x_depth = depth;
                    x_parent = pre->val;
                }
                else if (pre->left && pre->left->val == y)
                {
                    y_depth = depth;
                    y_parent = pre->val;
                }

                if (pre->right && pre->right->val == x)
                {
                    x_depth = depth;
                    x_parent = pre->val;
                }
                else if (pre->right && pre->right->val == y)
                {
                    y_depth = depth;
                    y_parent = pre->val;
                }
            }
            if (cnt == last_level_cnt)
            {
                depth++;
                cnt = 0;
                last_level_cnt = level_cnt;
                level_cnt = 0;
            }
            if (0 == last_level_cnt) break;
        }

        if (x_depth == y_depth && x_parent != y_parent)
            return true;
        else return false;
    }

};


int main()
{
    vector<int> tree_data;
    TreeNode *tree;
    bool expectAns;

    tree_data = {1, 2, 3};
    tree = vecToTree(tree_data);
    expectAns = false;
    TEST_SMP3(Solution, isCousins, expectAns, tree, 2, 3);

    tree_data = {1, 2, 3, 4};
    tree = vecToTree(tree_data);
    expectAns = false;
    TEST_SMP3(Solution, isCousins, expectAns, tree, 4, 3);

    tree_data = {1, 2, 3, -1, 4, -1, 5};
    tree = vecToTree(tree_data);
    expectAns = true;
    TEST_SMP3(Solution, isCousins, expectAns, tree, 4, 5);

    tree_data = {1, 2, 3, -1, 4};
    tree = vecToTree(tree_data);
    expectAns = false;
    TEST_SMP3(Solution, isCousins, expectAns, tree, 2, 3);
}