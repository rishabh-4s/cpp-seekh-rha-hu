#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    stack<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.size() << endl;
    cout << q.empty() << endl;

    while (!q.empty())
    {
        cout<< q.top() << endl;
        q.pop();
    }
    
    
}
