/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.*/


class Solution {
public:
    bool canConstruct(string r, string m) {
        int h[26]={0};
        for(int i=0;i<m.size();i++)h[m[i]-'a']++;
        int cnt=0;
        for(int i=0;i<r.size();i++){
            if(h[r[i]-'a']<=0)cnt++;
            else h[r[i]-'a']--;
        }
        if(cnt>0)return 0;
        return 1;
    }
};