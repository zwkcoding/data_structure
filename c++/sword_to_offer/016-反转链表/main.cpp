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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)  return nullptr;
        ListNode* pPrev = NULL;
        ListNode* pNode = pHead;
        ListNode* pNext;
        while(pNode != NULL)  {
            pNext = pNode->next;  // keep next node
            pNode->next = pPrev;  // reverse dir
            pPrev = pNode;  // keep last node
            pNode = pNext;  // push current node forward
        }
        return pPrev;
    }
};
