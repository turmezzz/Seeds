#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

namespace Char2Int_NS {
    constexpr int ALPHABET = 32;

    constexpr array <int, ALPHABET> InitChar2IntArray() {
        array <int, ALPHABET> data = {};
        int n = 1;
        for (int i = 0; i < ALPHABET; ++i) {
            data[i] = n;
            n <<= 1;
        }
        return data;
    }

    // works in gcc, but do not works in clang
    // this code will init char2int array in compile time
//    constexpr array <int, ALPHABET> char2int = InitChar2IntArray();
    const array <int, ALPHABET> char2int = InitChar2IntArray();

    // guess that
    int GetIntFrom(char symbol) {
        return char2int[symbol - 'a'];
    }
}

struct Node {
    char symbol;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Solution {
    unordered_map <int, Node*> subTree2subRoot;
    bool stop = false;
    pair <Node*, Node*> ret = {nullptr, nullptr};

public:

    pair <Node*, Node*> Solve(Node* root){
        GetSubTree(root);
        return ret;
    }

private:

    int GetSubTree(Node* node) {
        int left = node->left ? GetSubTree(node->left) : 0;
        int right = node->right ? GetSubTree(node->right) : 0;
        if (stop) {
            return 0;
        }
        int me = Char2Int_NS::GetIntFrom(node->symbol);
        int my_subtree = (left | me | right);
        if (auto it = subTree2subRoot.find(my_subtree); it != subTree2subRoot.end()) {
            stop = true;
            ret.first = it->second;
            ret.second = node;
            return 0;
        }
        subTree2subRoot[my_subtree] = node;
        return my_subtree;
    }
};

// this solution finds two different subtrees

int main() {

    {
        Solution sol;
        cout << "Test 0: ";
        Node* a = new Node();
        a->symbol = 'a';

        Node* b = new Node();
        b->symbol = 'b';

        Node* c = new Node();
        c->symbol = 'c';

        a->left = b;
        a->right = c;

        auto nodes = sol.Solve(a);
        if (nodes.first == nullptr) {
            cout << "[OK  ]" << endl;
        } else {
            cout << "[FAIL]" << endl;
        }
    }

    {
        Solution sol;
        cout << "Test 1: ";
        Node* a = new Node();
        a->symbol = 'a';

        Node* left_a = new Node();
        left_a->symbol = 'x';

        Node* right_a = new Node();
        right_a->symbol = 'x';

        a->left = left_a;
        a->right = right_a;

        auto nodes = sol.Solve(a);
        if (nodes.first == left_a and nodes.second == right_a) {
            cout << "[OK  ]" << endl;
        } else {
            cout << "[FAIL]" << endl;
        }
    }

    {
        Solution sol;
        cout << "Test 3: ";
        Node* a = new Node();
        a->symbol = 'a';

        Node* b = new Node();
        b->symbol = 'b';

        Node* c = new Node();
        c->symbol = 'c';

        Node* b1 = new Node();
        b1->symbol = 'b';

        Node* c1 = new Node();
        c1->symbol = 'c';

        a->left = b;
        a->right = c;

        b->left = c1;

        c->right = b1;

        auto nodes = sol.Solve(a);
        if (nodes.first == b and nodes.second == c) {
            cout << "[OK  ]" << endl;
        } else {
            cout << "[FAIL]" << endl;
        }
    }

    return 0;
}