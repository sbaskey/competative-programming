#include <bits/stdc++.h>
using namespace std;
#define r 5
#define c 5

bool issafe(int m[r][c],int i,int j,int visited[r][c])
{
    return (i>=0) && (i<=r) && (j>=0) && (j<=c) && (m[r][c] && !visited[i][j]);
}

void bfs(int m[r][c],int visited[r][c],int i,int j)
{
    int row[]={1,1,1,0,0,-1,-1,-1};
    int col[]={1,0,-1,1,-1,-1,1,0};
    queue<pair<int,int>>q;
    q.push(make_pair(i,j));
    visited[i][j]=1;

    while (!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0; k<8; k++)
        {
            if(issafe(m,i+row[k],j+col[k],visited))
            {
                visited[i+row[k]][j+col[k]]=1;
                q.push(make_pair(i+row[k],j+col[k]));
            }
        }

    }

}

int main()
{
    int mat[r][c] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 

    bool visited[r][c];
    memset(visited,0,sizeof(visited));
    int res=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mat[i][j] && !visited[i][j])
             {
                 bfs(mat,visited,i,j);
                 res++;
             }
        }
    }
return 0;
}
