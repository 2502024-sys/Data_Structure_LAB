#include <iostream>
using namespace std;

class Stack {
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        actions[++top] = action;
    }

    void pop() {
        cout << "Undo: " << actions[top--] << endl;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << actions[i] << endl;
    }

    void showTop() {
        cout << "Current TOP: " << actions[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Type Hello");
    s.push("Type World");
    s.push("Add !");
    s.push("Delete !");

    cout << "All Actions:" << endl;
    s.display();

    s.pop();
    s.pop();

    s.showTop();

    cout << "Remaining Actions:" << endl;
    s.display();

    return 0;
}
