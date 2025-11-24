#include<iostream>
#include<stack>
using namespace std;

class Stack{
    stack<int> s;
    stack<int> minS;
    public:
    void push(int x){
        s.push(x);
        if(minS.empty() || x <= minS.top()){
            minS.push(x);
        }
    }
    int pop(){
        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int top = s.top();
        s.pop();
        if(top == minS.top()){
            minS.pop();
        }
        return top;
    }
    int getMin(){
        if(minS.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return minS.top();
    }
    bool isEmpty(){
        return s.empty();
    }
    bool isFull(){
        return false; // Stack is never full in this implementation
    }
};

int main(){
    Stack st;
    st.push(3);
    st.push(5);
    cout<<"Current Min: "<<st.getMin()<<endl; // 3
    st.push(2);
    st.push(1);
    cout<<"Current Min: "<<st.getMin()<<endl; // 1
    st.pop();
    cout<<"Current Min: "<<st.getMin()<<endl; // 2
    st.pop();
    cout<<"Top Element: "<<st.pop()<<endl; // 5
    cout<<"Current Min: "<<st.getMin()<<endl; // 3
    return 0;
}