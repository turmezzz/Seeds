//
// Partition linked list around value x
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
    Node* prev_d = nullptr;
};

pair <Node*, Node*> Partition(Node* head, int x) {
    if (not head) {
        return {nullptr, nullptr};
    }
    Node* preHead = new Node();
    Node* doNotForgetDoDelete = preHead;
    preHead->next_d = head;

    Node* last = head;
    int length = 0;
    for (; last; last = last->next_d) {
        ++length;
        if (not last->next_d) {
            break;
        }
    }

    while (length != 0) {
        --length;
        while (preHead != last and preHead->next_d->value_d <= x) {
            preHead = preHead->next_d;
        }
        if (preHead != last) {
            Node* box = preHead->next_d->next_d ? preHead->next_d->next_d : nullptr;
            preHead->next_d->next_d = nullptr;
            last->next_d = preHead->next_d;
            preHead->next_d = box;
            last = last->next_d;
        }
    }

    Node* box = doNotForgetDoDelete->next_d;
    delete doNotForgetDoDelete;
    return {box, preHead->next_d}; // new head, begin of > x nodes
}

bool Test() {
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->prev_d = nullptr;
        a0->next_d = a1;
        a0->value_d = 1;

        a1->prev_d = a0;
        a1->next_d = a2;
        a1->value_d = 2;

        a2->prev_d = a1;
        a2->next_d = a3;
        a2->value_d = 7;

        a3->prev_d = a2;
        a3->next_d = a4;
        a3->value_d = 5;

        a4->prev_d = a3;
        a4->next_d = nullptr;
        a4->value_d = 3;

        vector <int> data = {1, 2, 3, 5, 7};
        auto box = Partition(a0, 4);
        a0 = box.first;
        Node* it = a0;
        for (int v : data) {
            if (v != it->value_d) {
                return false;
            }
            it = it->next_d;
        }
    }
    {
        Partition(nullptr, 4);
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->prev_d = nullptr;
        a0->next_d = a1;
        a0->value_d = 1;

        a1->prev_d = a0;
        a1->next_d = a2;
        a1->value_d = 2;

        a2->prev_d = a1;
        a2->next_d = a3;
        a2->value_d = 7;

        a3->prev_d = a2;
        a3->next_d = a4;
        a3->value_d = 5;

        a4->prev_d = a3;
        a4->next_d = nullptr;
        a4->value_d = 3;

        vector <int> data = {1, 2, 7, 5, 3};
        auto box = Partition(a0, 10);
        a0 = box.first;
        Node* it = a0;
        for (int v : data) {
            if (v != it->value_d) {
                return false;
            }
            it = it->next_d;
        }
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->prev_d = nullptr;
        a0->next_d = a1;
        a0->value_d = 5;

        a1->prev_d = a0;
        a1->next_d = a2;
        a1->value_d = 4;

        a2->prev_d = a1;
        a2->next_d = a3;
        a2->value_d = 3;

        a3->prev_d = a2;
        a3->next_d = a4;
        a3->value_d = 2;

        a4->prev_d = a3;
        a4->next_d = nullptr;
        a4->value_d = 1;

        vector <int> data = {3, 2, 1, 4, 5};
        auto box = Partition(a0, 3);
        a0 = box.first;
        Node* it = a0;
        for (int v : data) {
            if (v != it->value_d) {
                return false;
            }
            it = it->next_d;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}