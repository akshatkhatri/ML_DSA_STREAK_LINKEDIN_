#include <bits/stdc++.h>

using namespace std;

class binary_tree_node
{
public:
    int data;
    binary_tree_node *left;
    binary_tree_node *right;

    binary_tree_node() // default constructor
    {
        data = -1;
        this->left = NULL;
        this->right = NULL;
    }

    binary_tree_node(int data) // para 1 constructor
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    binary_tree_node(int data, binary_tree_node *left, binary_tree_node *right) // Para 2 constructor
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
void pre_order_traversal_recursive(binary_tree_node *root)
{
    if (root)
    {
        cout << root->data << " ";
        pre_order_traversal_recursive(root->left);
        pre_order_traversal_recursive(root->right);
    }
}

void pre_order_traversal_iterative(binary_tree_node *root)
{
    stack<binary_tree_node *> st;

    while (1)
    {
        while (root)
        {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }

        if (st.empty() == true)
        {
            break;
        }
        else
        {
            root = st.top();
            root = root->right;
            st.pop();
        }
    }
}

void in_order_traversal_recursive(binary_tree_node *root)
{
    if (root)
    {
        in_order_traversal_recursive(root->left);
        cout << root->data << " ";
        in_order_traversal_recursive(root->right);
    }
}

void in_order_traversal_iterative(binary_tree_node *root)
{
    stack<binary_tree_node *> st;

    while (1)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        if (st.empty())
        {
            break;
        }
        else
        {
            binary_tree_node *top_node = st.top();
            cout << top_node->data << " ";
            st.pop();
            root = top_node->right;
        }
    }
}

void post_order_recursive(binary_tree_node *root)
{
    if (root)
    {
        post_order_recursive(root->left);
        post_order_recursive(root->right);
        cout << root->data << " ";
    }
}

binary_tree_node *sorted_array_to_BST(const vector<int> &arr, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    binary_tree_node *root = new binary_tree_node(arr[mid]);
    root->left = sorted_array_to_BST(arr, left, mid - 1);
    root->right = sorted_array_to_BST(arr, mid + 1, right);

    return root;
}

int main()
{
        vector<int> arr = {11, 22, 33, 44, 55, 66, 77, 88, 99};
        binary_tree_node *root = sorted_array_to_BST(arr, 0, arr.size() - 1);


        cout << "Pre-order Traversal (Recursive): ";
        pre_order_traversal_recursive(root);
        cout << endl;

        cout << "Pre-order Traversal (Iterative): ";
        pre_order_traversal_iterative(root);
        cout << endl;

        cout << "In-order Traversal (Iterative): ";
        in_order_traversal_iterative(root);
        cout << endl;

        cout << "In-order Traversal (Recursive): ";
        in_order_traversal_recursive(root);
        cout << endl;
        
        cout << "Post-order Traversal (Recursive): ";
        post_order_recursive(root);
        cout<<endl;
}