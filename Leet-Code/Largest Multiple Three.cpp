class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        vector<int> c(10);
        for (int d : digits)
            ++c[d];

        auto getNum = [&](const vector<int> &ds)
        {
            for (int d : ds)
                --c[d];
            string ans;
            for (int d = 9; d >= 1; --d)
                ans.append(c[d], '0' + d);
            ans.append(ans.empty() ? min(1, c[0]) : c[0], '0');
            return ans;
        };

        const int r = accumulate(begin(digits), end(digits), 0) % 3;
        vector<vector<int>> rs{{0, 3, 6, 9}, {1, 4, 7}, {2, 5, 8}};

        // Use all digitis.
        if (r == 0)
            return getNum({});
        // Remove one among {1, 4, 7}, {2, 5, 8}
        for (int d : rs[r])
            if (c[d])
                return getNum({d});
        // Remove two among {1, 4, 7}^2 (r = 2), {2, 5, 8}^2 (r = 1)
        for (int d1 : rs[3 - r])
            for (int d2 : rs[3 - r])
                if (d1 == d2 && c[d1] > 1 || d1 != d2 && c[d1] && c[d2])
                    return getNum({d1, d2});
        return "";
    }
};