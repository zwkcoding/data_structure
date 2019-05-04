/*
 * Filename: /home/zwk/code/data_structrue/c++/bsearch/bsearch_varients.hpp
 * Path: /home/zwk/code/data_structrue/c++/bsearch
 * Created Date: Saturday, May 4th 2019, 9:26:34 pm
 * Author: zwk
 * 
 * ref to: https://github.com/wangzheng0822/algo/blob/master/c-cpp/16_bsearch/bsearch_varients.hpp
 */

#ifndef BSEARCH_BSEARCH_VARIENTS_HPP_
#define BSEARCH_BSEARCH_VARIENTS_HPP_

#include <functional>
#include <iterator> 

enum class BsearchPolicy
{
    UNSPECIFIED,
    FIRST,
    LAST,
    FIRST_NOT_LESS,
    LAST_NOT_GREATER
};

// Liam Huang: The algorithm works right with iterators that meet the ForwardIterator requirement,
//             but with a bad time complexity. For better performance, iterators should meet
//             the RandomAccessIterator requirement.
template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare>
IterT bsearch(IterT first, IterT last, ValueT target, Compare comp, BsearchPolicy policy = BsearchPolicy::UNSPECIFIED)  {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
        if (policy == BsearchPolicy::FIRST_NOT_LESS) {    // 查找第一个大于等于给定值的元素
            if (!comp(*mid, target)) {
                if (mid == first or comp(*(mid - 1), target)) {
                    result = mid;
                    break;
                } else {
                    last = mid;
                }
            } else {
                first = mid + 1;
            }
        } else if(policy == BsearchPolicy::LAST_NOT_GREATER)  {     // 查找最后一个小于等于给定值的元素
             if (comp(target, *mid)) {
                last = mid;
            } else {
                 if (mid == last or comp(target, *(mid +1))) {
                    result = mid;
                    break;
                } else {
                    first = mid + 1;
                }
            }
        } else  {    //  policy == UNSPECIFIED or FIRST or LAST
                if(comp( *mid, target))  {
                    first = mid + 1;
                } else if(comp( target, *mid))  {
                    last = mid;
                } else  {    // equal
                        if(policy == BsearchPolicy::FIRST)  {    // 查找第一个值等于给定值的元素
                            if(mid == first or comp(*(mid - 1), *mid))  {
                                result = mid;
                                break;
                            } else  {
                                last = mid;
                            }
                        } else if(policy == BsearchPolicy::LAST)  {    // 查找最后一个值等于给定值的元素
                            if(mid == last or comp(*mid, *(mid+1)))  {
                                result = mid;
                                break;
                            } else  {
                                first = mid + 1;
                            }
                        } else  {
                            result = mid;
                            break;
                        }
                }
        }
    }
    return result;
}

template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare = std::less<ValueT>>
IterT bsearch(IterT first,
              IterT last,
              ValueT target,
              BsearchPolicy policy =BsearchPolicy::UNSPECIFIED)  {
    return bsearch(first, last, target, Compare(), policy);
}

#endif //  BSEARCH_BSEARCH_VARIENTS_HPP_
