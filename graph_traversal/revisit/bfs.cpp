#include <bits/stdc++.h>
using namespace std;

vector<int>adjlist[10];
bool visited[10];
int label[10];


void bfs(vector<int>adjlist[],int start)
{
    queue<int>q;
    q.push(start);
    label[start]=0;
    visited[start]=1;
    while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int i=0;i<adjlist[v].size();i++)
            {
                if(visited[adjlist[v][i]]==0)
                 {
                    q.push(adjlist[v][i]);
                    visited[adjlist[v][i]]=1;
                    label[adjlist[v][i]]=label[v]+1;
                 }
            }
        }
}

int main()
{
    int nodes,edges,x,y;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adjlist[x].push_back(y);
    }

    for(int i=1;i<=nodes; i++)
        visited[i]=0;
    bfs(adjlist,1);
    for(int i=1; i<=nodes; i++) 
    {
    //cout<<visited[i];
    cout<<label[i];
    }

return 0;

}




