## Singly Linked List 

### pushFront (Insert/Add at First) : Global
```cpp
void pushFront(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (head) newNode -> next = head;
    head = newNode;
}
```

### pushBack (Insert/Add at Last) : Global
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

### popFront (Delete at First) : Global
```cpp
void popFront() {
    if (head == NULL) return; 
    // any message can be written before return;

    Node *delNode = head;
    head = head -> next;
    delete delNode;
}
```

### popBack (Delete at Last) : Global
```cpp
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
```

```cpp
    // Alternative & Short
    
    Node *cur = head;
    while(cur -> next -> next) cur = cur -> next;
    Node *delNode = cur -> next;
    cur -> next = NULL;
    delete delNode;
```
