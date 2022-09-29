## Singly Linked List 

### pushFront (Insert/Add at First) : Global
```cpp=
void pushFront(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (head) newNode -> next = head;
    head = newNode;
}
```

### pushBack (Insert/Add at Last) : Global
```cpp=
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
