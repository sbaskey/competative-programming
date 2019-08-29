
#include <bits/stdc++.h>
using namespace std;
const int k=1000;
const int  w=1000;
bool dfs(int mat[][w],int visited[][w],int i,int j,int m,int n)
{
    if(i==n-1 and j==m-1)
     return true;
     
     if(i>n-1 || j>m-1)
      return false;
      
      if(i<0 ||j<0)
       return false;
       if(mat[i][j]==0)
        return false;
        if(visited[i][j]==1)
         return false;
        
        visited[i][j]=1;
       
       if(dfs(mat,visited,i,j+1,m,n)==true) return true;
       if(dfs(mat,visited,i+1,j,m,n)==true)return true;
       if(dfs(mat,visited,i,j-1,m,n)==true) return true;
       if(dfs(mat,visited,i-1,j,m,n)==true)return true;
       
       return false;
       
}

int main() {
	int n,m;
	cin>>n>>m;	
	int mat[k][w];
	int visited[k][w];
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<m; j++){
	    cin>>mat[i][j];
	    visited[i][j]=0;
	    }
	}
	
	if(dfs(mat,visited,1,1,m,n)==1) cout<<"Yes";
	else cout<<"No";
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
         cout<<mat[i][j];
         cout<<"\n";
    }*/
	return 0;
			
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
