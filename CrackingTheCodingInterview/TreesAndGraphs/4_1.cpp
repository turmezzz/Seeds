//
// Check if BT is balanced (paths differ no more then 1 one)
//
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int value;
};

bool IsBalancedImpl(Node* node, int& maxDepth, int curDepth) {
    if (node->left) {
        if (not IsBalancedImpl(node->left, maxDepth, curDepth + 1)) {
            return false;
        }
    }
    if (node->right) {
        if (not IsBalancedImpl(node->right, maxDepth, curDepth + 1)) {
            return false;
        }
    }
    if (not node->left and not node->right) {
        if (maxDepth != -1 and abs(maxDepth - curDepth) > 1) {
            maxDepth = max(curDepth, maxDepth);
            return false;
        }
        maxDepth = max(curDepth, maxDepth);
    }
    return true;
}

bool IsBalanced(Node* root) {
    if (not root) {
        return true;
    }
    int maxDepth = -1;
    return IsBalancedImpl(root, maxDepth, 0);
}

bool Test() {
    {
        Node* a0 = new Node(); a0->value = 8;
        Node* a1 = new Node(); a1->value = 6;
        Node* a2 = new Node(); a2->value = 10;
        Node* a3 = new Node(); a3->value = 9;

        a0->left = a1;
        a0->right = a2;
        a2->left = a3;

        if (not IsBalanced(a0)) {
            return false;
        }
    }
    {
        if (not IsBalanced(nullptr)) {
            return false;
        }
    }
    {
        Node* a0 = new Node(); a0->value = 1;
        Node* a1 = new Node(); a1->value = 2;
        Node* a2 = new Node(); a2->value = 3;
        Node* a3 = new Node(); a3->value = 4;

        a0->right = a1;
        a1->right = a2;
        a3->right = a3;

        if (not IsBalanced(a0)) {
            return false;
        }
    }
    {
        Node* a0 = new Node(); a0->value = 1;
        Node* a1 = new Node(); a1->value = 2;
        Node* a2 = new Node(); a2->value = 3;
        Node* a3 = new Node(); a3->value = 4;
        Node* a4 = new Node(); a4->value = 5;

        a0->right = a1;
        a1->right = a2;
        a2->right = a3;
        a0->left = a4;

        if (IsBalanced(a0)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}
