//
// Find next node in bst
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int value;
};

Node* GetNext(Node* node) {
    if (not node) {
        return nullptr;
    }
    if (node->right) {
        Node* box = node->right;
        while (box->left) {
            box = box->left;
        }
        return box;
    } else if (node->parent) {
        Node* me = node;
        Node* parent = node->parent;
        while (parent and parent->right == me) {
            me = parent;
            parent = me->parent;
        }
        if (parent) {
            return parent;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

bool Test() {
    {
        Node* a0 = new Node(); a0->value = 0;
        Node* a1 = new Node(); a1->value = 1;
        Node* a2 = new Node(); a2->value = 2;
        Node* a3 = new Node(); a3->value = 3;
        Node* a4 = new Node(); a4->value = 4;

        a2->parent = nullptr;
        a2->left = a1;
        a2->right = a3;

        a1->parent = a2;
        a1->left = a0;
        a1->right = nullptr;

        a3->parent = a2;
        a3->left = nullptr;
        a3->right = a4;

        a0->parent = a1;
        a0->left = nullptr;
        a0->right = nullptr;

        a4->parent = a3;
        a4->left = nullptr;
        a4->right = nullptr;

        if (GetNext(a0) != a1) {
            return false;
        }
        if (GetNext(a1) != a2) {
            return false;
        }
        if (GetNext(a2) != a3) {
            return false;
        }
        if (GetNext(a3) != a4) {
            return false;
        }
        if (GetNext(a4) != nullptr) {
            return false;
        }

    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

