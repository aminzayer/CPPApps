/* Given two strings s and t, return true if they are equal when both are typed into empty text editors.'#' means a backspace character.

    Note that after backspacing an empty text,
    the text will continue empty.

    Example 1 :

    Input : s = "ab#c",
            t = "ad#c" Output : true Explanation : Both s and t become "ac".

                                                   Example 2 :

    Input : s = "ab##",
            t = "c#d#" Output : true Explanation : Both s and t become "".

                                                   Example 3 :

    Input : s = "a#c",
            t = "b" Output : false Explanation : s becomes "c" while t becomes "b".
 */
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> st1 = realString(S);
        stack<char> st2 = realString(T);
        if (st1.size() != st2.size())
            return false;
        while (st1.size() > 0)
        {
            char p1 = st1.top();
            char p2 = st2.top();
            st1.pop();
            st2.pop();
            if (p1 != p2)
                return false;
        }
        return true;
    }

private:
    stack<char> realString(string S)
    {
        stack<char> st;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '#')
            {
                if (st.size() > 0)
                {
                    st.pop();
                }
            }
            else
            {
                st.push(S[i]);
            }
        }
        return st;
    }
};