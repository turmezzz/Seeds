#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

pair <Node*, Node*> dummy(Node* node, Node* left_border, Node* right_border) {
    int left_border_val = left_border ? left_border->val : INT32_MIN;
    int right_border_val = right_border ? right_border->val : INT32_MAX;
    if (node->val < left_border_val) {
        return {left_border, node};
    }
    if (right_border_val <= node->val) {
        return {right_border, node};
    }
    pair <Node*, Node*> nodes_from_left = {nullptr, nullptr};
    if (node->left) {
        nodes_from_left = dummy(node->left, left_border, node);
    }
    pair <Node*, Node*> nodes_from_right = {nullptr, nullptr};
    if (node->right) {
        nodes_from_right = dummy(node->right, node, right_border);
    }
    if (not nodes_from_left.first and not nodes_from_right.first) {
        return {nullptr, nullptr};
    }
    if (not nodes_from_left.first) {
        swap(nodes_from_right.first->val, nodes_from_right.second->val);
        return {nullptr, nullptr};
    }
    if (not nodes_from_right.first) {
        swap(nodes_from_left.first->val, nodes_from_left.second->val);
        return nodes_from_left;
    }

    // check
    if (nodes_from_left.first != nodes_from_right.first) {
        cout << "SHIT" << endl;
        int box;
        cin >> box;
    }
    swap(nodes_from_left.second->val, nodes_from_right.second->val);
    return {nullptr, nullptr};
}

void FixBST(Node* root) {
    if (not root) {
        return;
    }
    dummy(root, nullptr, nullptr);
}

void Show(Node* root) {
    queue <Node*> data;
    data.push(root);
    while (not data.empty()) {
        auto* box = data.front();
        data.pop();
        if (not box) {
            cout << "null ";
        } else {
            cout << box->val << ' ';
            data.push(box->left);
            data.push(box->right);
        }
    }
    cout << endl;

}

int main() {
    {
        // from different subtrees
        Node* a0 = new Node(); a0->val = 5;
        Node* a1 = new Node(); a1->val = 7; // 3
        Node* a2 = new Node(); a2->val = 3; // 7
        Node* a3 = new Node(); a3->val = 2;
        Node* a4 = new Node(); a4->val = 4;
        Node* a5 = new Node(); a5->val = 6;
        Node* a6 = new Node(); a6->val = 8;

        a0->left = a1;
        a0->right = a2;

        a1->left = a3;
        a1->right = a4;

        a2->left = a5;
        a2->right = a6;

        a3->left = nullptr;
        a3->right = nullptr;

        a4->left = nullptr;
        a4->right = nullptr;

        a5->left = nullptr;
        a5->right = nullptr;

        a6->left = nullptr;
        a6->right = nullptr;

        Show(a0);
        FixBST(a0);
        Show(a0);
    }

    {
        // from one subtree
        Node* a0 = new Node(); a0->val = 3; // 5
        Node* a1 = new Node(); a1->val = 5; // 3
        Node* a2 = new Node(); a2->val = 7;
        Node* a3 = new Node(); a3->val = 2;
        Node* a4 = new Node(); a4->val = 4;
        Node* a5 = new Node(); a5->val = 6;
        Node* a6 = new Node(); a6->val = 8;

        a0->left = a1;
        a0->right = a2;

        a1->left = a3;
        a1->right = a4;

        a2->left = a5;
        a2->right = a6;

        a3->left = nullptr;
        a3->right = nullptr;

        a4->left = nullptr;
        a4->right = nullptr;

        a5->left = nullptr;
        a5->right = nullptr;

        a6->left = nullptr;
        a6->right = nullptr;

        Show(a0);
        FixBST(a0);
        Show(a0);
    }

    {
        // correct tree
        Node* a0 = new Node(); a0->val = 5;
        Node* a1 = new Node(); a1->val = 3;
        Node* a2 = new Node(); a2->val = 7;
        Node* a3 = new Node(); a3->val = 2;
        Node* a4 = new Node(); a4->val = 4;
        Node* a5 = new Node(); a5->val = 6;
        Node* a6 = new Node(); a6->val = 8;

        a0->left = a1;
        a0->right = a2;

        a1->left = a3;
        a1->right = a4;

        a2->left = a5;
        a2->right = a6;

        a3->left = nullptr;
        a3->right = nullptr;

        a4->left = nullptr;
        a4->right = nullptr;

        a5->left = nullptr;
        a5->right = nullptr;

        a6->left = nullptr;
        a6->right = nullptr;

        Show(a0);
        FixBST(a0);
        Show(a0);
    }

    {
        // bamboo
        Node* a0 = new Node(); a0->val = 3;
        Node* a1 = new Node(); a1->val = 5;
        Node* a3 = new Node(); a3->val = 2;

        a0->left = a1;
        a0->right = nullptr;

        a1->left = a3;
        a1->right = nullptr;

        Show(a0);
        FixBST(a0);
        Show(a0);
    }



    return 0;
}