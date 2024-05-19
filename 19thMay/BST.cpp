/*
* Trees are non-linear data structures that are used to store data in a hierarchical manner.
* A tree is a collection of nodes connected by directed (or undirected) edges, with the topmost node known as the root.
* The nodes in a tree are called vertices. The lines that connect them are called edges.
* A tree is a special type of graph, and the key difference between a tree and a graph is that a tree cannot contain cycles.
* A binary tree is a tree in which each node has at most two children, which are referred to as the left child and the right child.
* A binary search tree (BST) is a binary tree in which the value of each node is larger than the values in all nodes in that node's left subtree and is smaller than the values in all nodes in that node's right subtree.
* Let's consider the following example:
*         10
*        /  \
*       5    15
*      / \   / \
*     3   7 12  18
* In the above example, 10 is the root node, and 5 and 15 are its children. 3, 7, 12, and 18 are the children of 5, 7, 12, and 18, respectively.
* The tree is a binary search tree because the value of each node is larger than the values in all nodes in that node's left subtree and is smaller than the values in all nodes in that node's right subtree.
*/

// Binary Search Tree (BST) implementation in C++

#include <iostream>
#include <string>

using namespace std;

// Define the structure of the node
struct Node {
    int data;
    Node* left;
    Node* right;
};
// This is called a linked list, which consists of a data field and two pointers to the left and right children.

class BST {
public:
    // Declare the root node
    Node* root;

    // Constructor
    BST() {
        root = NULL;
    }

    // Helper functions
    Node* insert(int data, Node* root) {
        // If the tree is empty, create a new node and set it as the root
        if (root == NULL) {
            root = new Node();
            root->data = data;
            root->left = root->right = NULL;
        }
        // If the data is less than the root, insert it into the left subtree
        else if (data < root->data) {
            root->left = insert(data, root->left);
        }
        // If the data is greater than the root, insert it into the right subtree
        else {
            root->right = insert(data, root->right);
        }
        return root;
    }

    Node* search(int data, Node* root) {
        // If the tree is empty or the data is not found, return NULL
        if (root == NULL || root->data == data) {
            return root;
        }
        // If the data is less than the root, search the left subtree
        else if (data < root->data) {
            return search(data, root->left);
        }
        // If the data is greater than the root, search the right subtree
        else {
            return search(data, root->right);
        }
    }

    Node* findMin(Node* root) {
        // Traverse the left subtree to find the minimum value
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* findMax(Node* root) {
        // Traverse the right subtree to find the maximum value
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    Node* remove(int data, Node* root) {
        // If the tree is empty, return NULL
        if (root == NULL) {
            return root;
        }
        // If the data is less than the root, remove it from the left subtree
        if (data < root->data) {
            root->left = remove(data, root->left);
        }
        // If the data is greater than the root, remove it from the right subtree
        else if (data > root->data) {
            root->right = remove(data, root->right);
        }
        // If the data is equal to the root, delete the node
        else {
            // If the node has only one child or no child
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // If the node has two children, find the minimum value in the right subtree
            // and replace the current value with the minimum value
            // (Note: the maximum value in the left subtree can also be used)
            Node* temp = findMin(root->right);
            // Copy the minimum value to the root
            root->data = temp->data;
            // Remove the minimum value from the right subtree
            root->right = remove(temp->data, root->right);
        }
        return root;
    }

    // Sorting functions
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void print() {
        print("", root, false, true);
    }

    void print(const string &prefix, Node *parent, bool isLeft, bool isRoot) {
        if (parent == NULL)
            return;
        if (isRoot) {
            cout << "─────";
        } else {
            cout << prefix << (isLeft ? "L├────" : "R└───");
        }
        cout << parent->data << endl;

        print(prefix + (isLeft ? " │   " : "    "),
            parent -> left, true, false);
        print(prefix + (isLeft ? " │   " : "    "),
            parent -> right, false, false);
    }
};


int main () {
    BST tree;
    tree.root = tree.insert(10, tree.root);
    tree.insert(5, tree.root);
    tree.insert(15, tree.root);
    tree.insert(3, tree.root);
    tree.insert(7, tree.root);
    tree.insert(12, tree.root);
    tree.insert(18, tree.root);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Minimum value: " << tree.findMin(tree.root)->data << endl;
    cout << "Maximum value: " << tree.findMax(tree.root)->data << endl;

    cout << "Pretty print:" << endl;
    tree.print();

    tree.root = tree.remove(5, tree.root);
    cout << "After removing 5:" << endl;
    tree.print();

    return 0;
}