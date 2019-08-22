//creates and prints a adjacency list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes,edges,x,y;
    vector<int>adjlist[10];
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adjlist[x].push_back(y);
    }

    for(int i=1; i<=nodes; i++)
    {
        for(int j=0; j<adjlist[i].size(); j++)
            cout<<adjlist[i][j];
        cout<<endl;
    }
    

}
