#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        stack<int> st;
        int n = mat[0].size();
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (mat[a][b] == 1)
                st.push(b);
            else
                st.push(a);
        }

        int cand = st.top();

        for (int j = 0; j < n; j++)
        {
            if (j != cand && mat[cand][j] == 1)
                return -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (i != cand && mat[i][cand] == 0)
                return -1;
        }

        return cand;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{0, 0, 1},
                               {1, 0, 1},
                               {0, 0, 0}};
    int celeb = sol.celebrity(mat);
    cout << "The celebrity is at index: " << celeb << endl;
    return 0;
}