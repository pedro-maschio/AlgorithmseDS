#include <bits/stdc++.h>

#define ll long long
#define EPS (ll)1e-9
#define N (ll)(2*1e5)
#define M (ll)(1e9+7)

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->val = val;
    node->right = NULL;
    node->left = NULL;
    node->height = 1;

    return node;
}

int height(Node *root) {
    if(root == NULL)
        return 0;
    return root->height;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *root) {
    if(root == NULL) 
        return 0;
    else 
        return (height(root->left) - height(root->right));
}

Node* insert(Node *root, int val) {
    if(root == NULL) 
        return newNode(val);

    if(root->val < val)
        root->right = insert(root->right, val);
    else if(root->val > val)
        root->left = insert(root->left, val);
    else 
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left case
    if(balance > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    // right right case
    if(balance < -1 && val > root->right->val)
        return leftRotate(root);
    // left right case
    if(balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left case
    if(balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

bool busca(Node *root, int val) {
    if(root == NULL)    
        return false;
    else if(root->val == val)
        return true;
    else if(root->val > val)
        busca(root->left, val);
    else 
        busca(root->right, val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));

    

    return 0;
}
