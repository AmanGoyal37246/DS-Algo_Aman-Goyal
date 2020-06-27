You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

INPUT FORMAT

First line contains 2 integers number of coins(n) and the amount.

Next line contains n integers denoting the value of each coin.

OUTPUT

Print the minimum number of coins you need to make up the amount.

Example :

Input: 
3 11
1 2 5

Output: 3 
Explanation: 11 = 5 + 5 + 1
 

CONSTRAINTS

1 <= Number of Coins <= 500

1 <= Value of each Coin <= 5000

1 <= amount <= 105

SAMPLE INPUT 
3 11
1 3 5
SAMPLE OUTPUT 
3


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans[m+1];
    ans[0]=0;
    for(int i=1;i<=m;i++){
        ans[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<=i)
            {
                int res=ans[i-arr[j]];
                if(res!=INT_MAX){
                    ans[i]=min(ans[i],res+1);
                }
            }
        }
    }
    if(ans[m]==INT_MAX){
        return -1;
    }
    else{
        cout<<ans[m];
    }
    return 0;
}