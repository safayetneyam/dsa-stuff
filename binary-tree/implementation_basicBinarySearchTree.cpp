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


/*
How Many Numbers: 5            
Enter Numbers: 12 15 8 10 13
Enter Number to Search: 8 
8 is there!
*/
