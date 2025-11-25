#include <iostream>
#include <queue>
using namespace std;
class StackUsingQueue {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main(){
    StackUsingQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.pop() << endl; // 3
    cout << st.top() << endl; // 2
    cout << st.pop() << endl; // 2
    cout << st.empty() << endl; // 0 (false)
    cout << st.pop() << endl; // 1
    cout << st.empty() << endl; // 1 (true)
    return 0;
}