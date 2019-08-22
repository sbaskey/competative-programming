#include <bits/stdc++.h>
using namespace std;

int cross(vector<int>v1,vector<int>v2)
{
    int product=0;
    for(int i=0; i<v1.size(); i++)
    {
        product+=v1[i]*v2[i];
    }
    return product;
}
int main()
{
    vector<int>v1={1,2};
    vector<int>v2={3,4};
    cout<<cross(v1,v2);

}