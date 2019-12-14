#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void Show(ListNode* head) {
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

class Comparator {
public:
    bool operator()(ListNode* a, ListNode*b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector <ListNode*>, Comparator> cur_iters;
        for (auto* it : lists) {
            if (it) {
                cur_iters.push(it);
            }
        }

        if (cur_iters.empty()) {
            return nullptr;
        }

        ListNode* head = cur_iters.top();
        cur_iters.pop();
        ListNode* cur = head;
        if (cur->next) {
            cur_iters.push(cur->next);
        }

        while (not cur_iters.empty()) {
            auto* box_it = cur_iters.top();
            cur_iters.pop();

            if (box_it->next) {
                cur_iters.push(box_it->next);
            }

            cur->next = box_it;
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }

    ListNode* Next() {
        // this code is a solution of 23-th leetcode task
        // but main idea is same as yandex task
        return nullptr;
    }
};

int main() {
    {
        ListNode* a0 = new ListNode(1);

        Solution sol;

        vector <ListNode*> data = {a0};
        auto* head = sol.mergeKLists(data);
        Show(head);
    }

    {
        ListNode* a0 = new ListNode(1);

        ListNode* b0 = new ListNode(2);

        ListNode* c0 = new ListNode(3);

        Solution sol;

        vector <ListNode*> data = {a0, b0, c0};
        auto* head = sol.mergeKLists(data);
        Show(head);
    }

    {
        ListNode* a0 = new ListNode(1);
        ListNode* a1 = new ListNode(4);
        ListNode* a2 = new ListNode(5);
        a0->next = a1;
        a1->next = a2;

        ListNode* b0 = new ListNode(1);
        ListNode* b1 = new ListNode(3);
        ListNode* b2 = new ListNode(4);
        b0->next = b1;
        b1->next = b2;

        ListNode* c0 = new ListNode(2);
        ListNode* c1 = new ListNode(6);
        c0->next = c1;

        Solution sol;

        vector <ListNode*> data = {a0, b0, c0};
        auto* head = sol.mergeKLists(data);
        Show(head);
    }

    return 0;
}