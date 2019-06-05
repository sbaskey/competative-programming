#include <iostream>
using namespace std;
#define maxx 10000

int min_coin(int coins[],int m,int v)
{
    int table[v+1];
    table[0]=0;
    for(int i=1; i<v+1; i++)
        table[i]=maxx;

    for(int i=1; i<v+1; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(coins[j]<=i)
                {
                    int res=table[i-coins[j]];
                    if(res!=maxx && res + 1< table[i])
                    table[i]=res+ 1;
                }
            }
        }
    return table[v];
}


int main() 
{ 
    int coins[] =  {9, 6, 5, 1}; 
    int m = sizeof(coins)/sizeof(coins[0]); 
    int V = 11; 
    cout << "Minimum coins required is "
         << min_coin(coins, m, V); 
         
    return 0; 
} 