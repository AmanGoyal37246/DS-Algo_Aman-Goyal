/*Given a range [m, n] , return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: 0 1
Output: 0
CONSTRAINTS

0 <= m <= n <= 2147483647

INPUT FORMAT

The input contains 2 numbers m,n

OUTPUT FORMAT

Print the bitwise and of all the numbers in the range.*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
    int c=0;
	while(m^n){
		m=m>>1;
		n=n>>1;
		c++;
	}
	int ans=m<<c;
	cout<<ans;
}