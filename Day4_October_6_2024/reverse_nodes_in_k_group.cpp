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
    ListNode* reverse_a_ll(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr)
        {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

public:
    ListNode* getKthNode(ListNode *head, int k)
    {
        ListNode *temp = head;
        int i = 1;
        while(temp != NULL && i != k)
        {
            temp = temp->next;
            i++;
        }

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *prev_node = NULL;
        ListNode *temp = head;

        while(temp)
        {
            ListNode * k_th_node = getKthNode(temp,k);
            if(k_th_node == NULL)
            {
                prev_node->next = temp;
                break;
            }
            ListNode * next_node = k_th_node->next;
            k_th_node->next = NULL;

            if(prev_node == NULL)
            {
                head = reverse_a_ll(temp);
                prev_node = temp;
                temp = next_node;
            }
            else
            {
                ListNode * first_node = reverse_a_ll(temp);
                prev_node -> next = first_node;
                prev_node = temp;
                temp = next_node;
            }
        }

        return head;
    }
};