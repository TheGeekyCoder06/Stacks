#include <vector>
#include <stack>
using namespace std;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n , -1);
        
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
    }
};

// driver code
#include <iostream>
int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = sol.nextLargerElement(arr);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}