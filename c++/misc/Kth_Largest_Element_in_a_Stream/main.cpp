#include "../../include/base.h"

/// 
/// Time Complexity: 
/// Space Complexity: 
class KthLargest {
private:
    priority_queue<int, vector<int>, std::greater<int> > prior_que;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto x : nums)  {
            prior_que.push(x);
            if(prior_que.size() > k) {
                prior_que.pop();
            }
        }
        size = k;
    }

    int add(int val) {
        prior_que.push(val);
        prior_que.pop();
        return prior_que.top(); 
    }

};


int main() {
    int k = 3;
    vector<int> arr = {4,5,8,2};
    KthLargest* obj = new KthLargest(k, arr);
    std::cout << obj->add(3) << std::endl;      // returns 4
    std::cout << obj->add(5) << std::endl;      // returns 5
    std::cout << obj->add(10) << std::endl;      // returns 5
    std::cout << obj->add(9) << std::endl;      // returns 8
    std::cout << obj->add(4) << std::endl;      // returns 8


    return 0;
}
