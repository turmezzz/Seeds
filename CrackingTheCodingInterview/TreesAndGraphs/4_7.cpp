//
// Find fca of two nodes
//

#include <iostream>

using namespace std;

struct Node {
    Node* parent;
    int value;
};

Node* FindFirstCommonAncestor(Node* a, Node* b) {
    if (not a or not b) {
        return nullptr;
    }
    Node* aCopy = a;
    Node* bCopy = b;
    int aDepth = 0;
    int bDepth = 0;
    while (aCopy->parent) {
        ++aDepth;
        aCopy = aCopy->parent;
    }
    while (bCopy->parent) {
        ++bDepth;
        bCopy = bCopy->parent;
    }
    int aShift = max(aDepth - bDepth, 0);
    int bShift = max(bDepth - aDepth, 0);
    while (aShift-- != 0) {
        a = a->parent;
    }
    while (bShift-- != 0) {
        b = b->parent;
    }
    while (a != b) {
        a = a->parent;
        b = b->parent;
    }
    return a;
}

bool Test() {
    {
        Node* a0 = new Node(); a0->value = 0;
        Node* a1 = new Node(); a1->value = 1;
        Node* a2 = new Node(); a2->value = 2;
        Node* a3 = new Node(); a3->value = 3;
        Node* a4 = new Node(); a4->value = 4;

        a2->parent = nullptr;
        a1->parent = a2;
        a3->parent = a2;
        a0->parent = a1;
        a4->parent = a3;

        if (FindFirstCommonAncestor(a4, a0) != a2) {
            return false;
        }
        if (FindFirstCommonAncestor(a4, a3) != a3) {
            return false;
        }
        if (FindFirstCommonAncestor(a4, a2) != a2) {
            return false;
        }
        if (FindFirstCommonAncestor(a1, a3) != a2) {
            return false;
        }
    }
    {
        if (FindFirstCommonAncestor(nullptr, new Node()) != nullptr) {
            return false;
        }
    }
    {
        if (FindFirstCommonAncestor(nullptr, nullptr) != nullptr) {
            return false;
        }
    }
    {
        if (FindFirstCommonAncestor(new Node(), new Node()) != nullptr) {
            return false;
        }
    }
    {
        Node* box = new Node();
        if (FindFirstCommonAncestor(box, box) != box) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

