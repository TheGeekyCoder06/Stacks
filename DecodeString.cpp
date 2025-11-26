#include<iostream>
#include<stack>
using namespace std;

string decodeString(string s){
    stack<int> countStack;
    stack<string> stringStack;
    string currString = "";
    
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            int count = 0;
            while(i < s.length() && isdigit(s[i])){
                count = count * 10 + (s[i] - '0');
                i++;
            }
            i--;
            countStack.push(count);
        }
        else if(s[i] == '['){
            stringStack.push(currString);
            currString = "";
        }
        else if(s[i] == ']'){
            string temp = currString;
            currString = stringStack.top();
            stringStack.pop();
            int count = countStack.top();
            countStack.pop();
            while(count--){
                currString += temp;
            }
        }
        else{  // handle normal characters
            currString += s[i];
        }
    }
    return currString;
}

int main(){
    string s ;
    cin >> s; // optional input
    string decodedString = decodeString(s);
    cout << "Decoded string: " << decodedString << endl;
    return 0;
}
