#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
    int key = -1;
    string data = "";
    Node* next = nullptr;
    Node* prev = nullptr;
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
    while (temp != nullptr) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int n, key;
    string data;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter key and data for node " << i + 1 << ": " << endl;
        cout << "Please write integer number: ";
        cin >> key;
        cout << "Please write any string: ";
        cin >> data;
        insertNode(key, data);
    }

    cout << "The entire list:" << endl;
    displayList();
}
