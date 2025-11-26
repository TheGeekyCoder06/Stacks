#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int element)
{
    if (s.empty() || s.top() <= element)
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(top);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int top = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, top);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(2);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}