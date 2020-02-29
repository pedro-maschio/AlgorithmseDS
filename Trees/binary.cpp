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
};

Node *criaNo(int data) {
    Node *no = new Node(data);

    return no;
}

Node* insere(Node *head, int data) {
    if(!head) {
        return criaNo(data);
    } else {
        if(data < head->data)
            head->left = insere(head->left, data);
        else 
            head->right = insere(head->right, data);
    }
}

void preOrder(Node *head) {
    if(!head)
        return;

    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void inOrder(Node *head) {
    if(!head)
        return;

    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

void posOrder(Node *head) {
    if(!head)
        return;

    posOrder(head->left);
    posOrder(head->right);
    cout << head->data << " ";
}

int main() {
    int n, v;
    Node *head = nullptr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v;
        if(i == 0)
            head = insere(head, v);
        else 
            insere(head, v);
    }
    preOrder(head);
    cout << endl;
    inOrder(head);
    cout << endl;
    posOrder(head);


    return 0;
}