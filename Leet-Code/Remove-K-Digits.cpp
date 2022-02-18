// Remove K Digits
// Given string num representing a non - negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

//                                                                                      Example 1 :

//     Input : num = "1432219",
//             k = 3 Output : "1219" Explanation : Remove the three digits 4, 3, and2 to form the new number 1219 which is the smallest.

//                                                                                  Example 2 :

//     Input : num = "10200",
//             k = 1 Output : "200" Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

//                                                Example 3 :

//     Input : num = "10",
//             k = 2 Output : "0" Explanation : Remove all the digits from the number and it is left with nothing which is 0.

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == k)
            return "0";

        string ans;
        stack<char> s({num[0]});

        for (int i = 1; i < num.size(); ++i)
        {
            while (k > 0 && !s.empty() && s.top() > num[i])
            {
                --k;
                s.pop();
            }

            s.push(num[i]);

            if (s.size() == 1 && s.top() == '0')
            {
                s.pop();
            }
        }

        while (k > 0 && !s.empty())
        {
            --k;
            s.pop();
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        if (ans.size() == 0)
            return "0";
        else
            return ans;
    }
};