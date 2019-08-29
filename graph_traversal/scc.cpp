#include <bits/stdc++.h>
using namespace std;
#define maxx 1000
int nodes,edges,x,y;
vector<int>adj[maxx];
vector<int>rev_adj[maxx];
int vis[maxx];
stack<int>s;


void dfs(vector<int> adjs[],int vis[],int u)
{
    vis[u]=1;
    for(int i=0; i<adjs[u].size(); i++)
    {
        int v=adjs[u][i];
        if(vis[v]==0)
         dfs(adjs,vis,v);
    }
    s.push(u);

}

int main()
{
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }
    for(int i=0; i<nodes; i++)
        vis[i]=0;
    dfs(adj,vis,0);
    int scc=0;
    for(int i=0; i<nodes; i++)
        vis[i]=0;
    while(!s.empty())
    {
        int u=s.top();
        if(vis[u]==0)
            {
                dfs(rev_adj,vis,u);
                scc++;

            }
        s.pop();
    }
 cout<<scc;

    return 0;
       
}