//
// Find k-th to last node
//

#include <iostream>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
};


Node* FindKthFromEnd(Node* begin, int k) {
    Node* it = begin;
    for (int i = 0; i < k; ++i) {
        if (not it) {
            break;
        }
        it = it->next_d;
    }

    while (it) {
        begin = begin->next_d;
        it = it->next_d;
    }
    return begin;
}


bool Test() {
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1; a0->value_d = 0;
        a1->next_d = a2; a1->value_d = 1;
        a2->next_d = a3; a2->value_d = 2;
        a3->next_d = a4; a3->value_d = 3;
        a4->next_d = nullptr; a4->value_d = 4;

        Node* box = FindKthFromEnd(a0, 2);
        if (box != a3) {
            return false;
        }
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1; a0->value_d = 0;
        a1->next_d = a2; a1->value_d = 1;
        a2->next_d = a3; a2->value_d = 2;
        a3->next_d = a4; a3->value_d = 3;
        a4->next_d = nullptr; a4->value_d = 4;

        Node* box = FindKthFromEnd(a0, 8);
        if (box != a0) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}
