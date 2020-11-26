/**
 * 给定一个链表，判断链表是否有环
 * [https://leetcode-cn.com/problems/linked-list-cycle/]
 * 环路起点
 * [https://leetcode-cn.com/problems/linked-list-cycle-lcci/]
 **/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        while (q != nullptr)
        {
            p = p->next;
            q = q->next;
            if (q != nullptr)
            {
                q = q->next;
            }
            else
            {
                return false;
            }
            if (p == q)
            {
                return true;
            }
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        while (true)
        {
            p = p->next;
            q = q->next;
            if (q != nullptr && q->next != nullptr)
            {
                q = q->next;
            }
            else
            {
                return nullptr;
            }
            if (p == q)
            {
                p = head;
                break;
            }
        }
        while (true)
        {
            if (p == q)
            {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};