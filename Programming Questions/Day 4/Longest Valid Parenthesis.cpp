/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"

Output: 2

Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"

Output: 4

Explanation: The longest valid parentheses substring is "()()"*/


#include<bits/stdc++.h>
using namespace std;
int func(string str){
	int length=0;
	stack<int> s;
	s.push(-1);
	for(int i=0;i<str.length();i++){
		if(str[i]=='('){
			s.push(i);
		}
		else{
			s.pop();
			if(s.empty()){
				s.push(i);
			}
			else{
				length=max(length,i-s.top());
			}
		}
	}
	return length;
}
int main()
{
	string str;
	getline(cin,str);
	cout<<func(str);
	return 0;
}