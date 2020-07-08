/*The robber is very smart and  planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping thief from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Input:

n=4

nums = 1,2,3,1 

Output: 4

Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).   Total amount you can rob = 1 + 3 = 4.

Constraints:

0 <= nums.length < 10000

 

SAMPLE INPUT 
4
1
2
3
1
SAMPLE OUTPUT 
4*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=arr[0];
    for(int i=2;i<=n;i++){
        ans[i]=max(arr[i-1]+ans[i-2],ans[i-1]);
    }
    cout<<ans[n];
    return 0;
}
