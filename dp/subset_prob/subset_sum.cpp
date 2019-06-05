#include <iostream>
using namespace std;

bool issubset(int set[],int n,int sum)
{
    if (sum==0)
    return true;

    if (sum!=0 && n==0)
    return false;

    if(set[n-1]>sum)
    return issubset(set,n-1,sum);


    return issubset(set,n-1,sum) || issubset(set,n-1,sum-set[n-1]);
}

int main()
{
    int set[]={1,2,3,4,5,6,10};
    cout<<issubset(set,7,-1)<<endl;
    return 0;
}