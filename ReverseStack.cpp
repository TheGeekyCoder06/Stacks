#include<stack>
#include<iostream>
using namespace std;

void insertAtBottom(stack<int>& s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s , element);
    s.push(topElement);
}

void reverseStack(stack<int>& s){
    if(s.empty()) return;

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s , topElement);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
