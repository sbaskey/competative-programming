#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& candidates, int target, int index, vector<int>& nums, vector<vector<int>>& res) {
    if (target < 0)
        return;
    if (target == 0) {
        res.push_back(nums);
        return;
    }
    for (int i=index; i<candidates.size(); i++) {
        if (i>index && candidates[i] == candidates[i-1])
            continue;
        nums.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i+1, nums, res);
        nums.pop_back();
    }
}
vector<vector<int>> combination(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> nums;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, nums, res);
    return res;
}

int main()
{
    vector<int>candidate={1,2,3,7,0};
    vector<vector<int>>res=combination(candidate,8);
    cout<<res.size()<<endl;

    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}

