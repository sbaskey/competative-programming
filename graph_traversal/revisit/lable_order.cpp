#include <bits/stdc++.h>
using namespace std;
#define maxx 100000
vector<int>adjlist[maxx];
bool visited[maxx];
vector<int>label[maxx];
int l=0;


void bfs(vector<int>adjlist[],int start)
{
    queue<int>q;
    q.push(start);
    label[l].push_back(start);
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
                    //label[adjlist[v][i]]=label[v]+1;
                    label[l].push_back(adjlist[v][i]);
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
    /*for(int i=0; i<l; i++) 
    {
      for(int j=0; j<label[i].size(); i++)
       cout<<label[i][j];
      cout<<endl;
    }*/
    cout<<l;

return 0;

}




