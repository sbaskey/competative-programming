#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>graph;
//vector<pair<int,int>>graph[20];
vector<int>dis;

void dfs(int s)
{
    deque<int>q;
    dis[s]=0;
    q.push_back(s);
    while (!q.empty())
    {
        int val=q.front();
        q.pop_front();
        for(int i=0; i<graph[val].size(); i++)
        {
           int node=graph[val][i].first;
           if(dis[node]>dis[val]+graph[val][i].second)
            {
                dis[node]=graph[val][i].second + dis[val];
                if(dis[node]==0) q.push_front(node);
                 else 
                 q.push_back(node);
            }
        }


    }
    
}

int main()
{
    int nodes,edges,x,y,d;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y>>d;
        //cout<<x<<y<<d;
        graph.emplace_back();
        graph[x].push_back(make_pair(y,d));
    }
    for(int i=0; i<nodes; i++) 
    dis.push_back(INT_MAX);
    dfs(0);
    for(int i=0; i<nodes; i++) 
         cout<<dis[i]<<" ";
    cout<<endl;

    return 0;
}

