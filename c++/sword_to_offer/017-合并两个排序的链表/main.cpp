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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *head;
        ListNode *left = pHead1;
        ListNode *right = pHead2;

        if(left == NULL)     return right;
        if(right == NULL)    return left;
        
        // 先生成头节点
        if(left->val > right->val)  {
            head = right;
            right = right->next;
        }else {
            head = left;
            left = left->next;
        }
        
        // 遍历
        ListNode *cur = head;
        while(right && left) {
            if(left->val > right->val)  {
                cur->next = right;
                cur = cur->next;
                right = right->next;
            }else {
                cur->next = left;
                cur = cur->next;
                left = left->next;
            }
        }
        
        // 拼接剩下
        if(right)  {
            cur->next = right;
        } else  {
            cur->next = left;
        }
        
        return head;
    }
};
