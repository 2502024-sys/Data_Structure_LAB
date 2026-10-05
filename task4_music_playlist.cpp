// Task 4: Music Playlist using a Circular Singly Linked List (OOP Node class)
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string songName;
    Node* next;

    Node(string name) {
        songName = name;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    // Add a song at the end; last node points to head (never NULL)
    void addSong(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        count++;
    }

    // Display all songs once
    void displayOnce() {
        cout << "Playlist (all songs once):" << endl;
        Node* temp = head;
        int i = 1;
        do {
            cout << i++ << ". " << temp->songName << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Simulate playing the playlist for a number of complete rounds.
    // After the last song, the next pointer automatically continues from the first.
    void play(int rounds) {
        Node* temp = head;
        int totalSongs = rounds * count;
        for (int i = 1; i <= totalSongs; i++) {
            if ((i - 1) % count == 0)
                cout << "--- Round " << ((i - 1) / count + 1) << " ---" << endl;
            cout << "Now playing: " << temp->songName << endl;
            temp = temp->next;          // wraps from last song to first
        }
    }

    ~Playlist() {
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
    Playlist playlist;

    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Perfect");
    playlist.addSong("Believer");
    playlist.addSong("Counting Stars");

    playlist.displayOnce();
    cout << endl;
    playlist.play(2);

    return 0;
}
