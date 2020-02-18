// code for this interesting problem: https://www.hackerrank.com/challenges/maximum-element/problem
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long 

#define capacity 100000

class Stack {
    int data[capacity];

    public:
        int top;
        void push(int x);
        int pop();
        int maximum();
};

void Stack::push(int x) {

    data[++top] = x;

}
int Stack::pop() {
    return data[top--];
}

int Stack::maximum() {
    int i =0, max = 0;

    for(i = 0; i < top+1; i++)
        if(data[i] > max) {
            max = data[i];
        }
    return max;
}

int main() {
    Stack pilha;
    pilha.top = -1;
    int n, type, x, maximum = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            pilha.push(x);
            maximum = max(maximum, x);
        } else if(type == 2) {
            pilha.pop();
            maximum = pilha.maximum();
        } else {
            cout << maximum << endl;
        }
    }

    return 0;
}