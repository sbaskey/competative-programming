#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> colour;
vector<int> d;
vector<int> p;

void addedge(vector<int> g[],int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void bfs1(vector<int> g[],int s)
{
    queue<int> q;
    q.push(s);
    d[s]=0;
    colour[s]="green";

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto i=g[u].begin(); i!=g[u].end(); i++)
        {
            if(colour[*i]=="white")
            {
                colour[*i]="green";
                d[*i]=d[u] + 1;
                p[*i]=u;
                q.push(*i);
            }
        }

        colour[u]="dark_green";
    }
    
}

void fullbfs(vector<int> g[],int n)
{
    colour.assign(n,"white");
    d.assign(n,0);
    p.assign(n,-1);
    for (int i=0; i<n; i++)
    {
        if(colour[i]=="white")
            bfs1(g,i);

    }
}


int main()
{
     // Graph with 7 nodes and 6 edges. 
    int n = 7; 
          
    // The Graph vector 
    vector <int> g[n]; 
      
    addedge(g, 0, 1); 
    addedge(g, 0, 2); 
    addedge(g, 1, 3); 
    addedge(g, 1, 4); 
    addedge(g, 2, 5); 
    addedge(g, 2, 6); 
  
    fullbfs(g, n); 
  
    return 0;
}

