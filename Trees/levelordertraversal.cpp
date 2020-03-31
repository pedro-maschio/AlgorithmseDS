#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
        void printGivenLevel(Node *root, int level);
        void printLevelOrder(Node *root, int level);
        int height(Node *root);
        void printLevel(Node *root);
};

// O(n^2) complexity :(
void Node::printLevelOrder(Node *root, int level) {
    int h = height(root);

    for(int i = 1; i <= h; i++)
        printGivenLevel(root, i); 
}
void Node::printGivenLevel(Node *root, int level) {
    if(!root)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
// END of solution with O(n^2) complexity
 
// O(n) complexity :)
void Node::printLevel(Node *root) {
    if(!root)
        return;
    queue<Node *> fila;
    fila.push(root);

    while(!fila.empty()) {
        Node *node = fila.front();
        cout << node->data << " ";
        fila.pop();

        if(node->left != nullptr)
            fila.push(node->left);
        if(node->right != nullptr)
            fila.push(node->right);
    }
}


int Node::height(Node *root) {
    if(!root)   
        return 0;
    else {
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if(lHeight > rHeight)
            return lHeight + 1;
        else 
            return rHeight + 1;
    }
}

Node *criaNo(int data) {
    Node *no = new Node(data);

    return no;
}

Node* insere(Node *root, int data) {
    if(!root) {
        return criaNo(data);
    } else {
        if(data < root->data)
            root->left = insere(root->left, data);
        else 
            root->right = insere(root->right, data);
    }
}

void preOrder(Node *root) {
    if(!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if(!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void posOrder(Node *root) {
    if(!root)
        return;

    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int n, v;
    Node *root = nullptr;

    cin >> n;

    root = insere(root, 10);
    insere(root, 8);
    insere(root, 6);
    insere(root, 9);
    insere(root, 20);
    insere(root, 18);

    preOrder(root);
    cout << endl;
    //root->printLevelOrder(root, 1);

    return 0;
}