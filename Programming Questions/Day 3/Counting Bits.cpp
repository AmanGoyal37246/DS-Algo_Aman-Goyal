/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.*/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1,0);
        for(int i=1 ; i<=num ; i++){
            if(i%2 == 0)
                v[i] = v[i>>1]; // if i is even then same as i/2 (as last bit is 0)
            else
                v[i] = v[i-1]+1; // if odd then previous ans + 1 
        }
        return v;
    }
};