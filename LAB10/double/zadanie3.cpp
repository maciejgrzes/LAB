#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {    
    int key = -1;
    string data = "";
    Node* next = nullptr;
    Node* prev = nullptr; 
};

Node* head = nullptr;
Node* lastAdded = nullptr;

Node* whichNode(int index) {
    if (index < 0) return nullptr;
    Node* element = head;
    for (int i = 0; i < index && element != nullptr; i++)
        element = element->next;
    return element;
}

void insertNode(int key, string data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        lastAdded = newNode;
    } else {
        lastAdded->next = newNode;
        newNode->prev = lastAdded;
        lastAdded = newNode;
    }
}

void insertNodeAtSpecifiedPlace(int index, int key, string data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    Node* nodeAtIndex = whichNode(index-1);

    if (nodeAtIndex->next == nullptr) {
        insertNode(key, data);
        return;
    } else if (nodeAtIndex == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = nodeAtIndex;
        newNode->next = nodeAtIndex->next;
        if (nodeAtIndex->next)
            nodeAtIndex->next->prev = newNode;
        nodeAtIndex->next = newNode;
        if (newNode->next == nullptr)
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

void displayListBackwards() {
    Node* temp = lastAdded;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    while (temp != nullptr) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->prev;
    }
}



void deleteNode(Node* node) {
    if (!node) return;
    if (node == head && node->next == nullptr) {
        delete node;
        head = nullptr;
        lastAdded = nullptr;
    }
    else if (node == head) {
        Node* newHead = node->next;
        delete node;
        head = newHead;
        head->prev = nullptr;
    }
    else if (node->next == nullptr) {
        lastAdded = node->prev;
        lastAdded->next = nullptr;
        delete node;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
}



void displayMenu() {
    cout << "1. Insert new element" << endl;
    cout << "2. Insert new element at specified place" << endl;
    cout << "3. Delete element" << endl;
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
        // Adding at specified place
        case 2: {
            displayList();
            int index;
            cout << "After which node to add?";
            cin >> index;
            int key;
            string data;
            cout << "Enter node's key: ";
            cin >> key;
            cout << "Enter node's data: ";
            cin >> data;
            insertNodeAtSpecifiedPlace(index, key, data);
            displayList();
            break;
        }
        // Deleting nodes
        case 3: {
            displayList();
            int index;
            cout << "Which element to remove? ";
            cin >> index;

            deleteNode(whichNode(index-1));
            displayList();
            pressEnter();
            break;
        }
        // Displaying list
        case 4:
            displayList();
            displayListBackwards();
            pressEnter();
            break;
        }
    }

    return 0;
}
