/*
Question-

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

*/

// 1st approach (hashing)

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        unordered_map<int,int>Nodemap;
        Node *temp = head;
        int i = 0;
        
        while(temp)
        {
            Nodemap[temp->data] = i;
            i++;
            temp = temp->next;
        }
        
        temp = head;
        i = 0;
        while(temp)
        {
            auto it = Nodemap.find(target - temp->data);
            
            if(it != Nodemap.end() && it->second > i)
            {
                ans.emplace_back(temp->data,it->first);
            }
            
            i++;
            temp = temp->next;
        }
        
        return ans;
    }
};

// 2nd approach (two-pointers)



class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>>ans;
        Node *temp = head;
        Node *end;
        Node *start;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        end = temp;
        start = head;
        
        while(start != end)
        {
            int data = start->data + end->data;
            
            if(data == target)
            {
                ans.emplace_back(start->data,end->data);
                start = start->next;
                // end = end->prev;
            }
            else if(data > target)
            {
                end = end->prev;
            }
            else
            {
                start = start->next;
            }
        }
        
        return ans;
    }
};