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
            cout << "Processed: " << top->id << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->id << endl;
            temp = temp->next;
        }
    }

    void showTop() {
        if (top != NULL)
            cout << "Current TOP: " << top->id << endl;
    }

    void isEmpty() {
        if (top == NULL)
            cout << "Stack is Empty" << endl;
        else
            cout << "Stack is Not Empty" << endl;
    }
};

int main() {
    Stack s;

    s.push("ORD-101");
    s.push("ORD-102");
    s.push("ORD-103");
    s.push("ORD-104");

    cout << "All Orders:" << endl;
    s.display();

    s.pop();
    s.pop();

    s.showTop();

    cout << "Remaining Orders:" << endl;
    s.display();

    s.isEmpty();

    return 0;
}
