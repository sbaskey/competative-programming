#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s={1,2,3};
    int n=pow(2,s.size());
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i&(1<<j))
                cout<<s[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}