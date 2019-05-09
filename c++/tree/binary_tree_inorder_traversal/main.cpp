/*
 * Filename: /home/zwk/code/data_structrue/c++/tree/binart_tree_inorder_traversal/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/tree/binart_tree_inorder_traversal
 * Created Date: Thursday, May 9th 2019, 7:01:07 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
    vector<int>ans;

    void dfs(TreeNode* root){
        if(root == nullptr){
            return ;
        }

        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    public:
    vector<int> inorderTraversal(TreeNode *root) {
        ans.clear();
        dfs(root);
        return ans;
    }

};

void output(TreeNode* root, int lev = 1){
    if(root == nullptr){
        printf("%p\n", root);
        return;
    }

    printf("%p %d\n", root, root->val);
    output(root->left, lev + 1);
    output(root->right, lev + 1);
}

void output(vector<int>&ans){
    printf("ans=");
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}


void test(){
    srand(time(NULL));
    Solution work;

    TreeNode list[100];    
    vector<int>ans;

    list[0].val = 1;
    list[1].val = 2;
    list[2].val = 3;

    list[0].right = list + 1;
    list[1].left = list + 2;

    output(list, 1);
    ans = work.inorderTraversal(list);
    output(ans);

}

int main(){
    test();
    return 0;
}
