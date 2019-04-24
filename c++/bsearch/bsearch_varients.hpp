#ifndef BSEARCH_BSEARCH_VARIENTS_HPP_
#define BSEARCH_BSEARCH_VARIENTS_HPP_

#include <iterator>
#include <functional>

enum class BsearchPolicy { UNSPECIFIED, FIRST, LAST, FIRST_NOT_LESS, LAST_NOT_GREATER };

//
template <typename IterT,
                typename ValueT = typename std::iterator_traits<IterT>::value_type,
                typename Compare > 
IterT bsearch(IterT first, IterT last, ValueT target, Compare comp, BsearchPolicy policy = BsearchPolicy::UNSPECIFIED)  {
    IterT result = last;
    while(std::distance(first, last) > 0)  {
        IterT mid = first + std::distance(first, last) / 2;
        if(policy == BsearchPolicy::FIRST_NOT_LESS)  {
            if(!comp(*mid, target))  {
                if(mid == first or comp(*(mid - 1), target))  {
                    result = mid;
                    break;
                } else  {
                    last = mid;
                }
            } else  {
                first = mid + 1;
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
                       BsearchPolicy policy = BsearchPolicy::FIRST_NOT_LESS)  {
                           return bsearch(first, last, target, Compare(), policy);
                       }


#endif    //  BSEARCH_BSEARCH_VARIENTS_HPP_
