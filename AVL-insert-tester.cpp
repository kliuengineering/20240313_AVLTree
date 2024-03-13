#include <iostream>
using namespace std;

// Structure for AVL tree node
struct AVLTreeNode 
{
    int data;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;
};

// Function to create a new node with given key
AVLTreeNode* createNode(int key) 
{
    AVLTreeNode* newNode = new AVLTreeNode();
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Function to get the height of a node
int getHeight(AVLTreeNode* node) 
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(AVLTreeNode* node) 
{
    if (node == nullptr)
        return 0;
    return  (getHeight(node->left) - getHeight(node->right));
}

// Function to update the height of a node
void updateHeight(AVLTreeNode* node) 
{
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform left rotation
AVLTreeNode* leftRotate(AVLTreeNode* x) 
{
    AVLTreeNode* y = x->right;
    AVLTreeNode* T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // update()
    updateHeight(x);
    updateHeight(y);
    

    return y;
}
// Function to perform right rotation
AVLTreeNode* rightRotate(AVLTreeNode* y) 
{
    AVLTreeNode* x = y->left;
    AVLTreeNode* T2 = x->right; 

    // rotation
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}


// Function to perform right-left rotation
AVLTreeNode * rightleftRotate(AVLTreeNode * y) 
{
    y->right = rightRotate(y->right);
    return leftRotate(y);

}

// Function to perform left-right rotation
AVLTreeNode* leftrightRotate(AVLTreeNode* y) 
{
    y->left = leftRotate(y->left);
    return rightRotate(y);

}


// Function to insert a key into AVL tree
AVLTreeNode* insert(AVLTreeNode* root, int key) 
{
    // Perform normal BST insertion
    if (root == nullptr)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // No duplicates allowed

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor of this node
    int balance = getBalance(root);

    //// Left Left Case
    //if (balance > 1 && key < root->left->data)
    //   

    //// Right Right Case
    //if (balance < -1 && key > root->right->data)
    //    

    //// Left Right Case
    //if (balance > 1 && key > root->left->data) {
    //    
    //}

    //// Right Left Case
    //if (balance < -1 && key < root->right->data) {
    //   
    //}

    return root;
}

// Function to print in-order traversal of AVL tree
void inOrderTraversal(AVLTreeNode* root) 
{
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " " << endl;
    inOrderTraversal(root->right);
}


// Function to print spaces
void printSpaces(int numSpaces) 
{
    for (int i = 0; i < numSpaces; ++i)
        cout << " ";
}
// Function to print a tree recursively
void printTree(AVLTreeNode* root, int level, int spaces) 
{
    if (root == nullptr)
        return;

    // Print right child first
    printTree(root->right, level + 1, spaces);

    // Print current node after appropriate spaces
    printSpaces(level * spaces);
    cout << root->data <<  endl;

    // Print left child
    printTree(root->left, level + 1, spaces);
}

// Main function
int main() 
{
    AVLTreeNode* root = nullptr;
    int array1[6] = { 100, 250, 200, 300, 400, 500 };

    for (int i = 0; i < 6; i++) {
        // Insert elements into AVL tree
        cout << endl << "Add a new node:" << array1[i] << endl;
        root = insert(root, array1[i]);
        // Print tree structure
        cout << endl << endl << "Print AVL Tree structure:" << endl;
        printTree(root, 0, 4);
        cout << endl << "---------------------------------------------";
    }

    // Print in-order traversal of AVL tree
    cout << endl << "In-order traversal of AVL tree after insertions: " << endl;
    inOrderTraversal(root);
    cout << endl;
    int array2[3] = { 111, 211, 311 };

    for (int i = 0; i < 3; i++) 
    {
        // Insert elements into AVL tree
        cout << endl << "Add a new node:" << array2[i] << endl;
        root = insert(root, array2[i]);
        // Print tree structure
        cout << endl << endl << "Print AVL Tree structure:" << endl;
        printTree(root, 0, 4);
        cout << endl << "---------------------------------------------";
    }
  

    // Print in-order traversal of AVL tree
    cout << endl << "In-order traversal of AVL tree after insertions: " << endl;
    inOrderTraversal(root);
    cout << endl;
   
    return 0;
}
