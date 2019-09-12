#include <bits/stdc++.h>
using namespace std;

/*void dfs(vector<int> & candidate,vector<vector<int>>& res,vector<int>& set,int pos,int sum,int target)
{
    if(sum>=target)
        if(sum==target)
            res.push_back(set);
        return;
    for(int i=pos; i<candidate.size(); i++)
    {
        if(i!=pos && candidate[i]==candidate[i-1]) continue;
         set.push_back(candidate[i]);
         dfs(candidate,res,set,i+1,sum+candidate[i],target);
         set.pop_back();
    }
}
vector<vector<int>> combination(vector<int> & candidate,int target)
{
    sort(candidate.begin(),candidate.end());
    vector<vector<int>>res;
    vector<int>set;
    dfs(candidate,res,set,0,0,target);
    return res;
    
}*/
void recursion(int k, vector<int>& candidates, int target, vector<int>&combination, vector<vector<int>>& combinations) {
    if (target < 0) {
        return;
    }
    
    if(target == 0) {
        combinations.push_back(combination);
        return;
    }
    
    for(int i = k; i < candidates.size(); i++) {
        if (i != k && (candidates[i] == candidates[i - 1])) continue;
        
        combination.push_back(candidates[i]);
        recursion(i + 1, candidates, target - candidates[i], combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combination(vector<int>& candidates, int target) {
vector<int>combination;
vector<vector<int>>combinations;
int sum = 0;
sort(candidates.begin(), candidates.end());
recursion(0, candidates, target, combination, combinations);
return combinations;
}

int main()
{

    vector<int>candidate={1,2,3,5,4};
    vector<vector<int>>ans=combination(candidate,6);
    cout<<ans.size();
    for(int i=0; i<ans.size(); i++)
    {
        for (int j=0; ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }

}


