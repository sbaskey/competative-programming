#include <bits/stdc++.h>
using namespace std;
 
#define maxx 10000
int nodes,edges,x,y;
int vis[maxx];
stack<int>st;

void toplogy(vector<int>adj[],int vis[],int s)
{
    vis[s]=1;
    for(int i=0; i<adj[s].size(); i++)
    {
        int v=adj[s][i];
        if(vis[v]==0)
        toplogy(adj,vis,v);
    }
    st.push(s);

}


int main()
{
    cin>>nodes>>edges;
    vector<int>adj[nodes];
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        
    }

    for(int i=0; i<maxx; i++)
        vis[i]=0;

    toplogy(adj,vis,0);
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}