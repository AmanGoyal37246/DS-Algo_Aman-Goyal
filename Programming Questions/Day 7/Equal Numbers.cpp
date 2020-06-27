Given a binary array of length n, find the maximum length of a contiguous subarray with equal number of 0 and 1.

INPUT FORMAT: 

First line will contain a single integer n, denoting the length of array .

Next line will contain n elements of the array.

OUTPUT: 

Print the length of the contigous subarray.

CONSTRAINTS

2 <= n <= 50000

 

Example 1:

Input:                          Output:
2                               2
0 1  

Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
 

SAMPLE INPUT 
3
0 1 0
SAMPLE OUTPUT 
2


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
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			arr[i]=-1;
		}
	}
	for(int i=1;i<n;i++){
		arr[i]+=arr[i-1];
	}
	int op=0;
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			op=max(op,i+1);
		}
		else{
			if(m.find(arr[i])!=m.end()){
				op=max(op,i-m[arr[i]]);
			}
			else{
				m[arr[i]]=i;
			}
		}
	}
	cout<<op;
	return 0;
}