#include <bits/stdc++.h>
using namespace std;
#define maxx 10000
#define nil -1
#define inff 1000
vector<int>adj[maxx];
int t=0;
int nodes,edges,x,y;
int dis[maxx];
int p[maxx];
int ap[maxx];
int low[maxx];
int vis[maxx];

void dfs(vector<int>adj[],int dis[],int low[],int vis[],int p[],int ap[],int s)
{

    t++;
    dis[s]=t;
    low[s]=t;
    vis[s]=1;
    int child=0;
    //cout<<low[0];
    for(int i=0; i<adj[s].size(); i++)
        {
            int v=adj[s][i];
            if(vis[v]==0)
            {
            child++;
            p[v]=s;
            dfs(adj,dis,low,vis,p,ap,v);
            
            low[s]=min(low[s],low[v]);
            if(p[s]==nil && child>1)
                ap[s]=1;
            if(p[s]!=nil && dis[s]<=low[v])
                ap[s]=1;  
           }
        else if(v!=p[s])
            low[s]=min(low[s],dis[v]);   
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
     p[i]=nil;
     ap[i]=0;
     vis[i]=0;
     
     //low[i]=-inff;
     //dis[i]=inff;
 }
 
 /*for(int i=0; i<nodes; i++)
 {
     cout<<adj[i].size()<<endl;
     for(int j=0; j<adj[i].size(); j++)
     {
         cout<<adj[i][j];
     }
    //cout<<adj[i][j];
     //cout<<endl;
     //cout<<1;
 }*/
 int s=1;
 dfs(adj,dis,low,vis,p,ap,s);

 //cout<<t;
for(int i=0; i<nodes; i++)
    cout<<ap[i];

//cout<<low[0];

 return 0;
 
}
