/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1. 1

2. 11

3. 21

4. 1211

5. 111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

Input: 4

Output: 1211

 Explanation: For n = 3 the term was 21 in which we have two groups 2 and 1, 2 can be read as 12 which means frequency = 1 and value = 2, the same way " is read as 11, so the answer is the concatenation of 12 and 11 which is 1211

 

SAMPLE INPUT 
9
SAMPLE OUTPUT 
31131211131221*/


#include<bits/stdc++.h>
using namespace std;
string func(int num){
    if(num==0 || num==1){
        return "1";
    }
    vector<string> v(num+1);
    v[0]="1";
    v[1]="1";
    int c=1;
    for(int i=2;i<=num;i++){
        for(int j=0;j<v[i-1].size();j++){
            if(v[i-1][j]==v[i-1][j+1] && j!=v[i-1].size()-1){
                c++;
            }
            else{
                v[i]+=to_string(c)+v[i-1][j];
                c=1;
            }
        }
    }
    return v[num];
}
int main()
{
    int n;
    cin>>n;
    string s;
    s=func(n);
    cout<<s;
    return 0;
}
