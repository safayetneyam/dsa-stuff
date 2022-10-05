## Binary Tree
`Ref. GFG`

A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right children.

## Binary Search Tree
`Ref. GFG`

A binary Search Tree is a node-based binary tree data structure that has the following properties:

* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree each must also be a binary search tree.
* There must be no duplicate nodes.

```
Issues on Duplicate Notes.
According to GFG, No Duplicate Nodes.
According to MCS, Left to Root Node.
According to MRH1, Right to Root Node.
```

### Node Structure
```cpp=
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};
```

### Basic Implementation
> `ref. mycodeschool` 
```cpp=
#include <iostream>
using namespace std;

struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *getNewNode(int data) {
    bstNode *newNode = new bstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

bstNode *insert(bstNode *root, int data) {
    if (root == NULL) root = getNewNode(data);
    else if (data <= root -> data) root -> left = insert(root -> left, data);
    else root -> right = insert(root -> right, data);
    return root;
}

bool search(bstNode *root, int data) {
    if (root == NULL) return false;
    if (root -> data == data) return true;
    else if (data <= root -> data) return search(root -> left, data);
    else return search(root -> right, data);
}

int main() {
    bstNode *root = NULL;
    cout << "How Many Numbers to Insert: ";
    int howMany; cin >> howMany;
    cout << "Enter Numbers: ";
    for (int i = 1; i <= howMany; i++) {
        int temp; cin >> temp;
        root = insert(root, temp);
    }
    cout << "Enter Number to Search: ";
    int num; cin >> num;
    bool check = search(root, num);
    if (check) cout << num << " is there!" << endl;
    else cout <<  num << " is not there!" << endl;
}
```

> `output.txt`
```txt
How Many Numbers: 5            
Enter Numbers: 12 15 8 10 13
Enter Number to Search: 8 
8 is there!
```

### Insert Element (Recursive Call)
> `ref. mycodeschool` 
```cpp=
bstNode *getNewNode(int data) {
    bstNode *newNode = new bstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

bstNode *insert(bstNode *root, int data) {
    if (root == NULL) root = getNewNode(data);
    else if (data <= root -> data) root -> left = insert(root -> left, data);
    else root -> right = insert(root -> right, data);
    return root;
}
```

### Search Element; return Boolean (Recursive Call)
> `ref. mycodeschool` 
```cpp=
bool search(bstNode *root, int data) {
    if (root == NULL) return false;
    if (root -> data == data) return true;
    else if (data <= root -> data) return search(root -> left, data);
    else return search(root -> right, data);
}
```

### Find Node; return Node (Recursive Call)
> `ref. mycodeschool` 
```cpp=
bstNode *findNode(bstNode *root, int data) {
    if (root == NULL) return NULL;
    else if (root -> data == data) return root;
    else if (root -> data < data) return findNode(root -> right, data);
    else return findNode(root -> left, data);
}
```

### Find Minimum; return Value (Recursive Call)
> `ref. mycodeschool` 
```cpp=
int findMin(bstNode *root) {
    if (root == NULL) {
        cout << "Error! Empty Tree." << endl;
        return -1;
    } else if (root -> left == NULL) return root -> data;
    else return findMin(root -> left);
}
```

### Find Maximum; return Value (Recursive Call) 
> `ref. mycodeschool` 
```cpp=
int findMax(bstNode *root) {
    if (root == NULL) {
        cout << "Error! Empty Tree." << endl;
        return -1;
    } else if (root -> right == NULL) return root -> data;
    else return findMax(root -> right);
}
```

### Find Minimum; return Node (Iterative Call)
> `ref. mycodeschool`
```cpp=
bstNode *findMinimum(bstNode *root) {
    if (root == NULL) return NULL;
    while (root -> left != NULL) root = root -> left;
    return root;
}
```

### Delete Item (Recursive Call)
> `ref. mycodeschool`
```cpp=
// Must Add Functions (findMinimum)

bstNode *delItem(bstNode *root, int data) {
    if (root == NULL) return root;
    else if (data < root -> data) root -> left = delItem(root -> left, data);
    else if (data > root -> data) root -> right = delItem(root -> right, data);
    else {
        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            root = NULL;
        } else if (root -> left == NULL) {
            bstNode *temp = root;
            root = root -> right;
            delete temp;
        } else if (root -> right == NULL) {
            bstNode *temp = root;
            root = root -> left;
            delete temp;
        } else {
            bstNode *temp = findMinimum(root -> right);
            root -> data = temp -> data;
            root -> right = delItem(root -> right, temp -> data);
        }
    }
    return root;
}
```

### Get Inorder Successor 
> `ref. mycodeschool` 
```cpp=
// Must Add Functions (findNode, findMinimum)

bstNode *getSuccessor(bstNode *root, int data) {
    bstNode *cur = findNode(root, data);
    if (cur == NULL) return NULL;
    if (cur -> right != NULL) {
        return findMinimum(cur -> right);
    } else {
        bstNode *successor = NULL;
        bstNode *ancestor = root;
        while (ancestor != cur) {
            if (cur -> data < ancestor -> data) {
                successor = ancestor;
                ancestor = ancestor -> left;
            } else ancestor = ancestor -> right;
        }
        return successor;
    }
}
```

