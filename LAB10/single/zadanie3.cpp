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
    Node* temp = head;
    int i = 1;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    while (temp != nullptr) {
        cout << "Index: " << i << ", Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

Node* whichNode(int index) {
    Node* elementToDelete = head;

    for (int i = 0; i < index; i++) {
        elementToDelete = elementToDelete->next;
    }
    return elementToDelete;
}

void deleteNode(Node* node) {
    if (head == nullptr) {
        return;
    } else if (head == node && node->next == nullptr) {
        delete head;
        head = nullptr;
    } else if (head == node && node->next != nullptr) {
        delete head;
        head = node->next;
    } else if (head != node && node->next == nullptr) {
        Node* element = head;
        while (element->next != node) {
            element = element->next;
        }
        element->next = nullptr;
        delete node;
        lastAdded->next = element;
        lastAdded = element;
    } else {
        Node* element = head;
        while (element->next != node) {
            element = element->next;
        }
        element->next = node->next;
        delete node;
    }
}


void displayMenu() {
    cout << "1. Insert new element" << endl;
    cout << "2. Delete element" << endl;
    cout << "3. Modify element" << endl;
    cout << "4. Display list" << endl;
    cout << "5. Exit" << endl;
    cout << "Select option: ";
}

void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Press Enter to continue...";
    cin.get();
}

int main() {
    bool running = true;
    int option;

    while (running) {
        cout << "\033[2J\033[1;1H";
        displayMenu();
        cin >> option;

        if (option < 1 || option > 4) running = false;

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
        // Deleting nodes
        case 2: {
            displayList();
            int index;
            cout << "Which element to remove? ";
            cin >> index;

            deleteNode(whichNode(index-1));
            displayList();
            pressEnter();
            break;
        }
        // Modifing nodes
        case 3: {
            displayList();
            int index;
            cout << "Which element to remove? ";
            cin >> index;

            int newKey;
            string newData;
            cout << "Enter node's new key: ";
            cin >> newKey;
            cout << "Enter node's new data: ";
            cin >> newData;

            Node* node = whichNode(index-1);
            node->key = newKey;
            node->data = newData;

            displayList();
            pressEnter();
            break;
        }

        case 4:
            displayList();
            pressEnter();
            break;
        }
    }

    return 0;
}
