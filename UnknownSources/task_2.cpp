#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *insertNode(ListNode *head, int val) {
    auto *new_node = new ListNode();
    new_node->val = val;
    if (head == nullptr) {
        new_node->next = new_node;
        return new_node;
    }
    ListNode *turtle = head;
    ListNode *rabit = head;
    do {
        if ((turtle->val <= val and val <= turtle->next->val) or
            (turtle->val > turtle->next->val)) {
            new_node->next = turtle->next;
            turtle->next = new_node;
            return head;
        }
        turtle = turtle->next;
        rabit = rabit->next->next;
    } while (turtle != rabit);
    new_node->next = turtle->next;
    turtle->next = new_node;
    return turtle;
}

void Show(ListNode *node) {
    for (int i = 0; i < 10; ++i) {
        cout << node->val << ' ';
        node = node->next;
    }
    cout << endl;
}

int main() {
    {
        auto *a0 = new ListNode();
        a0->val = 0;
        auto *a1 = new ListNode();
        a1->val = 1;
        auto *a2 = new ListNode();
        a2->val = 2;
        auto *a3 = new ListNode();
        a3->val = 3;

        a0->next = a1;
        a1->next = a2;
        a2->next = a3;
        a3->next = a0;

        auto *box = insertNode(a0, 4);

        Show(box);
    }

    {
        auto *a0 = new ListNode();
        a0->val = 0;
        auto *a1 = new ListNode();
        a1->val = 1;
        auto *a2 = new ListNode();
        a2->val = 2;

        a0->next = a1;
        a1->next = a2;
        a2->next = a0;

        auto *box = insertNode(a0, -1);

        Show(box);
    }

    {
        auto *a0 = new ListNode();
        a0->val = 0;
        a0->next = a0;

        auto *box = insertNode(a0, -1);

        Show(box);
    }


    return 0;
}