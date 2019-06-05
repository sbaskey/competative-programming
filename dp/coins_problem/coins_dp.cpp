#include <iostream>
using namespace std;

int count_ways(int s[],int v,int m)
{
    int table[v+1][m];
    for (int i=0; i<m; i++)
    table[0][i]=1;

    for (int i=1; i<v+1; i++)
    {
        for(int j=0; j<m; j++)
        {
            int use_j=(i-s[j]>=0)? table[i-s[j]][j]:0;

            int not_j=(j>=1)?table[i][j-1]:0;

            table[i][j]=use_j + not_j;
        }
    }
return table[v][m-1];
}

int main()
{
    int s[]={1,2,5};
    int v=5;
    int m=3;
    cout<<count_ways(s,v,m)<<endl;
}
