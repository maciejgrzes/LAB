#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {    
    int key = -1;
    string data = "";
    Node* next = nullptr;
};

Node* head = nullptr;
Node* lastAdded = nullptr;

void insertNode(int key, string data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        lastAdded = newNode;
    } else {
        lastAdded->next = newNode;
        lastAdded = newNode;
    }
}

void displayList() {
    cout << "The entire list:" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
    }
}

void displayMenu() {
    cout << "1. Insert new element" << endl;
    cout << "2. Delete element" << endl;
    cout << "3. Display list" << endl;
    cout << "4. Exit" << endl;
    cout << "Select option: ";
}

void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Naciśnij Enter aby kontynuować...";
    cin.get();
}

int main() {
    bool running = true;
    int option;

    while (running) {
        cout << "\033[2J\033[1;1H";
        displayMenu();
        cin >> option;

        if (option < 1 || option > 3) running = false;

        switch (option) {
        // Adding nodes
        case 1: {
            int key;
            string data;
            cout << "Enter node's key: ";
            cin >> key;
            cout << "Enter node's data: ";
            cin >> data;
            insertNode(key, data);
            displayList();
            pressEnter();
            break;
        }

        case 2:
            //TODO
            break;

        case 3:
            displayList();
            pressEnter();
            break;
        }
    }

    return 0;
}
