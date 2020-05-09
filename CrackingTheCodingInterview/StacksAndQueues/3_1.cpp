#include <iostream>
#include <vector>

using namespace std;

class TreeStacks {
public:
    enum class StackPart {
        First,
        Second,
        Third
    };

    void Push(StackPart type, int value) {
        if (type == StackPart::First) {
            PushExact(firstEnd, value);
        } else if (type == StackPart::Second) {
            PushExact(secondEnd, value);
        } else if (type == StackPart::Third) {
            PushExact(thirdEnd, value);
        }
    }

    void Pop(StackPart type) {
        if (type == StackPart::First) {
            PopExact(firstEnd);
        } else if (type == StackPart::Second) {
            PopExact(secondEnd);
        } else if (type == StackPart::Third) {
            PopExact(thirdEnd);
        }
    }

    int Top(StackPart type) const{
        if (type == StackPart::First) {
            return TopExact(firstEnd);
        } else if (type == StackPart::Second) {
            return TopExact(secondEnd);
        } else if (type == StackPart::Third) {
            return TopExact(thirdEnd);
        }
        throw logic_error("No such part");
    }

private:
    void PushExact(int& end, int value) {
        if (end >= data.size()) {
            data.resize(data.size() + 3);
        }
        data[end] = value;
        end += 3;
    }

    void PopExact(int& end) {
        int box = end % 3;
        end -= 3;
        end = max(end, box);
    }

    int TopExact(int end) const {
        int i = end - 3;
        if (i < 0) {
            throw out_of_range("no elements");
        }
        return data[i];
    }

    vector <int> data;
    int firstEnd = 0;
    int secondEnd = 1;
    int thirdEnd = 2;
};

bool Test() {
    {
        TreeStacks data;

        vector <int> first = {0, 3, 6};
        vector <int> second = {1, 4, 7};
        vector <int> third = {2, 5, 8};

        for (int i = 0; i < 3; ++i) {
            data.Push(TreeStacks::StackPart::First, first[i]);
            data.Push(TreeStacks::StackPart::Second, second[i]);
            data.Push(TreeStacks::StackPart::Third, third[i]);
        }
        for (int i = 0; i < 3; ++i) {
            if (first[2 - i] != data.Top(TreeStacks::StackPart::First)) {
                return false;
            }
            data.Pop(TreeStacks::StackPart::First);
            if (second[2 - i] != data.Top(TreeStacks::StackPart::Second)) {
                return false;
            }
            data.Pop(TreeStacks::StackPart::Second);
            if (third[2 - i] != data.Top(TreeStacks::StackPart::Third)) {
                return false;
            }
            data.Pop(TreeStacks::StackPart::Third);
        }
    }
    {
        TreeStacks data;

        vector <int> first = {1, 2, 3, 4, 5};

        for (int i = 0; i < first.size(); ++i) {
            data.Push(TreeStacks::StackPart::First, first[i]);
        }
        for (int i = 0; i < first.size(); ++i) {
            if (first[first.size() - 1 - i] != data.Top(TreeStacks::StackPart::First)) {
                return false;
            }
            data.Pop(TreeStacks::StackPart::First);
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}