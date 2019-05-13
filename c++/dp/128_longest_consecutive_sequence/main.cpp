/*
 * Filename: /home/zwk/code/data_structrue/c++/dp/128_longest_consecutive_sequence/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/dp/128_longest_consecutive_sequence
 * Created Date: Monday, May 13th 2019, 8:24:08 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"
#include <array>


/// Time Complexity:  O(n) 
/// Space Complexity: O(n). 

class Solution {

public:
/*
    int longestConsecutive(vector<int>& nums)  {
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 1;
        for(int n : nums){
               if(record.find(n) == record.end()) continue;
               record.erase(n);
                int prev = n-1,next = n+1;
               while(record.find(prev) != record.end())  {record.erase(prev); prev--;}
               while(record.find(next) != record.end())  {record.erase(next); next++;}
               res = std::max(res, next - prev - 1);
        }
        return res;
    }
*/

    int longestConsecutive(vector<int>& nums)  {
        unordered_map<int, int> record;
        int res = 0;
        for(int n : nums)  {
           res = std::max(res, record[n] = record[n + record[n+1]] = record[n - record[n-1]] = record[n+1] + record[n-1] + 1);
        }
        return res;
    }

};


int main() {
    vector<int> first;
    int second;
    int ans, expectAns;

    first.clear();
    first.push_back(100);
    first.push_back(4);
    first.push_back(200);
    first.push_back(1);
    first.push_back(3);
    first.push_back(2);
    expectAns = 4;
    TEST_SMP1(Solution, longestConsecutive, expectAns, first);



    return 0;
}
