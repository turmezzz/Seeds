//
// Partition linked list around value x
//
// I can do it with forward list but I need O(n^2) for now
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
    Node* prev_d = nullptr;
};

void Partition(Node* head, int x) {
    if (not head) {
        return;
    }
    Node* left = head;
    Node* right = head;
    for (; right; right = right->next_d) {
        if (not right->next_d) {
            break;
        }
    }

    while (left and right) {
        while (left and left->value_d < x) {
            left = left->next_d;
        }
        while (right and right->value_d > x) {
            right = right->prev_d;
        }
        if (left and right) {
            bool needToStop = (left->next_d == right);
            swap(left->value_d, right->value_d);
            left = left->next_d;
            right = right->prev_d;
            if (left == right or needToStop) {
                break;
            }
        }
    }
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
        Partition(a0, 4);
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
        Partition(a0, 10);
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

        vector <int> data = {1, 2, 3, 4, 5};
        Partition(a0, 3);
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