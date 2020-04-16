//
// Delete duplicates from a linked list
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value_d = 0;
    Node* next_d = nullptr;
};

void Show(Node* begin, Node* end) {
    if (begin == end) {
        return;
    }
    while (begin != end) {
        cout << begin->value_d << ' ';
        begin = begin->next_d;
    }
    cout << endl;
}

pair <Node*, Node*> SortLinkedList(Node* begin, Node* end) {
    Node* prevSlow = begin;
    Node* slow = begin;
    Node* prevFast = begin;
    Node* fast = begin;
    while (fast != end and fast->next_d != end) {
        prevSlow = slow;
        prevFast = fast;
        slow = slow->next_d;
        fast = fast->next_d->next_d;
    }

    // left part = begin, slow
    // right part = slow, end

    Node* commonPre = new Node();
    Node* commonEnd = end;

    Node* leftBegin = begin;
    prevSlow->next_d = nullptr;
    Node* leftEnd = prevSlow->next_d;
    if (leftBegin->next_d != leftEnd) {
        auto box = SortLinkedList(leftBegin, leftEnd);
        leftBegin = box.first;
        leftEnd = box.second;
    }

    Node* rightBegin = slow;
    if (fast) {
        prevFast = fast;
    }
    prevFast->next_d = nullptr;
    Node* rightEnd = prevFast->next_d;
    if (rightBegin->next_d != rightEnd) {
        auto box = SortLinkedList(rightBegin, rightEnd);
        rightBegin = box.first;
        rightEnd = box.second;
    }

    Node* it = commonPre;
    Node* left = leftBegin;
    Node* right = rightBegin;
    while (left != leftEnd or right != rightEnd) {
        if (left != leftEnd and right != rightEnd and left->value_d <= right->value_d) {
            it->next_d = left;
            left = left->next_d;
        } else if (right != rightEnd) {
            it->next_d = right;
            right = right->next_d;
        } else if (left != leftEnd) {
            it->next_d = left;
            left = left->next_d;
        }
        it = it->next_d;
    }
    it->next_d = commonEnd;
    Node* commonBegin = commonPre->next_d;
    delete commonPre;
    return {commonBegin, commonEnd};
}

pair <Node*, Node*> DeleteDuplicates(Node* begin, Node* end) {
    if (begin == end) {
        return {begin, end};
    }
    {
        auto box = SortLinkedList(begin, end);
        begin = box.first;
        end = box.second;
    }
    Node* chunkBegin = begin;
    while (chunkBegin != end) {
        Node* chunkEnd = chunkBegin->next_d;
        while (chunkEnd and chunkBegin->value_d == chunkEnd->value_d) {
            chunkEnd = chunkEnd->next_d;
        }
        Node* it = chunkBegin->next_d;
        while(it != chunkEnd) {
            Node* box = it->next_d;
            delete it;
            it = box;
        }
        chunkBegin->next_d = chunkEnd;
        chunkBegin = chunkEnd;
    }
    return {begin, end};
}

bool Test() {
    {
        // testing sort
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1;
        a0->value_d = 4;

        a1->next_d = a2;
        a1->value_d = 1;

        a2->next_d = a3;
        a2->value_d = 3;

        a3->next_d = a4;
        a3->value_d = 2;

        a4->next_d = nullptr;
        a4->value_d = 5;

        vector <int> data = {1, 2, 3, 4, 5};

        auto[listBegin, listEnd] = SortLinkedList(a0, a4->next_d);
        auto it = data.begin();
        int length = 0;
        while (listBegin != listEnd) {
            ++length;
            if (listBegin->value_d != *it) {
                return false;
            }
            ++it;
            listBegin = listBegin->next_d;
        }
        if (length != data.size()) {
            return false;
        }
    }
    {
        // testing delete
        Node* a0 = new Node();
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();

        a0->next_d = a1;
        a0->value_d = 4;

        a1->next_d = a2;
        a1->value_d = 4;

        a2->next_d = a3;
        a2->value_d = 3;

        a3->next_d = a4;
        a3->value_d = 5;

        a4->next_d = nullptr;
        a4->value_d = 5;

        vector <int> data = {3, 4, 5};

        auto[listBegin, listEnd] = DeleteDuplicates(a0, a4->next_d);
        auto it = data.begin();
        int length = 0;
        while (listBegin != listEnd) {
            ++length;
            if (listBegin->value_d != *it) {
                return false;
            }
            ++it;
            listBegin = listBegin->next_d;
        }
        if (length != data.size()) {
            return false;
        }
    }

    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}