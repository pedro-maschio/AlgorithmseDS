#include <bits/stdc++.h>

using namespace std;

class ListNode {
    public:
        int data;
        ListNode *next;

        ListNode(int d): data(d), next(nullptr) {}
};

ListNode * merge(ListNode *l1, ListNode *l2) {
    ListNode fake(100);
    ListNode *last = &fake;

    while(l1 != nullptr && l2 != nullptr) {
        if(l1->data <= l2->data) {
            last->next = l1;
            last = l1;
            l1 = l1->next;
        } else {
            last->next = l2;
            last = l2;
            l2 = l2->next;   
        }
    }
    if(l1 != nullptr) {
        last->next = l1;
    }
    if(l2 != nullptr)
        last->next = l2;
        
    return fake.next;
}

ListNode* create(int data) {
    return new ListNode(data);
}

ListNode* insere(ListNode *head, int data) {
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

void exibeLista(ListNode *head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, v;
    ListNode *head = nullptr;

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