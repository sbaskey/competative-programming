#include <bits/stdc++.h>
using namespace std;
typedef struct int_point
{
 int x;
 int y;
}point;

int gcd(int a,int b)
{
    if(b==0)
     return a;
    else
    return gcd(b,a%b);
}

int points_on_line(point p,point q)
{
     if(p.x==q.x)
     return abs(p.y-q.y)-1;

     if(p.y==q.y)
      return abs(p.x-q.x)-1;
    else
        return gcd(abs(p.x-q.x),abs(p.y-q.y))-1; 
}

int area(point p,point q,point r)
{
    //2*area
    return abs(p.x*(q.y-r.y) + q.x*(r.y-p.y) + r.x*(p.y-q.y)); 
}

int main()
{
    point p,q,r;
    p.x=0;
    p.y=0;
    q.x=5;
    q.y=0;
    r.x=0;
    r.y=5;
    int a=area(p,q,r);

    int b_point=points_on_line(p,q) +points_on_line(q,r) + points_on_line(r,p)+3;
    cout<<(a-b_point+2)/2<<endl;
}





