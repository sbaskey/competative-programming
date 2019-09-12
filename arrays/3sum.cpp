#include <bits/stdc++.h>
using namespace std;

/*void sum3(vector<int> v,int sum)
{
    sort(v.begin(),v.end());
    for(int i=0; i<v.size()-2; i++)
    {
        int x=v[i];
        int l=i+1;
        int r=v.size()-1;
        while(l<r)
        {
            if(x+v[l]+v[r]==sum)
                {
                    cout<<x<<" "<<v[l]<<" "<<v[r]<<endl;
                    l++;
                    r--;
                }
            else if(x+v[l]+v[r]<sum)
                l++;
            else
              r--;
        }
        

    }
}
*/
    vector<vector<int>> threeSum(vector<int>& nums,int c) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int v=0;
        for(int i=0; i<nums.size()-2; i++)
        {
            int x=nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(x+nums[l]+nums[r]==0){
                    res.push_back(vector <int>());
                    res[v].push_back(x);
                    res[v].push_back(nums[l]);
                    res[v].push_back(nums[r]);
                    v++;
                    l++;
                    r--;
                }
            
            else if (x+nums[r]+ nums[l]<0)
                l++;
            else
                r--;
            }
        }
        return res;
        
    }
int main()
{
    vector<int> v={1,2,-3,0,2,3,-7,4};
    vector<vector<int>>x=threeSum(v,0);
    for(int i=0; i<x.size(); i++)
    {
        for(int j=0; j<x[i].size(); j++)
        {
            cout<<x[i][j];
        }
        cout<<endl;
    }
 return 0;

}












