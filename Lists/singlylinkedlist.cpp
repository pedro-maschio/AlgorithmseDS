#include <bits/stdc++.h>

using namespace std;


struct SingleNode {
    int val;
    struct SingleNode* next;
    SingleNode(int x) : val(x),next(nullptr){}
};
class MyLinkedList {
public:
    
    SingleNode *head,*tail;
    int size;
    
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    
    int get(int index) {
        
        auto temp = head;
        
        while(temp != nullptr && index > 0) {
            temp = temp->next;
            index--;
        }
        
        if (temp)
            return temp->val;
        
        return -1;
    }
    
   
    void addAtHead(int val) {
        
        if(size == 0){ // first element logic
            head = tail = new SingleNode(val);
            size++;
            return;
        }
        
        auto newNode = new SingleNode(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }
    

    void addAtTail(int val) {
        
        if(size == 0){
            head = tail = new SingleNode(val);
            size++;
            return;
        }
        
        auto newNode = new SingleNode(val);
        tail -> next = newNode;
        tail = newNode;
        size++;
    }
   
    void addAtIndex(int index, int val) {
        // if adding at begin/end use pre exist methods
        if(index == 0 or index == size) {
            if(index==0)
                addAtHead(val);
            else
                addAtTail(val);
            return;
        }
        
        auto temp = head;
        while(temp != nullptr && index > 1) {
            temp = temp->next;
            index--;
        }
        
        auto newNode = new SingleNode(val);

        newNode->next =temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        
        bool tailChanged = (index == size-1);
        
        if(index == 0) {
            size--;
            auto temp = head;
            head = head -> next;
            delete temp;
            
            if (size == 0)
                tail = head; // last element logic
            
            return;
        }
        
        
        auto temp = head;
        while(temp != nullptr && index > 1) {
            temp = temp->next;
            index--;
        }
        
        auto curr = temp->next;
        temp->next = curr ? curr->next : nullptr;
        size--;
        delete curr;
        
        if(tailChanged)
            tail = temp;
    }
    
    int length(){
        return size;
    }

    bool hasCycle() {
        SingleNode *slow = head;
        SingleNode *fast = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                return true;

        }
        return false;
    }
};

int main() {
    return 0;
}