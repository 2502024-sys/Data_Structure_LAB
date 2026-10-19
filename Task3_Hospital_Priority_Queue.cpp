#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
    Patient p[SIZE];
    int count;

public:
    PriorityQueue() { count = 0; }

    bool isEmpty() { return count == 0; }

    void insert(string id, int priority) {
        if (count == SIZE) {
            cout << "Queue Full! Cannot add " << id << ".\n";
            return;
        }
        p[count].id = id;
        p[count].priority = priority;
        count++;
        cout << "Patient " << id << " added with priority " << priority << ".\n";
    }

    void treatNext() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        int best = 0;
        for (int i = 1; i < count; i++)
            if (p[i].priority < p[best].priority) best = i;

        cout << "Treating patient " << p[best].id
             << " (priority " << p[best].priority << ").\n";
        for (int i = best; i < count - 1; i++) p[i] = p[i + 1];
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Waiting patients (ID - Priority):\n";
        for (int i = 0; i < count; i++)
            cout << p[i].id << " - " << p[i].priority << "\n";
    }
};

int main() {
    PriorityQueue hospital;
    cout << "HOSPITAL EMERGENCY DEPARTMENT\n";
    hospital.insert("P101", 3);
    hospital.insert("P102", 1);
    hospital.insert("P103", 2);
    hospital.display();
    hospital.treatNext();
    hospital.display();
    return 0;
}