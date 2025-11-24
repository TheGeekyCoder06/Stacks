#include<iostream>
#include<stack>
#include<limits.h>
#include<string>
using namespace std;    

string removeDuplicates(string s){
    stack<char> st;
    for(char ch : s){
        if(!st.empty() && st.top() == ch){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    string result = "";
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main(){
    string s = "abbaca";
    cout << "Result after removing duplicates: " << removeDuplicates(s) << endl; // Output: "ca"
    return 0;
}