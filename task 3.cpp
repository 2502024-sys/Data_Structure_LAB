// Task 3: Game Player Turns using a Circular Singly Linked List (OOP Node class)
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string playerName;
    Node* next;

    Node(string name) {
        playerName = name;
        next = NULL;
    }
};

class GameTurns {
private:
    Node* head;
    Node* tail;

public:
    GameTurns() {
        head = NULL;
        tail = NULL;
    }

    // Add a player at the end; the last node always points back to head
    void addPlayer(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;          // circular connection
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;          // keep the circle closed
        }
    }

    // Display each player's turn once
    void displayTurns() {
        cout << "Each player's turn:" << endl;
        Node* temp = head;
        int turn = 1;
        do {
            cout << "Turn " << turn++ << ": " << temp->playerName << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Show that after the last player the turn returns to the first player
    void showCircular() {
        cout << "Last player  : " << tail->playerName << endl;
        cout << "Next turn of last player goes to: " << tail->next->playerName
             << " (first player)" << endl;
    }

    ~GameTurns() {
        if (head == NULL) return;
        tail->next = NULL;              // break the circle before deleting
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    GameTurns game;

    game.addPlayer("Ali");
    game.addPlayer("Sara");
    game.addPlayer("Ahmed");
    game.addPlayer("Fatima");
    game.addPlayer("Hassan");

    game.displayTurns();
    cout << endl;
    game.showCircular();

    return 0;
}
