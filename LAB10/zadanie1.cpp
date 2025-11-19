#include <iostream>
#include <random>
#include <string>
using namespace std;


string generateRandomString(int length) {
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> index(0, CHARACTERS.size() - 1);

    string random_string;
    for (int i = 0; i < length; ++i) {
        random_string += CHARACTERS[index(gen)];
    }
    return random_string;
}

struct Node {    
    int key = -1;
    string data = "";
    Node* next = nullptr;
};

Node* head = nullptr; //globalny wskaznik zawsze pokazujacy pierszy wezel
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        insertNode(i, generateRandomString(4));
    }

    cout << "The entire list:" << endl;
    displayList();
}
