#include <bits/stdc++.h>

using namespace std;

class binary_tree
{
    public: int data;
    binary_tree * left;
    binary_tree * right;

    void pre_order_traversal_recursive(binary_tree * root)
    {
        if (root)
        {
            cout << root -> data << " ";
            pre_order_traversal_recursive(root -> left);
            pre_order_traversal_recursive(root -> right);
        }
    }

    void pre_order_traversal_iterative(binary_tree * root)
    {
        stack < binary_tree * > st;

        while (1)
        {
            while (root)
            {
                cout << root -> data << " ";
                st.push(root);
                root = root -> left;
            }

            if (st.empty() == true)
            {
                break;
            }
            else
            {
                root = st.top();
                root = root -> right;
                st.pop();
            }
        }

    }
   
    void in_order_traversal_recursive(binary_tree *root)
    {
        if(root)
        {
            in_order_traversal_recursive(root->left);
            cout<<root->data<<" ";
            in_order_traversal_recursive(root->right);
        }
    }
   
    void in_order_traversal_iterative(binary_tree *root)
    {
        stack<binary_tree *>st;
       
        while(1)
        {
            while(root)
            {
                st.push(root);
                root = root -> left;
            }
           
            if(st.empty())
            {
                break;
            }
            else
            {
                binary_tree* top_node = st.top();
                st.pop();
                root = top_node->right;
            }
        }
    }

    void post_order_recursive(binary_tree * root)
    {
        if(root)
        {
            in_order_traversal_recursive(root->left);
            in_order_traversal_recursive(root->right);
            cout<<root->data<<" ";
        }
    }


};

int main() {



}

