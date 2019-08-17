#include <bits/stdc++.h>
using namespace std;

int mincoin(int coins[],int v,int n)
{
    if(v==0)
        return 0;
    int res=INT_MAX;
     
    for(int i=0;i<n; i++)
    {
        if(coins[i]<=v)
        {
            int new_res=mincoin(coins,v-coins[i],n);
            if(new_res!=INT_MAX  && new_res+1<res)
             res=new_res+1;
        }

    }
return res;

}

int main()
{
    int coins[]={1,2,4,5,6,9};
    cout<<mincoin(coins,13,6);
    return 0;
}