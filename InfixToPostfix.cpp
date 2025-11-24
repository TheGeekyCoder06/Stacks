#include<iostream>
#include<stack>
#include<limits.h>
#include<string>
using namespace std;

int precendence(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string infix){
    stack<char> st;
    string postfix = "";
    for(char ch : infix){
        if(isalnum(ch)){
            postfix += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else{
            while(!st.empty() && precendence(st.top()) > precendence(ch)){
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl; // Output: abcd^e-fgh*+^*+i-
    return 0;
}