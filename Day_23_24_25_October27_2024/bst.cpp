#include <bits/stdc++.h>
using namespace std;

class bst_node
{
public:
    int data;
    bst_node *left;
    bst_node *right;

    bst_node() // default constructor
    {
        data = -1;
        this->left = NULL;
        this->right = NULL;
    }

    bst_node(int data) // para 1 constructor
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    bst_node(int data, bst_node *left, bst_node *right) // Para 2 constructor
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void in_order_traversal_recursive(bst_node *root)
{
    if (root)
    {
        in_order_traversal_recursive(root->left);
        cout << root->data << " ";
        in_order_traversal_recursive(root->right);
    }
}

void pre_order_traversal_recursive(bst_node *root)
{
    if (root)
    {
        cout << root->data << " ";
        pre_order_traversal_recursive(root->left);
        pre_order_traversal_recursive(root->right);
    }
}

bst_node *initialize_a_dummy_tree() // Assign a bunch of hardcoded nodes for testing purposes
{
    bst_node *my_root_lchild_rchild = new bst_node(5, NULL, NULL);
    bst_node *my_root_lchild_lchild = new bst_node(2, NULL, NULL);
    bst_node *my_root_rchild = new bst_node(9, NULL, NULL);
    bst_node *my_root_lchild = new bst_node(4, my_root_lchild_lchild, my_root_lchild_rchild);
    bst_node *my_root = new bst_node(7, my_root_lchild, my_root_rchild);

    return my_root;
}

bool search_element_in_a_bst_iterative(bst_node *root, int target)
{
    bst_node *temp = root;

    while (temp)
    {
        if (temp->data == target)
        {
            cout << "Found Data " << temp->data << endl;
            return true;
        }

        if (temp->data < target)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    cout << "element not found" << endl;
    return false;
}

bst_node *find_minimum_in_a_bst_recursive(bst_node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL)
    {
        return root;
    }

    return find_minimum_in_a_bst_recursive(root->left);
}

bst_node *find_minimum_in_a_bst_iterative(bst_node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    bst_node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

bst_node *find_maximum_in_a_bst_recursive(bst_node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->right == NULL)
    {
        return root;
    }

    return find_maximum_in_a_bst_recursive(root->right);
}

bst_node *insert_a_node_in_a_bst(bst_node *root, int data)
{
    if (root == nullptr)
    {
        return new bst_node(data);
    }

    bst_node *my_node = new bst_node(data);
    bst_node *temp = root;

    while (temp)
    {
        if (data == temp->data)
        {
            cout << "Duplicate value can't insert it" << endl;
            return root;
        }

        if (data > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = my_node;
                return root;
            }

            temp = temp->right;
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = my_node;
                return root;
            }
            temp = temp->left;
        }
    }

    return root;
}

bst_node *insert_in_a_bst_recursive(bst_node *root, int target)
{
    if (root == NULL)
    {
        return new bst_node(target);
    }

    if (target < root->data)
        root->left = insert_in_a_bst_recursive(root->left, target);

    else if (target > root->data)
        root->right = insert_a_node_in_a_bst(root->right, target);

    else
    {
        cout << "DUplicate entries not allowed" << endl;
        return root;
    }

    return root;
}

bst_node *delete_a_node_in_a_bst(bst_node *root, int target)
{
    bst_node *curr = root;
    bst_node *parent = NULL;

    while (curr)
    {
        if (curr->data == target)
        {
            break;
        }

        parent = curr;

        if (curr->data < target)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    if(curr == NULL)
    {
        cout<<"No Node to be deleted can be found"<<endl;
        return root;
    }

    if (curr->left == NULL && curr->right == NULL) // It is a leaf node a node with no child
    {
        if (curr == root)
        {
            delete curr;
            return NULL;
        }

        if (parent->left == curr)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        delete curr;
    }

    else if (curr->left == NULL || curr->right == NULL) // Node with only one child
    {
        if (curr == root)
        {
            root = curr->left != NULL ? curr->left : curr->right;
        }

        else if (parent->left == curr)
        {
            if (curr->left != NULL)
            {
                parent->left = curr->left;
            }
            else
            {
                parent->left = curr->right;
            }
        }

        else
        {
            if (curr->left != NULL)
            {
                parent->right = curr->left;
            }
            else
            {
                parent->right = curr->right;
            }
        }
        delete curr;
    }

    else // Node with both children present
    {
        // bst_node * in_order_predecessor = find_maximum_in_a_bst_recursive(curr->left);
        // bst_node * in_order_succesor = find_minimum_in_a_bst_recursive(curr->right);

        bst_node *in_order_predecessor = curr->left;
        bst_node *in_order_predecessor_parent = curr;

        while (in_order_predecessor->right != NULL)
        {
            in_order_predecessor_parent = in_order_predecessor;
            in_order_predecessor = in_order_predecessor->right;
        }

        curr->data = in_order_predecessor->data; // you can also use in_order_succesor it is a personal choice
        in_order_predecessor_parent->left == in_order_predecessor? in_order_predecessor_parent->left = NULL : in_order_predecessor_parent->right = NULL;

        delete in_order_predecessor;
    }

    return root;
}

bst_node * find_LCA_of_two_nodes_iterative(bst_node *root, int alpha, int beta) // It is assumed that both alpha and beta are inside the tree
{
    while(1)
    {
        if(root->data == alpha || root->data == beta || (alpha < root->data && root->data < beta) || (alpha > root->data && root->data > beta)) // a node is an ancestor of itself
        {
            return root;
        }

        if(root->data < alpha && root->data < beta)
        {
            root = root->right;
        }

        else
        {
            root = root->left;
        }
    }

    return root;
}

bool is_tree_bst(bst_node *root,bst_node *prev = NULL)
{
    if(!is_tree_bst(root->left,prev))
    {
        return false;
    } 
    
}

/*
// TREE REPRESENTATION
    7
   / \
  4   9
 / \
2   5

*/

int main()
{
    bst_node *my_root = initialize_a_dummy_tree();
    search_element_in_a_bst_iterative(my_root, 11);
    search_element_in_a_bst_iterative(my_root, 2);

    cout << "Minimum element is " << find_minimum_in_a_bst_iterative(my_root)->data << " And " << find_minimum_in_a_bst_recursive(my_root)->data << endl;
    cout << "Maximum element is " << find_maximum_in_a_bst_recursive(my_root)->data << endl;

    bst_node *new_root = insert_a_node_in_a_bst(my_root, 11);
    new_root = insert_in_a_bst_recursive(my_root, 10);
    new_root = insert_in_a_bst_recursive(my_root, 8);

    new_root = delete_a_node_in_a_bst(my_root,7);

    cout << "pre order_traveral is ";
    pre_order_traversal_recursive(new_root);

    cout<<"\nLCA OF NODES IS "<<find_LCA_of_two_nodes_iterative(new_root,9,4)->data;
    
    cout<<"\nInorder Traversal is "; in_order_traversal_recursive(my_root);

    return 0;
}