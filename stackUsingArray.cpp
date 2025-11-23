#include <iostream>
#include<vector>
using namespace std;
// Stack using Array Implementation
class Stack{
    vector<int> arr;
    int top;
    int capacity;
    public:
    Stack(int size){
        arr.resize(size);
        capacity = size;
        top = -1;
    }

    void push(int x){
        if(top == capacity - 1){
            cout<< "Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }

    int pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        // cout << arr[top] << endl;
        return arr[top--];
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == capacity -1;
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};
int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    return 0;
}