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



int max_element_in_a_binary_tree(binary_tree_node *root, int &maxi = *(new int(0)))
{
    if (root)
    {
        max_element_in_a_binary_tree(root->left, maxi);
        maxi = max(maxi, root->data);
        // cout<<maxi<<" ";
        max_element_in_a_binary_tree(root->right, maxi);
    }

    return maxi;
}

void construct_a_binary_tree(binary_tree_node *root) // Assuming the user is passing a constructed node of a binary tree
{
    if (!root)
    {
        return;
    }
    int left_data, right_data;
    cout << "enter the value for the " << root << " " << root->data << " node's Left Child" << " ";
    cin >> left_data;
    cout << "enter the value for the " << root << " " << root->data << " node's Right Child" << " ";
    cin >> right_data;

    // processing the left subtree now

    if (left_data == 0)
    {
        root->left = NULL;
    }

    else
    {
        binary_tree_node *left_node = new binary_tree_node(left_data);
        root->left = left_node;
        construct_a_binary_tree(root->left); // Recursive call to the left subtree
    }

    // Proccesing the right subtree now
    if (right_data == 0)
    {
        root->right = NULL;
    }
    else
    {
        binary_tree_node *right_node = new binary_tree_node(right_data);
        root->right = right_node;
        construct_a_binary_tree(root->right); // recursive call to the right subtree
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

void breadth_first_traversal(binary_tree_node *root)
{
    queue<binary_tree_node *> my_queue;

    if (root == NULL)
    {
        cout << "root == NULL" << endl;
        return;
    }

    my_queue.push(root);

    while (!my_queue.empty())
    {
        binary_tree_node *curr_node = my_queue.front();
        my_queue.pop();

        cout << curr_node->data << " ";

        if (curr_node->left)
        {
            my_queue.push(curr_node->left);
        }
        if (curr_node->right)
        {
            my_queue.push(curr_node->right);
        }
    }
}

void insert_in_a_binary_tree(binary_tree_node *root, int data)
{
    queue<binary_tree_node *> my_queue;

    if (root == NULL)
    {
        cout << "root == NULL" << endl;
        return;
    }

    my_queue.push(root);

    while (!my_queue.empty())
    {
        binary_tree_node *curr_node = my_queue.front();
        my_queue.pop();

        if (curr_node->left == NULL)
        {
            binary_tree_node *newnode = new binary_tree_node(data);
            curr_node->left = newnode;
            return;
        }
        if (curr_node->right == NULL)
        {
            binary_tree_node *newnode = new binary_tree_node(data);
            curr_node->right = newnode;
            return;
        }

        my_queue.push(curr_node->left);
        my_queue.push(curr_node->right);
    }
}

int size_of_binary_tree_recursive_postorder(binary_tree_node *root, int &count = *(new int(0)))
{
    if (root)
    {
        size_of_binary_tree_recursive_postorder(root->left,count);
        size_of_binary_tree_recursive_postorder(root->right,count);
        count++;
    }

    return count;
}


int size_of_binary_tree(binary_tree_node *root)
{
    // This is also a valid recursive implementation

    // if (root == NULL)
    // {
    //     return 0;
    // }

    // return size_of_binary_tree(root->left) + 1 + size_of_binary_tree(root->right);

    // 2nd implementation below will be using tree traversal method (BFS) maintaining a count variable for each node

    // queue<binary_tree_node *> my_queue;
    // int count = 0;

    // if (root == NULL)
    // {
    //     cout << "root == NULL" << endl;
    //     return 0;
    // }

    // my_queue.push(root);

    // while (!my_queue.empty())
    // {
    //     binary_tree_node *curr_node = my_queue.front();
    //     my_queue.pop();

    //     // std::cout << "Counting node with value: " << curr_node->data << std::endl;
    //     count++;

    //     if (curr_node->left)
    //     {
    //         my_queue.push(curr_node->left);
    //         // count++;
    //     }
    //     if (curr_node->right)
    //     {
    //         my_queue.push(curr_node->right);
    //         // count++;
    //     }
    // }

    // return count;

    // 3rd implementation Recursive function

    int ans = size_of_binary_tree_recursive_postorder(root);
    return ans;

}

void reverse_order_BFS_traversal(binary_tree_node *root)
{
    queue<binary_tree_node *> my_queue;
    stack<binary_tree_node *> my_stack;

    if (root == NULL)
    {
        cout << "root == NULL" << endl;
        return;
    }

    my_queue.push(root);

    while (!my_queue.empty())
    {
        binary_tree_node *curr_node = my_queue.front();
        my_queue.pop();

        if (curr_node->right)
        {
            my_stack.push(curr_node->right);
            my_queue.push(curr_node->right);
        }

        if (curr_node->left)
        {
            my_stack.push(curr_node->left);
            my_queue.push(curr_node->left);
        }
    }

    while (!my_stack.empty())
    {
        cout << my_stack.top()->data << " ";
        my_stack.pop();
    }
}

int main()
{
    // Binary-Tree Part
    binary_tree_node *ROOT = new binary_tree_node(12);
    construct_a_binary_tree(ROOT); // Constructs a binary tree taking root as an input

    // insert_in_a_binary_tree(ROOT, 80);  // Inserting 80
    // insert_in_a_binary_tree(ROOT, 90);  // Inserting 90
    // insert_in_a_binary_tree(ROOT, 100); // Inserting 100

    cout << "\npre-order traversal of the new tree is ";
    pre_order_traversal_recursive(ROOT);

    cout << "\nbreadth-first traversal of the new tree is ";
    breadth_first_traversal(ROOT);

    cout << "\nReverse Order of BFS Traversal is ";
    reverse_order_BFS_traversal(ROOT);

    cout << "\n size of the binary tree is " << size_of_binary_tree(ROOT);
    cout << "\nmax element of the input array is " << max_element_in_a_binary_tree(ROOT) << endl;

    // BST-PART
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
    cout << endl;

    cout << "Maximum element in this binary tree is " << max_element_in_a_binary_tree(root) << endl;
}