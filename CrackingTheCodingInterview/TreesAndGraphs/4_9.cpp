//
// We have a bt with values in nodes and value.
// Need to implement algorithm to find all paths (not only simple)
// which sum are equal to given value.
//

#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{

    Node(int value) : value(value) {

    };

    int value;
    Node* left;
    Node* right;
};

namespace PathFinder {
    unordered_map <Node*, unordered_map <int, vector <deque <Node*>>>> Node2Sum2Path;

    void ShowPath(deque <Node*>::const_iterator pathBegin, deque <Node*>::const_iterator pathEnd) {
        while (pathBegin != pathEnd) {
            cout << (*pathBegin)->value <<  ", ";
            ++pathBegin;
        }
    }

    void ShowPath(deque <Node*>::const_reverse_iterator pathBegin, deque <Node*>::const_reverse_iterator pathEnd) {
        while (pathBegin != pathEnd) {
            cout << (*pathBegin)->value << ", ";
            ++pathBegin;
        }
    }

    void ShowAllPaths(Node* node, int value, deque <Node*> path, int pathSum) {
        if (not node) {
            return;
        }

        pathSum += node->value;
        path.push_back(node);

        int origPathSum = pathSum;
        for (auto it = path.begin(); it != path.end(); ++it) {
            if (pathSum == value) {
                ShowPath(path.cbegin(), path.cend());
                cout << "\n";
            }
            Node2Sum2Path[*it][pathSum].emplace_back(it, path.end());

            pathSum -= (*it)->value;
            auto boxIt = it;
            ++boxIt;
            for (const auto& leftPath : Node2Sum2Path[*it][value - pathSum]) {
                ShowPath(leftPath.crbegin(), leftPath.crend());
                ShowPath(boxIt, path.end());
                cout << "\n";
            }
        }

        ShowAllPaths(node->left, value, path, origPathSum);
        ShowAllPaths(node->right, value, move(path), origPathSum);
    }
}



bool Test() {
    {
        {
            Node* a1 = new Node(1);
            Node* a2 = new Node(2);
            Node* a3 = new Node(3);
            Node* a4 = new Node(5);
            Node* a5 = new Node(5);
            Node* a6 = new Node(6);
            Node* a7 = new Node(7);

            a1->left = a2;
            a1->right = a5;

            a2->left = a3;
            a2->right = a4;

            a5->right = a6;

            a6->left = a7;

            Node* root = a1;
            int value = 8;
            PathFinder::ShowAllPaths(root, value, {}, 0);
        }
    }
    return true;
}

int main() {

    // does nothing here
    cout << Test();

    return 0;
}
