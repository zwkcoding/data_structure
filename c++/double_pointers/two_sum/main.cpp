/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-27 20:06:48 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-27 20:13:47
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

typedef unsigned uint;
typedef unsigned char uchar;
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
    vector<int> twoSum(vector<int>& numbers, int target) {
         unordered_map<int,int> record;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++)  {
            if(record.find(numbers[i]) == record.end())  {
                record[target - numbers[i]] = i;
            } else {
                result.push_back(record[numbers[i]]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.twoSum(firstData, secondData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("secondData", secondData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
    vector<int> first;
    int second;
    vector<int> expectAns;


    first = {7,11,2,15};
    second = 9;
    expectAns = {0,2};
    test(expectAns, first, second);

    first = {2,7,11,15};
    second =17;
    expectAns = {0,3};
    test(expectAns, first, second);


    return 0;
}
