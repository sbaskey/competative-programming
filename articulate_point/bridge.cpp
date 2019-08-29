#include <bits/stdc++.h>
using namespace std;
#define maxx 10000
#define inff 10000
vector<int>adj[maxx];
vector<pair<int,int>>bridge;
int dis[maxx];
int low[maxx];
int vis[maxx];
int parent[maxx];
int t=0;
int nodes,edges,x,y;
void dfs(vector<int>adj[],int u)
{   t++;
    dis[u]=low[u]=t;
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==0)
        {
            parent[v]=u;
            dfs(adj,v);
            low[u]=min(low[u],low[v]);
            if(dis[u]<low[v])
                bridge.push_back(make_pair(u,v));
        }
     else if(parent[u]!=v)
      low[u]=min(low[u],dis[v]);
    }

}

int main()
{
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<nodes; i++)
    {
        vis[i]=0;
        parent[i]=-1;

    }
    dfs(adj,0);
    for(int i=0; i<bridge.size(); i++)
    {
        cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
    }
    return 0;
}