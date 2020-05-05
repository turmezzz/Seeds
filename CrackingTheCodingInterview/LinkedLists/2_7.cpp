//
// Check LL is it is a palindrome
//


#include <iostream>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
};

bool IsPalindrome(Node* head) {
    if (not head or not head->next_d) {
        return true;
    }
    Node* fast = head;
    Node* slow = head;
    Node* prevSlow = nullptr;
    do {
        fast = fast->next_d;
        prevSlow = slow;
        slow = slow->next_d;
    } while (fast and fast->next_d);
    Node* halfHead = prevSlow->next_d;
    prevSlow->next_d = nullptr;
    slow = slow->next_d;
    halfHead->next_d = nullptr;
    while (slow) {
        Node* box = slow->next_d;
        slow->next_d = halfHead;
        halfHead = slow;
        slow = box;
    }

    Node* headIt = head;
    Node* halfHeadIt = halfHead;
    bool ok = true;
    while (halfHeadIt) {
        Node* halfHeadItCopy = halfHeadIt;

        if (headIt->value_d != halfHeadIt->value_d) {
            ok = false;
        }
        headIt = headIt->next_d;
        halfHeadIt = halfHeadIt->next_d;

        Node* box = prevSlow->next_d;
        halfHeadItCopy->next_d = box;
        prevSlow->next_d = halfHeadItCopy;
    }
    return ok;
}

bool Test() {
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

        a2->next_d = a3;
        a2->value_d = 7;

        a3->next_d = a4;
        a3->value_d = 5;

        a4->next_d = nullptr;
        a4->value_d = 3;

        if (IsPalindrome(a0)) {
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

        a2->next_d = a3;
        a2->value_d = 7;

        a3->next_d = a4;
        a3->value_d = 2;

        a4->next_d = nullptr;
        a4->value_d = 1;

        if (not IsPalindrome(a0)) {
            return false;
        }
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();

        a0->next_d = a1;
        a0->value_d = 1;

        a1->next_d = a2;
        a1->value_d = 2;

        a2->next_d = a3;
        a2->value_d = 2;

        a3->next_d = nullptr;
        a3->value_d = 1;

        if (not IsPalindrome(a0)) {
            return false;
        }
    }
    {
        Node* a0 = new Node();

        a0->next_d = nullptr;
        a0->value_d = 1;

        if (not IsPalindrome(a0)) {
            return false;
        }
    }
    {
        if (not IsPalindrome(nullptr)) {
            return false;
        }
    }
    {
        Node* a0 = new Node();
        Node* a1 = new Node();

        a0->next_d = a1;
        a0->value_d = 1;

        a1->next_d = nullptr;
        a1->value_d = 1;

        if (not IsPalindrome(a0)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}