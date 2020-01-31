#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
};

int GetDepth(Node* node) {
    // nullptr - 0 level
    // root - 1 level
    int depth = 0;
    while (node) {
        ++depth;
        node = node->parent;
    }
    return depth;
}

Node* GetLCA(Node* a, Node* b) {
    int a_depth = GetDepth(a);
    int b_depth = GetDepth(b);

    if (a_depth < b_depth) {
        swap(a, b);
        swap(a_depth, b_depth);
    }

    for (int i = 0; i < a_depth - b_depth; ++i ){
        a = a->parent;
    }
    while (a != b) {
        a = a->parent;
        b = b->parent;
    }
    return a;
}

int main() {
    auto* a0 = new Node();
    auto* a1 = new Node();
    auto* a2 = new Node();
    auto* a3 = new Node();
    auto* a4 = new Node();
    auto* a5 = new Node();
    auto* a6 = new Node();

    a0->parent = nullptr;
    a0->left = a1;
    a0->right = a2;

    a1->parent = a0;
    a1->left = a3;
    a1->right = a4;

    a2->parent = a0;
    a2->left = a5;
    a2->right = a6;

    a3->parent = a1;
    a3->left = nullptr;
    a3->right = nullptr;

    a4->parent = a1;
    a4->left = nullptr;
    a4->right = nullptr;

    a5->parent = a2;
    a5->left = nullptr;
    a5->right = nullptr;

    a6->parent = a2;
    a6->left = nullptr;
    a6->right = nullptr;

    {
        auto* box = GetLCA(a5, a3);
        cout << (box == a0) << endl;
    }
    {
        auto* box = GetLCA(a5, a6);
        cout << (box == a2) << endl;
    }
    {
        auto* box = GetLCA(a5, a3);
        cout << (box == a0) << endl;
    }
    {
        auto* box = GetLCA(a0, a3);
        cout << (box == a0) << endl;
    }
    {
        auto* box = GetLCA(nullptr, a3);
        cout << (box == nullptr) << endl;
    }
    {
        auto* box = GetLCA(nullptr, nullptr);
        cout << (box == nullptr) << endl;
    }


    return 0;
}