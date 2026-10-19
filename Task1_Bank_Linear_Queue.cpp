#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
    int q[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add " << token << ".\n";
            return;
        }
        if (isEmpty()) front = 0;
        q[++rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customer to serve.\n";
            return;
        }
        cout << "Serving customer " << q[front] << ".\n";
        if (front == rear) front = rear = -1;
        else front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No waiting customers.\n";
            return;
        }
        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) cout << q[i] << " ";
        cout << "\nNumber waiting: " << rear - front + 1 << "\n";
    }
};

int main() {
    LinearQueue bank;
    cout << "BANK CUSTOMER SERVICE SYSTEM\n";
    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);
    bank.display();
    bank.dequeue();
    bank.display();
    return 0;
}