/*Given a binary string s and an integer k.

Return true if every binary code of length k is a substring of s. Otherwise, return false.

Constraints:

1 <= s.length <= 5 * 10^5

s consists of 0's and 1's only.

1 <= k <= 20

Input Format:

First Line contains a string s.

Second line contains an integer k.

Output Formal:

Contains true or false.

Input:

s = "00110110",  k = 2

Output:

true

Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int k;
	cin>>k;
	int ans=pow(2,k);
	unordered_map<string,int> mp;
	for(int i=0;i+k<=s.size();i++){
		string a=s.substr(i,k);
		mp[a]+=1;
	}
	if(mp.size()==ans)
	{
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}