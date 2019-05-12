#include <iostream>
#include <cstring>
using namespace std;

#define nil -1
#define MAX  10000

int look_up[MAX];

int fib(int n)
{
    if(n==0|n==1)
    {
        look_up[n]=n;
        return look_up[n];
    }

    if (look_up[n]!=nil)
            return look_up[n];

    else
    {
        look_up[n]=fib(n-1) + fib(n-2);
        return look_up[n];
    }
    
}

int bottom_up(int n)
{
    int f[n+1];
    f[0]=0; f[1]=1;
    for(int i=2; i<=n; i++)
    {
        f[i]=f[i-1] + f[i-2];
    }

    return f[n];
}

//optimal way
int fib_opt(int n)
{
    int a=0;
    int b=1;
    int c;
    for(int i=2; i<=n; i++){
        c=a+b;
        a=b;
        b=c;}
    return c;
}

int main()
{
    for(int i=0; i<MAX; i++)
    look_up[i]=nil;
    cout<<fib(5)<<endl;

    cout<<bottom_up(5)<<endl;

    cout<<fib_opt(5)<<endl;
    
    return 0;
}
