/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-26 20:02:17 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-26 20:40:40
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

/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution
{
public:
   vector<vector<int>>  pascalsTriangle(int num_rows)  {
       vector<vector<int>> res;
       if(num_rows == 0)  {
           return res;
       } 

       vector<int> row_n;
       row_n.push_back(1);
       res.push_back(row_n);

      // f(x, y) = f(x-1, y -1) + f(x-1, y)
      for(int i = 1; i < num_rows; i++)  {
          vector<int> row_temp;
          row_temp.push_back(1);
          vector<int> row_last = res[i - 1];
          for(int j = 1; j < i ; j++)  {
             row_temp.push_back(row_last[j] + row_last[j - 1]);
         }
          row_temp.push_back(1);
          res.push_back(row_temp);
      } 
      return res;
       
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType &expectAns, dataType1 &data, dataType2 K = dataType2())
{
    Solution work;
    ansType ans;
    ans = work.pascalsTriangle(data);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if (!check) {
        printf("index %d: NO\n", index);
        output("data", data);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");
}

int main()
{
    int data;
    vector<vector<int>> expectAns;


    data = 5;
    expectAns = {
        {1},
        {1,1},
        {1,2,1},
        {1,3,3,1},
        {1,4,6,4,1}
    };
    test(expectAns, data);

    data = 3;
    expectAns = {
        {1},
        {1,1},
        {1,2,1}
    };
    test(expectAns, data);

    data = 1;
    expectAns = {
        {1}
    };
    test(expectAns, data);



    return 0;
}
