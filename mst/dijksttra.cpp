#include <bits/stdc++.h>
using namespace std;
const int INF=1000000000;
vector<pair<int,int>>adj[1000];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

void addEdge(int s,int des,int d)
{
   adj[s].push_back(make_pair(des,d));
   adj[des].push_back(make_pair(s,d));
}

void dijkstra(int s,vector<int>d,vector<int>p)
{
   //int n=adj.size();
   //int n=1000;
   int n=9;
   d.assign(n,INF);
   p.assign(n,-1);
   q.push(make_pair(0,s));
   vector<bool>vis(n,false);
    while(!q.empty())
       {
           //int dist=q.top().first;
         int v=q.top().second;
         q.pop();
        
           for(int i=0; i<adj[v].size(); i++)
           {
               if(d[v] + adj[v][i].second<d[adj[v][i].first])
               {
                 d[adj[v][i].first]=d[v] + adj[v][i].second;
                 p[adj[v][i].first]=v;
                 q.push(make_pair(d[adj[v][i].first],adj[v][i].first));
               }
           }
       }

    for(int i=0; i<n; i++)
    {
        cout<<"i\t"<<d[i];
    }




}


int main()
{
    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 
    vector<int>d;
    vector<int>p;
    dijkstra(0,d,p);
    
    
   
    return 0;
}

