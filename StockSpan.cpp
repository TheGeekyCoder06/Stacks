#include <vector>
#include <stack>
using namespace std;
class Solution {
  public:
    vector<int> calculateSpan(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - st.top();
        }

        st.push(i);
    }

    return ans;
}

};

// driver code
#include <iostream>
int main() {
    Solution sol;
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = sol.calculateSpan(arr);    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}