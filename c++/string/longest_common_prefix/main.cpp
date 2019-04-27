/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-27 12:36:38 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-27 13:17:01
 */

#include "../../include/base.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

// const int debug = 0;
// typedef unsigned uint;
// typedef unsigned char uchar;
auto __ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0)  {
            return res;
        }

        int min_len = strs[0].length();
        const string& first = strs[0];
        for(int i = 0; i < strs.size(); i++)  {
            min_len = std::min(min_len, (int)strs[i].length());
        }

        int res_len = min_len;
        for(int i = 0; i < strs.size(); i++)  {
            for(int j = 0; j < min_len; j++)  {
                if(strs[i][j] != first[j])  {
                    res_len = j;
                    break;
                }
            }
        }
        return first.substr(0, res_len);
    }

};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.longestCommonPrefix(firstData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");
    
}

int main()
{
    vector<string> first;
    string expectAns;

    first = {"flower","flower","flower"};
    expectAns = "flower";
    test(expectAns, first);

    first = {"flower","flow","flight"};
    expectAns = "fl";
    test(expectAns, first);


    first = {"dog","racecar","car"};
    expectAns = "";
    test(expectAns, first);

    first = {};
    expectAns = "";
    test(expectAns, first);

    return 0;
}
