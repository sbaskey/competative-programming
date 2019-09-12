#include <bits/stdc++.h>
using namespace std;

bool anargram(string s1,string s2)

{
    if(s1.length()!=s2.length()) return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]!=s2[i]) return false;
    }

    return true;
}
bool anargram1(string s1,string s2)
{
    int val=0;
    if(s1.length()!=s2.length()) return false;

    for(int i=0; i<s1.size(); i++)
    {
        val=val^(int)s1[i];
        val=val^(int)s2[i];
    }

    return val;
}

int main()
{
    cout<<anargram1("abc","bca");
    return 0;

}