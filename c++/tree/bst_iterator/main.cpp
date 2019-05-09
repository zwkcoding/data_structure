/*
 * Filename: /home/zwk/code/data_structrue/c++/tree/bst_iterator/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/tree/bst_iterator
 * Created Date: Thursday, May 9th 2019, 8:22:58 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

class BSTIterator {
private:
        stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            findLeft(top->right);
            
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
        
    }
    
    void findLeft(TreeNode* root)  {
        TreeNode* p = root;
        while(p != nullptr)  {
            st.push(p);
            p = p->left;
        }
    }
};



void test(){

    TreeNode list[100];    

    list[0].val = 1;
    list[1].val = 3;
    list[2].val = 2;

    list[0].right = list + 1;
    list[1].left = list + 2;

    BSTIterator bst_iter(list);

    int ans = bst_iter.next();
    printf("ans:  %d ",ans);
    printf("ans:  %d ", bst_iter.next());
    printf("ans:  %d ", bst_iter.next());


    std::cout << std::boolalpha;   
    std::cout<<bst_iter.hasNext()<<"\n";


}

int main(){
    test();
    return 0;
}
