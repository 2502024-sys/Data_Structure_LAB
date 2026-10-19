#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
    int q[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Buffer Full! Packet " << id << " not added.\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        q[rear] = id;
        count++;
        cout << "Packet " << id << " added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Buffer Empty! No packet to transmit.\n";
            return;
        }
        cout << "Transmitting packet " << q[front] << ".\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets waiting.\n";
            return;
        }
        cout << "Packets waiting: ";
        for (int i = 0; i < count; i++)
            cout << q[(front + i) % SIZE] << " ";
        cout << "\n";
    }
};

int main() {
    CircularQueue network;
    cout << "NETWORK DATA PACKET MANAGEMENT\n";
    network.enqueue(201);
    network.enqueue(202);
    network.enqueue(203);
    network.display();
    network.dequeue();
    network.enqueue(204);
    network.enqueue(205);
    network.enqueue(206);
    network.display();
    return 0;
}