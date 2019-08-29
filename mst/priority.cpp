#include <bits/stdc++.h>
using namespace std;
int main()
{
    //minheap with extra argument
    //max without extra argument
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(-2);
    q.push(0);
    q.push(3);
    //cout<<q.size();
    while (!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
    
}
