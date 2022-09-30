#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void pushFront(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (head) newNode -> next = head;
    head = newNode;
}

void pushBack(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (head) {
        Node *cur = head;
        while (cur -> next) cur = cur -> next;
        cur -> next = newNode;
    } else head = newNode;
}

void popFront() {
    if (head == NULL) return; 
    // any message can be written before return;

    Node *delNode = head;
    head = head -> next;
    delete delNode;
}

void popBack() {
    if (head == NULL) return; 
    // any message can be written before return;

    if (head -> next == NULL) {
        Node *delNode = head;
        head = head -> next;
        delete delNode;
        return;
    }

    Node *cur = head;
    while(cur -> next -> next) cur = cur -> next;
    Node *delNode = cur -> next;
    cur -> next = NULL;
    delete delNode;
}

int itemCount() {
    int count = 0;
    Node *cur = head; 
    while (cur) {
        count++;
        cur = cur -> next;
    }
    return count;
}

Node* findNode(int data) {
    Node* cur = head;
    while (cur) {
        if (cur -> data == data) return cur;
        cur = cur -> next;
    }
    return NULL;
}

void eraseData(int data) {
    Node *dataNode = findNode(data);
    Node *cur = head;
    if (dataNode) {
        if (dataNode == head) head = head -> next; 
        else {
            while (cur -> next != dataNode) cur = cur -> next;
            Node *prevNode = cur;
            prevNode -> next = dataNode -> next;
        }
        delete dataNode;
    } else cout << "Data Not Found!" << endl;
}

void addAfter(Node *prevNode, int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (prevNode != NULL) {
        newNode -> next = prevNode -> next;
        prevNode -> next = newNode;
    } else cout << "Key Not Found!" << endl;
}

void addBefore(Node* nextNode, int data) {
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (nextNode) {
        if (nextNode == head) {
            newNode -> next = head;
            head = newNode;
        } else {
            Node* cur = head;
            while (cur -> next != nextNode) cur = cur -> next;
            newNode -> next = nextNode;
            cur -> next = newNode;
        }
    } else cout << "Key Not Found!" << endl;
}

void insertAtPosition(int pos, int data) {
    if (pos < 1 || pos > itemCount() + 1) {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    
    if (pos == 1) {
        if (head) newNode -> next = head;
        head = newNode;
    } else {
        Node *nodeBefore = head;
        for (int i = 1; i < pos - 1; i++) {
            nodeBefore = nodeBefore -> next;
        }
        newNode -> next = nodeBefore -> next;
        nodeBefore -> next = newNode;
    }
}

void deletePosition(int pos) {
    if (pos < 1 || pos > itemCount()) {
        cout << "Invalid Position!" << endl;
        return;
    }

    if (pos == 1) {
        Node *delNode = head;
        head = head -> next;
        delete delNode;
        return;
    } else {
        Node *nodeBefore = head;
        for (int i = 1; i < pos - 1; i++) {
            nodeBefore = nodeBefore -> next;
        }
        Node *delNode = nodeBefore -> next;
        nodeBefore -> next = delNode -> next;
        delete delNode;
    }
}

void printList() {
    Node *cur = head; 
    while (cur != NULL) {
        cout << cur -> data << " ";
        cur = cur -> next;
    } cout << endl;
}

void reverseList() {
    Node *prev, *current, *after;
    prev = NULL;
    current = head;
    while (current != NULL) {
        after = current -> next;
        current -> next = prev;
        prev = current;
        current = after;
    }
    head = prev;
}

int main() {
    cout << "--> Push Front Three (03) Elements: 11 22 33" << endl;
    pushFront(11);
    pushFront(22);
    pushFront(33);
    cout << "Printing Elements... ";
    printList();

    cout << "--> Push Back Three (03) Elements: 52 62 72" << endl;
    pushBack(52);
    pushBack(62);
    pushBack(72);
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "--> Insert 55 at Position 1" << endl;
    insertAtPosition(1, 55);
    cout << "Printing Elements... ";
    printList();

    cout << "--> Insert 67 at Position 5" << endl;
    insertAtPosition(5, 67);
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Pop Front Two (02) Times." << endl;
    popFront();
    cout << "Printing Elements... ";
    printList();
    popFront();
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Pop Back Two (02) Times." << endl;
    popBack();
    cout << "Printing Elements... ";
    printList();
    popBack();
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Adding 31 before 11" << endl;
    Node *nodeCheck = findNode(11);
    addBefore(nodeCheck, 31);
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Adding 51 after 52" << endl;
    Node *checkNode = findNode(52);
    addAfter(checkNode, 51);
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Reversing the Linked List" << endl;
    reverseList();
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Erase 11 and 51" << endl;
    eraseData(11);
    cout << "Printing Elements... ";
    printList();
    eraseData(51);
    cout << "Printing Elements... ";
    printList();

    cout << endl;
    cout << "Printing Elements... ";
    printList();
    cout << "--> Delete Position 3" << endl;
    deletePosition(3); 
    cout << "Printing Elements... ";
    printList();
    return 0;
}


/*
--> Push Front Three (03) Elements: 11 22 33
Printing Elements... 33 22 11 
--> Push Back Three (03) Elements: 52 62 72
Printing Elements... 33 22 11 52 62 72 

--> Insert 55 at Position 1
Printing Elements... 55 33 22 11 52 62 72 
--> Insert 67 at Position 5
Printing Elements... 55 33 22 11 67 52 62 72 

Printing Elements... 55 33 22 11 67 52 62 72 
--> Pop Front Two (02) Times.
Printing Elements... 33 22 11 67 52 62 72 
Printing Elements... 22 11 67 52 62 72 

Printing Elements... 22 11 67 52 62 72 
--> Pop Back Two (02) Times.
Printing Elements... 22 11 67 52 62 
Printing Elements... 22 11 67 52 

Printing Elements... 22 11 67 52 
--> Adding 31 before 11
Printing Elements... 22 31 11 67 52 

Printing Elements... 22 31 11 67 52 
--> Adding 51 after 52
Printing Elements... 22 31 11 67 52 51 

Printing Elements... 22 31 11 67 52 51 
--> Reversing the Linked List
Printing Elements... 51 52 67 11 31 22 

Printing Elements... 51 52 67 11 31 22 
--> Erase 11 and 51
Printing Elements... 51 52 67 31 22 
Printing Elements... 52 67 31 22 

Printing Elements... 52 67 31 22 
--> Delete Position 3
Printing Elements... 52 67 22
*/
