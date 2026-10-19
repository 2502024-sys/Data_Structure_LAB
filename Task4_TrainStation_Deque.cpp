#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
    int q[SIZE];
    int front, rear, count;

public:
    Deque() { front = 0; rear = -1; count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque Full! Cannot add at front.\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else front = (front - 1 + SIZE) % SIZE;
        q[front] = id;
        count++;
        cout << "Passenger request " << id << " added at front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque Full! Cannot add at rear.\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        q[rear] = id;
        count++;
        cout << "Passenger request " << id << " added at rear.\n";
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Deque Empty! Nothing to remove at front.\n";
            return;
        }
        cout << "Removed from front: " << q[front] << ".\n";
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) { front = 0; rear = -1; }
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Deque Empty! Nothing to remove at rear.\n";
            return;
        }
        cout << "Removed from rear: " << q[rear] << ".\n";
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
        if (count == 0) { front = 0; rear = -1; }
    }

    void display() {
        if (isEmpty()) {
            cout << "No passenger requests.\n";
            return;
        }
        cout << "Requests (front to rear): ";
        for (int i = 0; i < count; i++)
            cout << q[(front + i) % SIZE] << " ";
        cout << "\n";
    }
};

int main() {
    Deque station;
    cout << "TRAIN STATION PASSENGER MANAGEMENT\n";
    station.insertRear(301);
    station.insertRear(302);
    station.insertFront(300);
    station.display();
    station.removeFront();
    station.display();
    station.removeRear();
    station.display();
    return 0;
}