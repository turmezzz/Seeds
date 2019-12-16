#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* GetNext(Node* node) {
    // imitate situation when we work with ~100gb lists
    // this method can be reading next node from disk
    return node->next;
}

Node* Filter(Node* a, Node* b) {
    auto* pre_head = new Node();
    auto* cur = pre_head;
    while (a) {
       while ((a and b and a->val < b->val) or (a and not b)) {
           cur->next = new Node();
           cur = cur->next;
           cur->val = a->val;
           a = GetNext(a);
       }
       while(a and b and a->val >= b->val) {
           if (a->val == b->val) {
               a = GetNext(a);
           }
           b = GetNext(b);
       }
    }
    return pre_head->next;
}

void Show(Node* node) {
    while (node) {
        cout << node->val << ' ';
        node = node->next;
    }
    cout << endl;
}

int main() {
    // actually i have memory leak in tests
    // but it is okay :)
    {
        auto* a0 = new Node();
        auto* a1 = new Node();
        auto* a2 = new Node();
        auto* a3 = new Node();
        auto* a4 = new Node();

        auto* b0 = new Node();
        auto* b1 = new Node();
        auto* b2 = new Node();

        a0->val = 1;
        a0->next = a1;
        a1->val = 2;
        a1->next = a2;
        a2->val = 3;
        a2->next = a3;
        a3->val = 4;
        a3->next = a4;
        a4->val = 5;
        a4->next = nullptr;

        b0->val = 2;
        b0->next = b1;
        b1->val = 3;
        b1->next = b2;
        b2->val = 6;
        b2->next = nullptr;

        Show(Filter(a0, b0));
    }

    {
        auto* a0 = new Node();
        auto* a1 = new Node();
        auto* a2 = new Node();
        auto* a3 = new Node();
        auto* a4 = new Node();

        a0->val = 1;
        a0->next = a1;
        a1->val = 2;
        a1->next = a2;
        a2->val = 3;
        a2->next = a3;
        a3->val = 4;
        a3->next = a4;
        a4->val = 5;
        a4->next = nullptr;

        Show(Filter(a0, a2));
    }

    {
        auto* a0 = new Node();
        auto* a1 = new Node();
        auto* a2 = new Node();
        auto* a3 = new Node();
        auto* a4 = new Node();

        a0->val = 1;
        a0->next = a1;
        a1->val = 2;
        a1->next = a2;
        a2->val = 3;
        a2->next = a3;
        a3->val = 4;
        a3->next = a4;
        a4->val = 5;
        a4->next = nullptr;

        Show(Filter(a0, nullptr));
    }
    {
        auto* a0 = new Node();
        auto* a1 = new Node();
        auto* a2 = new Node();
        auto* a3 = new Node();
        auto* a4 = new Node();

        auto* b0 = new Node();
        auto* b1 = new Node();
        auto* b2 = new Node();

        a0->val = 1;
        a0->next = a1;
        a1->val = 2;
        a1->next = a2;
        a2->val = 3;
        a2->next = a3;
        a3->val = 4;
        a3->next = a4;
        a4->val = 6;
        a4->next = nullptr;

        b0->val = 2;
        b0->next = b1;
        b1->val = 3;
        b1->next = b2;
        b2->val = 5;
        b2->next = nullptr;

        Show(Filter(a0, b0));
    }
    {
        Show(Filter(nullptr, nullptr));
    }
    return 0;
}