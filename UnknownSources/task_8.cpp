#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
};

void Show(Node* node) {
    while (node) {
        cout << node->val << ' ';
        node = node->next;
    }
    cout << endl;
}

Node* Reverse(Node* node) {
    if (not node) {
        return nullptr;
    }
    Node* prev = nullptr;
    while (node->next) {
        Node* box = node->next;
        node->next = prev;
        prev = node;
        node = box;
    }
    node->next = prev;
    return node;
}

Node* SumTwoNumbers(Node* a, Node* b) {
    if (not a and not b) {
        return nullptr;
    }

    a = Reverse(a);
    b = Reverse(b);

    auto* pre_head = new Node();
    auto* cur = pre_head;
    int buf = 0;
    int box;
    while (a or b) {
        cur->next = new Node();
        cur = cur->next;
        box = buf;
        if (a) {
            box += a->val;
            a = a->next;
        }
        if (b) {
            box += b->val;
            b = b->next;
        }
        cur->val = box % 10;
        buf = box / 10;
    }
    if (buf != 0) {
        cur->next = new Node();
        cur->next->val = buf;
    }
    return Reverse(pre_head->next);
}

int main() {
    {
        auto* a0 = new Node(); a0->val = 1;
        auto* a1 = new Node(); a1->val = 1;
        a0->next = a1;

        auto* b0 = new Node(); b0->val = 2;
        auto* b1 = new Node(); b1->val = 1;
        b0->next = b1;

        auto* box = SumTwoNumbers(a0, b0);
        Show(box);
    }
    {
        auto* a0 = new Node(); a0->val = 9;
        auto* a1 = new Node(); a1->val = 9;
        auto* a2 = new Node(); a2->val = 9;
        a0->next = a1;
        a1->next = a2;

        auto* b0 = new Node(); b0->val = 1;

        auto* box = SumTwoNumbers(a0, b0);
        Show(box);
    }
    {
        auto* a0 = new Node(); a0->val = 9;
        auto* a1 = new Node(); a1->val = 9;
        auto* a2 = new Node(); a2->val = 9;
        a0->next = a1;
        a1->next = a2;

        auto* box = SumTwoNumbers(a0, nullptr);
        Show(box);
    }
    {
        auto* box = SumTwoNumbers(nullptr, nullptr);
        Show(box);
    }

    return 0;
}