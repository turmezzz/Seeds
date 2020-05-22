//
// Make ll with bt elements of each level
//
#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
};

void Dfs(Node* node, vector <forward_list <Node*>>& data, int level) {
    if (data.size() <= level) {
        data.emplace_back(forward_list <Node*>());
    }
    data[level].push_front(node);
    if (node->left) {
        Dfs(node->left, data, level + 1);
    }
    if (node->right) {
        Dfs(node->right, data, level + 1);
    }
}

vector <forward_list <Node*>> GetLevelsFromBT(Node* root) {
    if (not root) {
        return {};
    }
    vector <forward_list <Node*>> ret;
    Dfs(root, ret, 0);
    return ret;
}

bool Test() {
    {
        Node* a0 = new Node();
        a0->value = 0;
        Node* a1 = new Node();
        a1->value = 1;
        Node* a2 = new Node();
        a2->value = 2;
        Node* a3 = new Node();
        a3->value = 3;
        Node* a4 = new Node();
        a4->value = 4;

        a0->left = a1;
        a0->right = a2;
        a1->left = a3;
        a1->right = a4;

        vector <forward_list <Node*>> reference = {{a0},
                                                   {a2, a1},
                                                   {a4, a3}};

        auto test = GetLevelsFromBT(a0);
        if (test.size() != reference.size()) {
            return false;
        }
        for (int i = 0; i < reference.size(); ++i) {
            const auto& refList = reference[i];
            const auto& testList = test[i];
            auto refListIt = refList.begin();
            auto testListIt = testList.begin();
            cout << "level " << i << endl;
            while (refListIt != refList.end() and testListIt != testList.end()) {
                cout << (*refListIt)->value << '-' << (*testListIt)->value << ' ';
                if ((*refListIt++)->value != (*testListIt++)->value) {
                    return false;
                }
            }
            cout << endl;
            if (not (refListIt == refList.end() and testListIt == testList.end())) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}