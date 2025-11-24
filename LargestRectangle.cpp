#include<iostream>
#include<stack>
#include<limits.h>
#include<string>
using namespace std;

int LargestRectangleArea(vector<int>& heights){
    stack<int> st;
    heights.push_back(0); // Sentinel
    int maxArea = 0;
    for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << LargestRectangleArea(heights) << endl; // Output: 10
    return 0;
}