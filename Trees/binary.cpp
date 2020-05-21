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

// Iterative solution
vector<int> preorderTraversal(Node* root) {
    vector<int> resultado;
    list<Node *> fila;
    if(root) {
        fila.push_front(root);
        while(!fila.empty()) {
            Node *no = fila.front();
            fila.pop_front();
            resultado.push_back(no->data);

            /* We first add the right node, since we are piling, in the
            end, the left node will be the first to be pushed back in the result
            */
            if(no->right != nullptr)
                fila.push_front(no->right);
            if(no->left != nullptr)
                fila.push_front(no->left);


        }
    } 
    return resultado;
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

    vector<int> res = preorderTraversal(head);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}