Given a 2 dimenstional matrix whose elements are 0 and 1 only. Find the largest square that contain only 1's and return the area of that square.

 

Example:

Input:

4

5

1 0 1 0 0

1 0 1 1 1

1 1 1 1 1

1 0 0 1 0

 

Output: 4

Constraints 

0 < rows < 10,000

0 < columns < 10,000

SAMPLE INPUT 
4
5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
SAMPLE OUTPUT 
4
Explanation
We need to find the largest square comprising of all ones in the given m×n matrix. In other words we need to find the largest set of connected ones in the given matrix that forms a square.


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    int output[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[i][j]=arr[i][j];
            if(i!=0 && j!=0 && arr[i][j]==1){
                output[i][j]=1+min(output[i-1][j-1],min(output[i-1][j],output[i][j-1]));
            }
            ans=max(ans,output[i][j]);
        }
    }
    cout<<ans*ans;
    return 0;
}