## Singly Linked List; v02

### deletePosition : Global
```cpp
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
```


### sortedInsert : Global
```cpp
void sortedInsert(int item) {
    Node *newNode = new Node();
    newNode -> data = item;
    newNode -> next = NULL;

    if (!head || head -> data >= item) {
        // InsertAtFirst(item);
        if (head != NULL) newNode -> next = head;
        head = newNode;
        return;
    }

    Node *nodeBefore = head;
    while (nodeBefore -> next != NULL && nodeBefore -> next -> data < item) {
        nodeBefore = nodeBefore -> next;
    }
    newNode -> next = nodeBefore -> next;
    nodeBefore -> next = newNode;
}
```


### findMin : Global
```cpp
void findMin() {
    if (head == NULL) {
        cout << "No Item Found!" << endl;
        return;
    }
    
    Node *cur = head;
    int minVal = cur -> data;
    while (cur != NULL) {
        if (cur -> data < minVal) minVal = cur -> data;
        cur = cur -> next;
    }
    cout << "Minimum Value: " << minVal << endl;
}
```


### findMax : Global
```cpp
void findMax() {
    if (head == NULL) { 
        cout << "No Item Found!" << endl;
        return;
    }
    
    Node *cur = head;
    int maxVal = cur -> data;
    while (cur != NULL) {
        if (cur -> data > maxVal) maxVal = cur -> data;
        cur = cur -> next;
    }
    cout << "Maximum Value: " << maxVal << endl;
}
```


### makeListSorted : Global
- include sortedInsert function
```cpp
void makeListSorted() {
    Node *tempHead = head;
    head = NULL;
    Node *cur = tempHead;
    while (cur != NULL) {
        sortedInsert(cur -> data);
        cur = cur -> next;
    }
}
```


### removeDuplicates : Global
```cpp
void removeDuplicates() {
    Node *cur = head;
    while (cur != NULL) { // && cur -> next != NULL
        Node *temp = cur;
        while (temp -> next != NULL) {
            if (cur -> key == temp -> next -> key) {
                Node *del_dupli = temp -> next;
                temp -> next = temp -> next -> next;
                delete del_dupli;
            }
            else temp = temp -> next;  
        }
        cur = cur -> next;
    }
}
```
