//
// Sum two numbers which are represented as ll
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
};

Node* ReverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* newHead = nullptr;
    while (head) {
        Node* box = head->next_d;
        if (not box) {
            newHead = head;
        }
        head->next_d = prev;
        prev = head;
        head = box;
    }
    return newHead;
}

Node* SumTwoNumbers(Node* a, Node* b) {
    a = ReverseLinkedList(a);
    b = ReverseLinkedList(b);

    Node* preHead = new Node();
    Node* it = preHead;
    int box = 0;
    while (a or b) {
        it->next_d = new Node();
        int aValue = 0;
        if (a) {
            aValue = a->value_d;
            a = a->next_d;
        }
        int bValue = 0;
        if (b) {
            bValue = b->value_d;
            b = b->next_d;
        }
        it->next_d->value_d = (aValue + bValue + box) % 10;
        box = (aValue + bValue + box) / 10;
        it = it->next_d;
    }
    it = preHead->next_d;
    delete preHead;
    return ReverseLinkedList(it);
}

bool Test() {
    {
        // Test reverse
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1;
        a0->value_d = 1;

        a1->next_d = a2;
        a1->value_d = 2;

        a2->next_d = a3;
        a2->value_d = 7;

        a3->next_d = a4;
        a3->value_d = 5;

        a4->next_d = nullptr;
        a4->value_d = 3;

        Node* box = ReverseLinkedList(a0);
        if (box != a4) {
            return false;
        }
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1;
        a0->value_d = 1;

        a1->next_d = a2;
        a1->value_d = 2;

        a2->next_d = nullptr;
        a2->value_d = 7;

        a3->next_d = a4;
        a3->value_d = 5;

        a4->next_d = nullptr;
        a4->value_d = 3;


        int x = 0;
        for (Node* box = SumTwoNumbers(a0, a3); box; box = box->next_d) {
            x *= 10;
            x += box->value_d;
        }
        if (x != 180) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}