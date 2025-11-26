#include<iostream>
#include<stack>
#include<climits>
using namespace std;
class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val){
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                long long encodedVal = 2LL * val - mini;
                st.push(encodedVal);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    void pop(){
        if(st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if(topVal < mini){
            mini = 2LL * mini - topVal;
        }
    }
    int top(){
        if(st.empty()) return -1;

        long long topVal = st.top();
        if(topVal < mini){
            return mini;
        }
        else{
            return topVal;
        }
    }
    int getMin(){
        if(st.empty()) return -1;
        return mini;
    }
};

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;        // Returns 0
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -2
    return 0;
}