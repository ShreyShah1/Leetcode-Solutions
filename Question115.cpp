/**
 * AUTHOR: Shrey Shah
 * Language: Cpp
 * LeetCode Question No: 115
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * Return 3.
 */





class Solution {
public:
    int numDistinct(string s, string t) {
        int length1 = s.length();
        int length2 = t.length();
        
        int distinctOccurances[length1 + 1][length2 + 1];
        
        // Initialise the base cases.
        // Null Pattern and String always is a match so initialising 1 everywhere.
        
        for (int row = 0 ; row <= length1 ; row++) {
            distinctOccurances[row][0] = 1;    
        }
        
        // Null string and a pattern is not a match so intialising 0 everywhere.
        for (int col = 1 ; col <= length2 ; col++) {
            distinctOccurances[0][col] = 0;
        }
        for (int row = 0 ; row < length1 ; row++) {
            for (int col = 0 ; col < length2 ; col++) {
                if (s[row] == t[col]) {
                    distinctOccurances[row+1][col+1] = distinctOccurances[row][col] + distinctOccurances[row][col+1];
                } else {
                    distinctOccurances[row+1][col+1] = distinctOccurances[row][col+1];
                }
            } 
        }
        
        return distinctOccurances[length1][length2];
    }
};
