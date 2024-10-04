/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    int size_of_ll(ListNode *head)
    {
        ListNode *temp = head;
        int size = 0;
        while(temp)
        {
            temp = temp->next;
            size++;
        }

        return size;

    }

public:
    ListNode* place_fast_ptr(ListNode *head, int k)
    {
        int i = 0;
        ListNode *fast = head;
        while(i != k)
        {
            fast = fast->next;
            i++;
        }

        return fast;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        int n = size_of_ll(head);

        k = k % n; // rotating a 3 sized list 4 times means the same as rotating it 1 time
        if(k == 0)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = place_fast_ptr(head,k);

        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *new_head = slow->next;
        fast->next = head;
        slow->next = NULL;

        head = new_head;

        return head;
    }
};