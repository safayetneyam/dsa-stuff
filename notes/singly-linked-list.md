## Singly Linked List 

### pushFront : Global
```cpp
void pushFront(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (head) newNode -> next = head;
    head = newNode;
}
```

### pushBack : Global
```cpp
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
```

### popFront : Global
```cpp
void popFront() {
    if (head == NULL) return; 
    // any message can be written before return;

    Node *delNode = head;
    head = head -> next;
    delete delNode;
}
```

### popBack : Global
```cpp
void popBack() {
    if (head == NULL) return; 
    // any message can be written before return;

    if (head -> next == NULL) {
        Node *delNode = head;
        head = head -> next;    // head = NULL;
        delete delNode;
        return;
    }

    Node *cur = head;
    while(cur -> next -> next) cur = cur -> next;
    Node *delNode = cur -> next;
    cur -> next = NULL;
    delete delNode;
}
```

```cpp
    // Alternative & Short
    
    Node *cur = head;
    while(cur -> next -> next) cur = cur -> next;
    Node *delNode = cur -> next;
    cur -> next = NULL;
    delete delNode;
```

### findNode : Global
```cpp
Node* findNode(int data) {
    Node* cur = head;
    while (cur) {
        if (cur -> data == data) return cur;
        cur = cur -> next;
    }
    return NULL;
}
```

### eraseData : Global
```cpp
void eraseData(int data) {
    Node *dataNode = NULL, *checkNode = head;
    while (checkNode) {
        if (checkNode -> data == data) {
            dataNode = checkNode;
            break;
        }
        checkNode = checkNode -> next;
    }

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
```

### eraseData : Global
- include findNode function
```cpp
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
```

### addAfter : Global
- include findNode function
- by passing (found from findNode function) and the data to be added
```cpp
void addAfter(Node *prevNode, int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (prevNode != NULL) {
        newNode -> next = prevNode -> next;
        prevNode -> next = newNode;
    } else cout << "Key Not Found!" << endl;
}
```

### addBefore : Global
- include findNode function
- by passing (found from findNode function) and the data to be added
```cpp
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
```

### reverseList : Global
```cpp
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
```

### printList : Global
```cpp
void printList() {
    Node *cur = head;
    while (cur != NULL) {
        cout << cur -> data << " ";
        cur = cur -> next;
    } cout << endl;
}
```

### insertAtPosition : Global
```cpp
int itemCount() {
    int count = 0;
    Node *cur = head; 
    while (cur) {
        count++;
        cur = cur -> next;
    }
    return count;
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
```
