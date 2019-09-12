#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int>&candidates,vector<int> &temp,vector<vector<int>> &res,int idx)
{
    if(idx=candidates.size())
        res.push_back(temp);
    temp.push_back(candidates[idx]);
    dfs(candidates,temp,res,idx+1);
    temp.pop_back();
    dfs(candidates,temp,res,idx+1);

}
vector<vector<int>> sets(vector<int>&candidates)
{
    vector<vector<int>>res;
    vector<int>temp;
    dfs(candidates,temp,res,0);

    return res;

}

int main()
{
    vector<int>candidates={1,2,3};
    vector<vector<int>>res=sets(candidates);

    for(int i=0; i<res.size(); i++)
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
}