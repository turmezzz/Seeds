//
// Queue for dogs and cats
//
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>

using namespace std;

struct Buddy {

    Buddy(const string& name) : name(name) {
    }

    string name;
};

class AnimalShelter {
public:

    void Enqueue(bool isDog = true, const string& name = "") {
        if (isDog) {
            dogs.emplace(time++, name);
        } else {
            cats.emplace(time++, name);
        }
    }

    Buddy DequeueAny() {
        if (dogs.empty() and cats.empty()) {
            throw out_of_range("world is okay");
        }
        int dogTime = dogs.empty() ? INT32_MAX : dogs.front().first;
        int catTime = cats.empty() ? INT32_MAX : cats.front().first;
        if (dogTime < catTime) {
            auto buddy = dogs.front().second;
            dogs.pop();
            return buddy;
        } else {
            auto buddy = cats.front().second;
            cats.pop();
            return buddy;
        }
    }

    Buddy DequeueDog() {
        if (dogs.empty()) {
            throw out_of_range("check cats");
        }
        auto buddy = dogs.front().second;
        dogs.pop();
        return buddy;
    }

    Buddy DequeueCat() {
        if (cats.empty()) {
            throw out_of_range("check dogs");
        }
        auto buddy = cats.front().second;
        cats.pop();
        return buddy;
    }

private:
    queue <pair <int, Buddy>> dogs;
    queue <pair <int, Buddy>> cats;
    int time = 0;
};

bool Test() {
    {
        vector <string> dogs = {"rex", "boss"};
        vector <string> cats = {"pushok", "solomon"};
        AnimalShelter shelter;
        shelter.Enqueue(true, dogs[0]);
        shelter.Enqueue(false, cats[0]);
        shelter.Enqueue(true, dogs[1]);
        shelter.Enqueue(false, cats[1]);

        if (shelter.DequeueAny().name != "rex") {
            return false;
        }
        if (shelter.DequeueDog().name != "boss") {
            return false;
        }
        if (shelter.DequeueCat().name != "pushok") {
            return false;
        }
        if (shelter.DequeueAny().name != "solomon") {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}
