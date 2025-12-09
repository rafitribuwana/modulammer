#include "tree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}

int BinaryTree::getHeight(Node* n) {
    return n ? n->height : 0;
}

int BinaryTree::getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

inline void updateHeight(Node* n) {
    n->height = 1 + max(n->left ? n->left->height : 0,
                        n->right ? n->right->height : 0);
}

Node* BinaryTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* BinaryTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* BinaryTree::insertNode(Node* node, int value) {
    if (!node)
        return new Node{ value, nullptr, nullptr, 1 };

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    else
        return node;

    updateHeight(node);
    int balance = getBalance(node);

    if (balance > 1) {
        if (value < node->left->data)
            return rotateRight(node);
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1) {
        if (value > node->right->data)
            return rotateLeft(node);
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void BinaryTree::insert(int value) {
    root = insertNode(root, value);
}

Node* BinaryTree::minValueNode(Node* node) {
    while (node->left) node = node->left;
    return node;
}

Node* BinaryTree::deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0)
            return rotateRight(root);
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1) {
        if (getBalance(root->right) <= 0)
            return rotateLeft(root);
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void BinaryTree::deleteValue(int value) {
    root = deleteNode(root, value);
}

void BinaryTree::update(int oldVal, int newVal) {
    deleteValue(oldVal);
    insert(newVal);
}

void BinaryTree::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BinaryTree::preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BinaryTree::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void BinaryTree::inorder()  { inorder(root); cout << endl; }
void BinaryTree::preorder() { preorder(root); cout << endl; }
void BinaryTree::postorder(){ postorder(root); cout << endl; }