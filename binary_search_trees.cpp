#include <iostream>
using namespace std;
// Define a BST Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// a) Creation: Create a new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// b) Insertion
Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
// c) Find Minimum
Node *findMin(Node *root)
{
    while (root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}
// d) Find Maximum
Node *findMax(Node *root)
{

    while (root != nullptr && root->right != nullptr)
        root = root->right;
    return root;
}
// e) Delete Element
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with one or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// f) Post-order Traversal
void postOrder(Node *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// g) Pre-order Traversal
void preOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// h) In-order Traversal
void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = nullptr;

    // Insert elements
    int elements[] = {50, 30, 20, 40, 70, 60, 80};

    for (int i = 0; i < 7; i++)
    {
        root = insert(root, elements[i]);
    }

    cout << "Binary Search Tree Created Successfully\n\n";

    cout << "In-Order Traversal (Sorted Order): ";
    inOrder(root);

    cout << "\nPre-Order Traversal: ";
    preOrder(root);

    cout << "\nPost-Order Traversal: ";
    postOrder(root);

    cout << "\n\nMinimum Element: "
         << findMin(root)->data;

    cout << "\nMaximum Element: "
         << findMax(root)->data;

    // Delete leaf node
    cout << "\n\nDeleting Leaf Node (20)...\n";
    root = deleteNode(root, 20);

    cout << "In-Order Traversal: ";
    inOrder(root);

    // Delete node with one child
    cout << "\n\nDeleting Node With One Child (30)...\n";
    root = deleteNode(root, 30);

    cout << "In-Order Traversal: ";
    inOrder(root);

    // Delete node with two children
    cout << "\n\nDeleting Node With Two Children (50)...\n";
    root = deleteNode(root, 50);

    cout << "In-Order Traversal: ";
    inOrder(root);

    cout << "\n\nFinal BST Traversals\n";

    cout << "In-Order: ";
    inOrder(root);

    cout << "\nPre-Order: ";
    preOrder(root);

    cout << "\nPost-Order: ";
    postOrder(root);

    cout << endl;

    return 0;
}