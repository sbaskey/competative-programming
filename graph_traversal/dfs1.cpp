#include <iostream>
#include <vector>
using namespace std;

#define n 10

vector <int> adj[n];
bool visited[10];

void intitialize()
{
    for (int i=0; i<n; i++)
        visited[i]=false;
}

void dfs1(int s)
{
    visited[s]=true;
    for(int i=0; i<adj[s].size(); i++)
    {
        if(visited[adj[s][i]]==false)
            dfs1(adj[s][i]);
    }
}

int main()
{
    int nodes,edges,x,y,connected_component=0;
    cin>>nodes;
    cin>>edges;
    for(int i=0;i<edges; i++)
    {

        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    intitialize();

    for(int i=0; i<nodes; i++)
        {
            if(visited[i]==false)
            {
                dfs1(i);
                connected_component++;
            }
        }

    cout<<"connected_component"<<connected_component<<endl;

return 0;

    
}

