#include <bits/stdc++.h>
using namespace std;

int napsack(vector<int> val,vector<int>w,int W,int n)
{
    if(n==0||W==0) return 0;
    if(w[n-1]>W) return napsack(val,w,W,n-1);
    else return max((val[n-1]+ napsack(val,w,W-w[n-1],n-1)),napsack(val,w,W,n-1));
}

int main()
{
    vector<int>val={60,100,120};
    vector<int>w={10,20,30};
    int W=50;
    int n=3;
    cout<<napsack(val,w,W,n);
}