#include <bits/stdc++.h>
using namespace std;

int napsack(vector<int>val,vector<int>wt,int W,int n)
{
    int table[n+1][W+1];
    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(w==0|| i==0)
                table[i][w]=0;
            else if(wt[i-1]<=w)
             table[i][w]=max(val[i-1]+ table[i-1][w-wt[i-1]],table[i-1][w]);
            else
             table[i][w]=table[i-1][w];
             
        }
    }
return table[n][W];
}

int main()
{
    vector<int>val={1,4,5,7};
    vector<int>wt={1,3,4,5};
    cout<<napsack(val,wt,7,4);
}