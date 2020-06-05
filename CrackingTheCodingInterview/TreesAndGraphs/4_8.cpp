//
// T1 - huge bt (millions)
// T2 - bt (hundreds)
// Check if T2 is a subtree of T1
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node {
    Node(int value) : value(value) {

    }

    Node* left = nullptr;
    Node* right = nullptr;
    int value;
};

void GetInOrdered(Node* node, vector <int>& data) {
    if (not node) {
        return;
    }
    GetInOrdered(node->left, data);
    data.push_back(node->value);
    GetInOrdered(node->right, data);
}

template <class T>
void Show(const T& data) {
    for (auto v : data) {
        cout << v << ' ';
    }
    cout << endl;
}

bool IsSubtreeImpl(Node* node, deque <int>& data, const vector <int>& ref) {
    if (not node) {
        return false;
    }
    if (IsSubtreeImpl(node->left, data, ref)) {
        return true;
    }
    data.push_back(node->value);
    if (data.size() > ref.size()) {
        data.pop_front();
    }
    if (data.size() == ref.size()) {
        auto it = data.begin();
        bool equal = true;
        for (auto v : ref) {
            if (v != *it) {
                equal = false;
                break;
            }
            ++it;
        }
        if (equal) {
            return true;
        }
    }
    if (IsSubtreeImpl(node->right, data, ref)) {
        return true;
    }
    return false;
}

bool IsSubtree(Node* bigRoot, Node* smallRoot) {
    vector <int> smallTreeData;
    GetInOrdered(smallRoot, smallTreeData);
    deque <int> bigTreeData;
    return IsSubtreeImpl(bigRoot, bigTreeData, smallTreeData);
}

bool Test() {
    {
        Node* a0 = new Node(0);
        Node* a1 = new Node(1);
        Node* a2 = new Node(2);
        Node* a3 = new Node(3);
        Node* a4 = new Node(4);
        Node* a5 = new Node(5);
        Node* a6 = new Node(6);

        a1->left = a0;
        a1->right = a2;

        a5->left = a4;
        a5->right = a6;

        a3->left = a1;
        a3->right = a5;

        Node* b0 = new Node(0);
        Node* b1 = new Node(1);
        b0->right = b1;

        if (not IsSubtree(a3, b0)) {
            return false;
        }

    }
    {
        Node* a0 = new Node(0);
        Node* a1 = new Node(1);
        Node* a2 = new Node(2);
        Node* a3 = new Node(3);
        Node* a4 = new Node(4);
        Node* a5 = new Node(5);
        Node* a6 = new Node(6);

        a1->left = a0;
        a1->right = a2;

        a5->left = a4;
        a5->right = a6;

        a3->left = a1;
        a3->right = a5;

        Node* b0 = new Node(3);
        Node* b1 = new Node(4);
        b0->right = b1;

        if (not IsSubtree(a3, b0)) {
            return false;
        }

    }
    {
        Node* a0 = new Node(0);
        Node* a1 = new Node(1);
        Node* a2 = new Node(2);
        Node* a3 = new Node(3);
        Node* a4 = new Node(4);
        Node* a5 = new Node(5);
        Node* a6 = new Node(6);

        a1->left = a0;
        a1->right = a2;

        a5->left = a4;
        a5->right = a6;

        a3->left = a1;
        a3->right = a5;

        Node* b0 = new Node(0);
        Node* b1 = new Node(5);
        b0->right = b1;

        if (IsSubtree(a3, b0)) {
            return false;
        }

    }
    {
        Node* a0 = new Node(0);
        Node* a1 = new Node(1);
        Node* a2 = new Node(2);
        Node* a3 = new Node(3);
        Node* a4 = new Node(4);
        Node* a5 = new Node(5);
        Node* a6 = new Node(6);

        a1->left = a0;
        a1->right = a2;

        a5->left = a4;
        a5->right = a6;

        a3->left = a1;
        a3->right = a5;

        Node* b0 = new Node(4);

        if (not IsSubtree(a3, b0)) {
            return false;
        }

    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

