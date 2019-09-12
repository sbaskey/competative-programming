#include <bits/stdc++.h>
using namespace std;
#define n 4
#define m 3
int colour[n];

bool issafe(int graph[n][n],int colour[],int c,int v)
{
    for(int i=0; i<n; i++)
        if(graph[v][i] && c==colour[i])
            return false;

        return true;
}

bool graph_colour(int graph[n][n],int colour[],int v)
{
    if(v==n) return true;
    for(int c=1; c<=m; c++)
    {
        if(issafe(graph,colour,c,v))
            {
               colour[v]=c;
               if(graph_colour(graph,colour,v+1))
                return true;

              colour[v]=0;
            }

        
    }
return false;

}

int main()
{
    int graph[n][n] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 

    for(int i=0; i<n; i++)
    {
        colour[i]=0;
    }
    if(graph_colour(graph,colour,0))
        cout<<"graph can be coloured"<<endl;

    return 0;


}