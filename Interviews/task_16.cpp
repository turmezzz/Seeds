#include <iostream>

using namespace std;

struct Node {

    Node() : next(nullptr), val(0) {
    }

    Node* next;
    int val;
};

pair <Node*, Node*> Reverse(Node* begin, Node* end) {
    Node* prev = nullptr;
    Node* curr = begin;
    Node* next = nullptr;
    while (curr != end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // prev - old end, new begin
    // begin - old begin, new last
    return {prev, begin->next};
}

void Show(Node* begin) {
    while (begin) {
        cout << begin->val << ' ';
        begin = begin->next;
    }
    cout << endl;
}

int main() {
    {
        // 0 -> 1 -> 2 -> nullptr
        Node* a0 = new Node(); a0->val = 0;
        Node* a1 = new Node(); a1->val = 1;
        Node* a2 = new Node(); a2->val = 2;

        a0->next = a1;
        a1->next = a2;

        Show(a0);

        Node* begin = a0;
        Node* end = a2->next;

        auto[new_begin, new_end] = Reverse(begin, end);
        Show(new_begin);
    }
    {
        // 0 -> 1 -> 2 -> 3 -> 4-> nullptr
        Node* a0 = new Node(); a0->val = 0;
        Node* a1 = new Node(); a1->val = 1;
        Node* a2 = new Node(); a2->val = 2;
        Node* a3 = new Node(); a3->val = 3;
        Node* a4 = new Node(); a4->val = 4;

        a0->next = a1;
        a1->next = a2;
        a2->next = a3;
        a3->next = a4;

        Show(a0);

        Node* begin = a0;
        Node* end = a2->next;

        auto[new_begin, new_end] = Reverse(begin, end);
        Show(new_begin);
    }
    return 0;
}