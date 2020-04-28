//
// You are given node of forward list. Delete this node
//

#include <iostream>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
};

void DeleteMidNode(Node* node) {
    while (node) {
        Node* next = node->next_d;
        if (next) {
            node->next_d = next->next_d;
            node->value_d = next->value_d;
        }
        node = next;
    }
    delete node;
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

        DeleteMidNode(a2);
        if (a1->next_d->value_d != 3) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}