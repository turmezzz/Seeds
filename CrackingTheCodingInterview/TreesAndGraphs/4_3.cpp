//
// Make lowest bst from sorted array
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
};

void Show(Node* node, int level = 0) {
    if (not node) {
        return;
    }
    cout << node->value << ':' << level << endl;
    Show(node->left, level + 1);
    Show(node->right, level + 1);
}

vector <int> GetInOrder(Node* node) {
    if (not node) {
        return {};
    }
    vector <int> ret;
    if (node->left) {
        ret = GetInOrder(node->left);
    }
    ret.push_back(node->value);
    if (node->right) {
        for (int i : GetInOrder(node->right)) {
            ret.push_back(i);
        }
    }
    return ret;
}

Node* MakeBST(vector <int>::const_iterator begin, vector <int>::const_iterator end) {
    int n = end - begin;
    if (n <= 0) {
        return nullptr;
    }
    Node* ret = new Node();
    ret->value = *(begin + n / 2);
    ret->left = MakeBST(begin, begin + n / 2);
    ret->right = MakeBST(begin + n / 2 + 1, end);
    return ret;
}

bool Test() {
    {
        vector <int> data = {1, 2, 3, 4};
        Node* box = MakeBST(data.cbegin(), data.cend());
        vector <int> inOrder = GetInOrder(box);
        if (data != inOrder) {
            return false;
        }
    }
    {
        vector <int> data = {1, 2, 3, 4, 9, 11, 123, 432, 123123};
        Node* box = MakeBST(data.cbegin(), data.cend());
        vector <int> inOrder = GetInOrder(box);
        if (data != inOrder) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

