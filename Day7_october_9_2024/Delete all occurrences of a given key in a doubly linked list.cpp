//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int key) {
        Node *temp = *head;
        
        while(temp)
        {
            if(temp->data == key)
            {
                if(temp == *head)
                {
                    temp = temp->next;
                    
                    if(temp != NULL)
                        temp->prev = NULL;
                        
                    delete *head;
                    *head = temp;
                }
                else if(temp->next == NULL)
                {
                    if(temp->prev)
                    {
                        temp->prev->next = temp->next;
                        temp = temp->next;
                    }
                    else
                    {
                        delete temp;
                        return;
                    }
                }
                
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    Node *del_node = temp;
                    temp = temp->next;
                    delete del_node;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends