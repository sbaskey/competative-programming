#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool c(int x,int y)
{
    return x>y;
}

int main()
{
    vector<int>A={1,21,34,12,4};
    cout<<A[1]<<endl;

    sort(A.begin(),A.end());//nlogn

    bool present=binary_search(A.begin(),A.end(),21);

    cout<<present<<endl;
    A.push_back(1000);
    A.push_back(1000);
    A.push_back(1000);
    A.push_back(2000);
     sort(A.begin(),A.end());//nlogn



    vector<int>::iterator it=lower_bound(A.begin(),A.end(),1000);//>=
    cout<<*it<<endl;
    vector<int>::iterator it1=upper_bound(A.begin(),A.end(),1000);//>
    cout<<*it1<<endl;

    cout<<it1-it<<endl;

    sort(A.begin(),A.end(),c);

    vector<int>:: iterator i3;
    for (i3=A.begin(); i3!=A.end(); i3++)
        cout<<*i3<<" ";

    cout<<endl;








return 0;

}