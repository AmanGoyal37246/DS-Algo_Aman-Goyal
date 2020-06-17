/*Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
      int n = A.size();
      
      if(n == 0)
          return {};
      sort(A.begin(), A.end());
      vector<int> dp(n, 1);
      vector<int> previous_index(n, -1);
       
      int max_ind = 0; 
      
       for(int i=1; i<n; i++) {
           for(int j=0; j<i; j++) {
               if(A[i]%A[j]==0 and dp[i] < dp[j] + 1) {
                   dp[i] = dp[j]+1;
                   previous_index[i] = j;
               }
           }
           if(dp[i] > dp[max_ind]) {
               max_ind = i;
           }
       }
        
      vector<int> answer;
      int t = max_ind;  
      while(t >= 0) {
          answer.push_back(A[t]);
          t = previous_index[t];
      }
       
      return answer;  
    }
};