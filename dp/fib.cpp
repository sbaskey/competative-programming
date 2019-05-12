#include <iostream>
#include <cstring>

using namespace std;

int fib(int n)
{
    if(n==1|n==0)
    return n;

    return fib(n-1) + fib(n-2);
}

//topdown approach
//dp + recurssion +memotization

int topdown(int n,int *dp)
{
  if(n==0|n==1)
  {
    dp[n]=n;
    return n;
  }

  if(dp[n]!=-1)
    return dp[n];

else
{
    dp[n]=topdown(n-1,dp)+ topdown(n-2,dp);
    return dp[n];
}


}


int main()
{
    cout<<fib(5) <<endl;

    int dp[1000];
    for(int i=0; i<1000; i++)
        dp[i]=-1;
    cout<<topdown(5,dp)<<endl;



    return 0;
}