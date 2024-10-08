/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    
  public:
    Node * merge_2_sorted_ll(Node *head1, Node *head2)
    {
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        Node *t1 = head1;
        Node *t2 = head2;
        while(t1 && t2)
        {
            if(t1->data <= t2->data)
            {
                curr->bottom = t1;
                curr = t1;
                t1 = t1->bottom;
            }
            else
            {
                curr->bottom = t2;
                curr = t2;
                t2 = t2->bottom;
            }
        }
        
        if(t1)
        {
           curr->bottom = t1;
        }
        if(t2){
            curr->bottom = t2;
        }
        
        return dummy->bottom;
    }
    
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root == NULL || root->next == NULL)
        {
            return root;
        }
        Node *head2 = root->next;
        root = merge_2_sorted_ll(root,head2);
        head2 = head2->next;
        
        while(head2)
        {
            root = merge_2_sorted_ll(root,head2);
            head2 = head2->next;
        }
        
        return root;
    }
};
