/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-24 19:34:29 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-24 21:38:17
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

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums)  {
        const int n = nums.size();
        if(n == 0)  {
            return -1;
        }

        int sum = 0;
        for(int i = 0; i < n; i++)  {
            sum += nums[i]; 
        }

        int left_sum = 0;
        for(int i = 0; i < n; i++)  {
            // int cur_index = i;
            // for(int j = 0; j < i; j++)  {
            //     left_sum += nums[j];
            // }
            int temp_sum = 2 * left_sum + nums[i];
            if(temp_sum == sum)  {
                return i;    
            } else  {
                left_sum += nums[i];
            }
        }
        return -1;
    }


};


template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& data, dataType2 K = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.pivotIndex(data);

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
    vector<int> data;
    int expectAns;


    data = {1, 7, 3, 6, 5, 6};
    expectAns = 3;
    test(expectAns, data);


    data = {1, 2, 3};
    expectAns = -1;
    test(expectAns, data);

    return 0;
}
