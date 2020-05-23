#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
};

bool IsBST(Node* node) {
    if (not node) {
        return true;
    }
    bool leftOk = node->left ? node->left->value < node->value : true;
    bool rightOk = node->right ? node->right->value >= node->value : true;
    return leftOk and rightOk and IsBST(node->left) and IsBST(node->right);
}

bool Test() {
    {
        Node* a0 = new Node(); a0->value = 0;
        Node* a1 = new Node(); a1->value = 1;
        Node* a2 = new Node(); a2->value = 2;
        Node* a3 = new Node(); a3->value = 3;
        Node* a4 = new Node(); a4->value = 4;

        a0->left = a1;
        a1->left = a2;
        a2->left = a3;
        a3->left = a4;

        if (IsBST(a0)) {
            return false;
        }
    }
    {
        Node* a0 = new Node(); a0->value = 0;
        Node* a1 = new Node(); a1->value = 1;
        Node* a2 = new Node(); a2->value = 2;
        Node* a3 = new Node(); a3->value = 3;
        Node* a4 = new Node(); a4->value = 4;

        a4->left = a3;
        a3->left = a2;
        a2->left = a1;
        a1->left = a0;

        if (not IsBST(a4)) {
            return false;
        }
    }
    {
        Node* a0 = new Node(); a0->value = 0;
        Node* a1 = new Node(); a1->value = 1;
        Node* a2 = new Node(); a2->value = 2;
        Node* a3 = new Node(); a3->value = 3;
        Node* a4 = new Node(); a4->value = 4;

        a2->left = a0;
        a0->right = a1;
        a2->right = a4;
        a4->left = a3;

        if (not IsBST(a2)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}