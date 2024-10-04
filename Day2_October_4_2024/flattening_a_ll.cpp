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
    void traverse_all_bottom_nodes(Node *head, int &i,multiset<int> &mymap)
    {
        Node *temp = head;
        while(temp)
        {
            mymap.insert(temp->data);
            i++;
            temp = temp->bottom;
        }
    }
    
    
  public:
    Node * form_a_ll_with_bottom(multiset<int> &mymap)
    {
        Node *dummy_node = new Node(-1);
        Node *curr = dummy_node;
        
        for(auto ele : mymap)
        {
            Node *new_node = new Node(ele);
            curr->bottom = new_node;
            curr = new_node;
        }
        
        return dummy_node->bottom;
    }
    
  public:

    Node *flatten(Node *root) 
    {
        // map<int,int>mymap;
        multiset<int>mymap;
        
        Node *temp = root;
        int i = 1;
        
        while(temp)
        {
            mymap.insert(temp->data);
            i++;
            traverse_all_bottom_nodes(temp->bottom,i,mymap);
            temp = temp->next;
        }
        
        Node *new_root = form_a_ll_with_bottom(mymap);
        
        return new_root;
    }
};
