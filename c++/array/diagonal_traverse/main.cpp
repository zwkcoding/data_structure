/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-25 18:41:01 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-25 19:23:23
 */

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
#include "../../include/base.h"
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

// const int debug = 0;
// typedef unsigned uint;
// typedef unsigned char uchar;
auto __ =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}
();

/// Time Complexity: O((n+m)^2)
/// Space Complexity: O(n*m)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};

        const int n = matrix.size();
        const int m = matrix[0].size();

        vector<int> res;
        for (int s = 0; s <= n + m - 2; s++) {
            int i = 0, j = 0;
            for (int x = 0; x <= s; x++) {
                i = x;
                j = s - x;
                // when it is even, rever dir
                if (s % 2 == 0) {
                    swap(i, j);
                }
                // touch edge
                if (i >= n || j >= m)
                    continue;
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
    };

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& data, dataType2 K = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.findDiagonalOrder(data);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("data", data);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
   vector<vector<int>> data;
    vector<int> expectAns;


    data = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    expectAns = {1,2,4,7,5,3,6,8,9};
    test(expectAns, data);


    data = {
        { 1 }
    };
    expectAns = {1};
    test(expectAns, data);

    data = {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };
    expectAns = {1,2,4,5,3,6};
    test(expectAns, data);

    data = {
        { 1, 2 },
        { 4, 5 },
        { 7, 8}
    };
    expectAns = {1,2,4,7,5,8};
    test(expectAns, data);

    return 0;
}
