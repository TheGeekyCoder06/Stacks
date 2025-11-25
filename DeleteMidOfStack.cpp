#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void deleteMid(stack<int>&s , int count , int mid){
    if(count == mid){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMid(s , count + 1 , mid);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int mid = s.size() / 2;
    deleteMid(s , 0 , mid);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}