## Traversal Techniques

### Node Structure
```cpp=
// replace bstNode with Node, if needed
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};
```

### Height of Binary Tree (Recursive Call)
> `ref. mycodeschool` 
```cpp=
int findHeight(bstNode *root) {
    if (root == NULL) return -1;
    else return max(findHeight(root -> left), findHeight(root -> right) + 1);
}
```
### Traversal of Binary Tree 

![binaryTree](https://user-images.githubusercontent.com/65675816/193988958-5c32b872-6375-4abe-adc9-14bda7a3cf17.png)


```
Insertion of Elements (11): 30 25 28 18 23 12 50 75 39 47 42
```

* Beadth First 
    * Level Order
    (30,25,50,18,28,39,75,12,23,47,42)
* Depth First
    * Preorder (Root, Left, Right)
    (30,25,18,12,23,28,50,39,47,42,75)
    * Inorder (Left, Root, Right)
    (12,18,23,25,28,30,39,42,47,50,75)
    * Postorder (Left, Right, Root)
    (12,23,18,28,25,42,47,39,75,50,30)

```
                30
               /  \ 
             25    50 
            /  \   / \
           18  28 39 75
          / \      \
         12  23    47
                   /
                  42
```

### Breadth First or Level Order Traversal
> `ref. mycodeschool` 
```cpp=
void levelOrder(bstNode *root) {
    if (root == NULL) return;
    queue <bstNode*> Qu;
    Qu.push(root);
    while (!Qu.empty()) {
        bstNode *cur = Qu.front();
        Qu.pop();
        cout << cur -> data << " ";
        if (cur -> left != NULL) Qu.push(cur -> left);
        if (cur -> right != NULL) Qu.push(cur -> right);
    }
}
```

### Depth First Traversal

```
Time Complexity: O(n)
  Worst Case: O(n)
  Best/Average Case: O(log n)
Space Complecity: O(h)

n - number of elements
h - height of tree
```

#### Preorder Traversal
> `ref. mycodeschool` 
```cpp=
void preorder(bstNode *root) {
    if (root == NULL) return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}
```

#### Inorder Traversal
> `ref. mycodeschool` 
```cpp=
void inorder(bstNode *root) {
    if (root == NULL) return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}
```

#### Postorder Traversal
> `ref. mycodeschool` 
```cpp=
void postorder(bstNode *root) {
    if (root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}
```

## Other Implementations
- Check if Binary Search Tree
- Check if Binary Search Tree (Inorder Traversal)

### Check if Binary Search Tree
```
Note

* It will always return true, as the insertion is already binary tree based.
* lesser or equal elements other than root element are inserted in the left subtree.
* greater elements other than root element are inserted in the right subtree.
```
> `ref. mycodeschool` 
```cpp=
bool isSubtreeLesser(bstNode *root, int val) {
    if (root == NULL) return true;
    if (root -> data <= val 
    && isSubtreeLesser(root -> left, val) 
    && isSubtreeLesser(root -> right, val)) {
        return true;
    } else return false; 
}

bool isSubtreeGreater(bstNode *root, int val) {
    if (root == NULL) return true;
    if (root -> data > val 
    && isSubtreeGreater(root -> left, val) 
    && isSubtreeGreater(root -> right, val)) {
        return true;
    } else return false; 
}

bool isBinarySearchTree(bstNode *root) {
    if (root == NULL) return true;
    if (isSubtreeLesser(root -> left, root -> data) && isSubtreeGreater(root -> right, root -> data) 
    && isBinarySearchTree(root -> left) && isBinarySearchTree(root -> right)) {
        return true;
    } else return false;
}
```

> `ref. mycodeschool (efficient approach)`
```cpp=
// Must Include 'climits/limits.h/bitsc++.h' Header

/* 
This Program Is Handled Only for Elements 
Strictly Lesser or Greater than the Compared Element, 
But for Duplicate Elements.
*/

bool isBstUtil(bstNode *root, int minVal, int maxVal) {
    if (root == NULL) return true;
    if (root -> data > minVal && root -> data < maxVal 
    && isBstUtil(root -> left, minVal, root -> data) 
    && isBstUtil(root -> right, root -> data, maxVal)) {
        return true;
    } else return false;
}

bool isBinarySearchTree(bstNode *root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
}
```

### Check if Binary Search Tree (Inorder Traversal)

Ref. 
* [GFG](https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/)
* [Pseudo](https://www.baeldung.com/cs/bst-validation)
* [TechieDelight](https://www.techiedelight.com/determine-given-binary-tree-is-a-bst-or-not/)

> `GeeksForGeeks`
```cpp=
bool isBSTUtilForInorder(bstNode* root, bstNode *&prev) {
    if (root) {
        if (!isBSTUtilForInorder(root -> left, prev)) return false;
        if (prev != NULL && root -> data <= prev -> data) return false;
        prev = root;
        return isBSTUtilForInorder(root -> right, prev);
    }
    return true;
}

bool isBstInorder(bstNode *root) {
   bstNode *prev = NULL;
   return isBSTUtilForInorder(root, prev);
}
```
