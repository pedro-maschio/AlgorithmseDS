#include <bits/stdc++.h>

using namespace std;

class List {
    public:
        int data;
        List *next;

        List(int d) {
            data = d;
            next = nullptr;
        }
};

List* create(int data) {
    return new List(data);
}

List* insere(List *head, int data) {
    if(!head) {
        head = create(data);
        return head;
    } else {
        while(head->next != nullptr)
            head = head->next;
        head->next = create(data);
    }
    return head;
}

void exibeLista(List *head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, v;
    List *head = nullptr;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> v;
        if(i == 0)
            head = insere(head, v);
        else
            insere(head, v);
    }
    exibeLista(head);
    
    return 0;
}