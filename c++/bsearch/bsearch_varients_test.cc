#include <iostream>
#include <vector>

#include "bsearch_varients.hpp"

template <typename VecT, typename T = typename VecT::value_type>
void test_bsearch(const VecT& test, T target, BsearchPolicy policy = BsearchPolicy::FIRST_NOT_LESS)  {
    auto it = bsearch(test.begin(), test.end(), target, policy);
    std::cout << std::distance(test.begin(), it) << std::endl;
}

int main()  {
    std::vector<int> test{0, 0, 1, 2, 3, 4, 4, 5 , 5, 5, 5, 5, 6, 8};

    test_bsearch(test, 0);
    test_bsearch(test, -1);

    return 0;
}
