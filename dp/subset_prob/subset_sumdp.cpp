#include <bits/stdc++.h>
using namespace std;


bool issumset(int set[],int n,int sum)
{
    if(sum<0)
    return 0;
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
    dp[i][0]=1;
    
    for(int j=1; j<=sum; j++)
     dp[0][j]=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(dp[i-1][j]==true)
                dp[i][j]=true;
            
            else
            {
             if(set[i-1]>j)
              dp[i][j]=false;

            else
               dp[i][j]=dp[i-1][j-set[i-1]];
            }
            
        }
    }
return dp[n][sum];
    
}

int main()
{
    int set[]={1,2,3,4,5,6};
    int sum=-3;
    int n=6;
    cout<<issumset(set,n,sum);
    return 0;

}