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

int GetLengthOfTheLoop(Node* head) {
    if (not head or not head->next_d) {
        return 0;
    }
    Node* fast = head;
    Node* slow = head;
    do {
        if (fast and fast->next_d) {
            fast = fast->next_d->next_d;
        } else {
            return 0;
        }

        if (slow) {
            slow = slow->next_d;
        } else {
            return 0;
        }
    } while (fast != slow);

    int loopSize = 0;
    do {
        fast = fast->next_d->next_d;
        slow = slow->next_d;
        ++loopSize;
    } while (fast != slow);
    return loopSize;
}

int GetXSize(Node* head) {
    Node* prev = nullptr;
    int ret = 0;
    while (head) {
        Node* box = head->next_d;
        head->next_d = prev;
        prev = head;
        head = box;
        ++ret;
    }
    return ret;
}

Node* Solve(Node* head) {
    int loopSize = GetLengthOfTheLoop(head);
    if (loopSize == 0) {
        return nullptr;
    }
    int xSize = GetXSize(head);
    GetXSize(head);
    int nonLoopPartSize = (xSize - loopSize) / 2;
    for (int i = 0; i < nonLoopPartSize; ++i) {
        head = head->next_d;
    }
    return head;
}

bool Test() {
    {
        // test get loop size
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

        a4->next_d = a1;
        a4->value_d = 3;

        if (GetLengthOfTheLoop(a0) != 4) {
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
        a3->value_d = 5;

        a4->next_d = a3;
        a4->value_d = 3;

        Node* box = Solve(a0);
        if (box != a3) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}