#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class QueueUsingStack {
    stack<int> s1 , s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty(){
        return s1.empty() && s2.empty();
    }
};

int main() {
    
    QueueUsingStack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl; // 1
    cout << q.peek() << endl;    // 2
    cout << q.dequeue() << endl; // 2
    cout << q.isEmpty() << endl; // 0 (false)
    cout << q.dequeue() << endl; // 3
    cout << q.isEmpty() << endl; // 1 (true)
    
    return 0;
}