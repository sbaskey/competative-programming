#include <iostream>
#include <vector>
using namespace std;

#define n 10
int t=0;

vector <int> adj[n];
vector<int>stacck;
bool active[10];
int start[10];
int endd[10];
int parent[10];


void intitialize()
{
    for (int i=0; i<n; i++)
    {
        active[i]=false;
        start[i]=endd[i]=-1;
        active[i]=0;
    }
        
}

void dfs1(int s)
{
    t++;
    start[s]=t;
    
    active[s]=true;//assume it as active
    
    for(int i=0; i<adj[s].size(); i++)
    {
        if(start[adj[s][i]]==-1)
            {
            parent[adj[s][i]]=s;
            cout<<s<<"-->"<<adj[s][i]<<" is tree edge"<<endl;
            dfs1(adj[s][i]);
            }

        else if(start[adj[s][i]]>start[s])
            cout<<s<<"-->"<<adj[s][i]<<" is forward edge"<<endl;

        else if(active[adj[s][i]]==false)
            cout<<s<<"-->"<<adj[s][i]<<" is cross edge"<<endl;

        else 
            cout<<s<<"-->"<<adj[s][i]<<" is back edge"<<endl;
    }
    active[s]=false;
    t++;
    endd[s]=t;
    stacck.push_back(s);
    cout<<s<<" ";
    
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
        //adj[y].push_back(x);
    }

    intitialize();

    for(int i=0; i<nodes; i++)
        {
            if(start[i]==-1)
            {
                dfs1(i);
                connected_component++;
            }
        }

    cout<<"connected_component"<<connected_component<<endl;

    cout<<"start"<<" "<<"end"<<endl;

    for(int i=0; i<nodes; i++)
    {
        cout<<start[i]<<" "<<endd[i]<<endl;
    }

    for(auto i=stacck.begin(); i!=stacck.end(); i++)
    {
        cout<<stacck[*i]<<" ";
    }

    cout<<endl;

return 0;

    
}
