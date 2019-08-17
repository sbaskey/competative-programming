#include <bits/stdc++.h>
using namespace std;
bool issubset(int sets[],int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0 and sum!=0)
        return false;
    if(sets[n-1]>sum)
        return issubset(sets,n-1,sum);
    else
    {
       return issubset(sets,n-1,sum) || issubset(sets,n-1,sum-sets[n-1]);
    }
    
}




int main()
{
    int sets[]={1,2,3,4,5};
    int sum=10;
    int n=5;
    cout<<issubset(sets,n,sum);
}
