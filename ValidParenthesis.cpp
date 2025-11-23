#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    bool isBalanced(string& s) { // TC: O(N), SC: O(N)
        // code here
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }

                if ((st.top() == '(' && ch == ')') ||
                    (st.top() == '{' && ch == '}') ||
                    (st.top() == '[' && ch == ']')) {
                    st.pop(); 
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
    bool isBalancedOptimized(string& s) { // TC: O(N), SC: O(1)
    
    // stack top index in string
    int top = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            
            // push opening bracket
            s[++top] = s[i]; 
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            
            // no opening bracket
            if (top == -1) return false; 
            if ((s[i] == ')' && s[top] != '(') ||
                (s[i] == '}' && s[top] != '{') ||
                (s[i] == ']' && s[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    
    // balanced if stack empty
    return top == -1; 
}
};



// { Driver Code Starts
#include <iostream>
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        if (obj.isBalanced(s))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
    return 0;
}  // } Driver Code Ends    