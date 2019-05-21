/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* right = pListHead;
        if(right == NULL) return nullptr;  // special case
        for(int i = 0; i < k-1; i++)  {
            // first right go off k
            right = right->next;
            if(right == NULL)  {
                return nullptr;
            }
        }
        
        ListNode* left = pListHead;
        
        while(right->next) {
            right = right->next;
            left = left->next;
        }
        
        return left;
        

    }
};
