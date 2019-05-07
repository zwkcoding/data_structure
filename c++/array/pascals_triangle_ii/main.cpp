/*
 * Filename: /home/zwk/code/data_structrue/c++/array/pascals_triangle_ii/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/array/pascals_triangle_ii
 * Created Date: Tuesday, May 7th 2019, 8:26:25 pm
 * Author: zwk
 * 
 */

#include "../../include/base.h"

/// Time Complexity: O(n^2)
/// Space Complexity: O(k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // f(x, y) = f(x-1, y -1) + f(x-1, y)
        vector<int> ans;
        ans.resize(rowIndex+1, 1);
        for(int i=2; i <= rowIndex; i++) {
            for(int j  = i - 1; j > 0; j--)  {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
};

int main() {
    int first;
     vector<int>  expectAns;

    first = 1;
    expectAns = {1,1};
    TEST_SMP1(Solution, getRow, expectAns, first);


    first = 2;
    expectAns = {1,2,1};
    TEST_SMP1(Solution, getRow, expectAns, first);

    first = 3;
    expectAns = {1,3,3,1};
    TEST_SMP1(Solution, getRow, expectAns, first);



    first = 4;
    expectAns = {1,4,6,4,1};
    TEST_SMP1(Solution, getRow, expectAns, first);


    first = 5;
    expectAns = {1,5,10,10,5,1};
    TEST_SMP1(Solution, getRow, expectAns, first);

    return 0;
}
