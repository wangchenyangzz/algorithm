/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 链表中倒数第k个节点
 **/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * pFirst = head;
        ListNode * pLast = head;
        int i = 0;
        while (pFirst != nullptr)
        {
            if (i < k)
            {
                pFirst = pFirst->next;
            } else {
                pFirst = pFirst->next;
                pLast = pLast->next;
            }
            i++;
        }
        return pLast;
    }
};