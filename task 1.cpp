// Task 1: Browser History using a Doubly Linked List (OOP Node class)
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string site) {
        website = site;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* head;   // first visited
    Node* tail;   // last visited

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    // Add a newly visited website at the end of the history
    void visit(string site) {
        Node* newNode = new Node(site);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display history from first visited -> last visited (using next)
    void displayForward() {
        cout << "History (first visited -> last visited):" << endl;
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << i++ << ". " << temp->website << endl;
            temp = temp->next;
        }
    }

    // Display history in reverse order, last -> first (using prev)
    void displayReverse() {
        cout << "History (last visited -> first visited):" << endl;
        Node* temp = tail;
        int i = 1;
        while (temp != NULL) {
            cout << i++ << ". " << temp->website << endl;
            temp = temp->prev;
        }
    }

    ~BrowserHistory() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    BrowserHistory history;

    history.visit("google.com");
    history.visit("youtube.com");
    history.visit("github.com");
    history.visit("stackoverflow.com");
    history.visit("wikipedia.org");

    history.displayForward();
    cout << endl;
    history.displayReverse();

    return 0;
}
