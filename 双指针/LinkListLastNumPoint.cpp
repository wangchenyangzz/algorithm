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
 * [https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/]
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