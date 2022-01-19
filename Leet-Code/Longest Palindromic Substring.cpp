// Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

//                          Example 1 :

//     Input : s = "babad" Output : "bab" Explanation : "aba" is also a valid answer.

//                                                      Example 2 :

//     Input : s = "cbbd" Output : "bb"
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string rlt = "";
        //vector<vector<bool>> isPal(n, vector<bool> (n, false));//leads to TLE
        bool isPal[1000][1000] = {false};
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if ((i + 1 >= j - 1 || isPal[i + 1][j - 1]) && s[i] == s[j])
                {
                    isPal[i][j] = true;
                    if (j - i + 1 > rlt.size())
                        rlt = s.substr(i, j - i + 1);
                }
            }
        }
        return rlt;
    }
};