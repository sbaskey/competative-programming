
#include <iostream>
using namespace std;

int count_coin(int s[],int v,int m)
{
    if (v==0)
    return 1;

    if(v<0)
    return 0;

    if(m<=0 && v>=1)
        return 0;
    return count_coin(s,v,m-1) + count_coin(s,v-s[m-1],m); 
}

int main()
{
    int coins[]={1,2,3};
    cout<<count_coin(coins,4,3)<<endl;

    return 0;

}