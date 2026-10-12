#include <iostream>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string x) {
        id = x;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* n = new Node(id);
        n->next = top;
        top = n;
    }

    void pop() {
        if (top != NULL) {
            cout << "Handled: " << top->id << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void showTop() {
        if (top != NULL)
            cout << "New TOP: " << top->id << endl;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->id << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "All Requests:" << endl;
    s.display();

    s.pop();
    s.showTop();

    cout << "Remaining Requests:" << endl;
    s.display();

    return 0;
}
