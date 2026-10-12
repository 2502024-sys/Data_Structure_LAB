#include <iostream>
using namespace std;

class Stack {
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        pages[++top] = page;
    }

    void pop() {
        cout << "Removed: " << pages[top--] << endl;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << pages[i] << endl;
    }

    void showTop() {
        cout << "Current TOP: " << pages[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Google");
    s.push("YouTube");
    s.push("Facebook");
    s.push("GitHub");

    cout << "Browsing History:" << endl;
    s.display();

    s.pop();

    s.showTop();

    cout << "Remaining History:" << endl;
    s.display();

    return 0;
}
