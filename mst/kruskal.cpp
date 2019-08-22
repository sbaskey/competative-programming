#include <bits/stdc++.h>
using namespace std;
const int MAXX=1e4 +5;
int id[MAXX],nodes,edges;

pair<long long,pair<int,int>> p[MAXX];

void initialize()
{
    for(int i=0; i<MAXX; i++)
        id[i]=i;
}

int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
 return x;
}

void joint(int x,int y)
{
  int p=root(x);
  int q=root(y);
  id[p]=id[q];

}

long long kruskal(pair<long long,pair<int,int>>p[])
{
    long long cost,minicost;
    for(int e=0; e<edges; e++)
    {
        int i=p[e].second.first;
        int j=p[e].second.second;
        cost=p[e].first;
        if(root(i)!=root(j))
        {
            minicost+=cost;
            joint(i,j);
        }
    }

return minicost;
}

int main()
{
   int x,y;
   long long weight;
   cin>>nodes>>edges;
   initialize();
   for(int i=0; i<edges; i++)
   {
       cin>>x>>y>>weight;
       p[i]=make_pair(weight,make_pair(x,y));
   }

   sort(p,p+edges);

   cout<<kruskal(p)<<endl;

return 0;

}