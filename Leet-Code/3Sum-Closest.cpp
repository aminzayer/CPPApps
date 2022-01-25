class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int result = num[0] + num[1] + num.back();
        for (int i = 0; i < num.size(); i++)
        {
            int j = i + 1, k = num.size() - 1;
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                if (abs(sum - target) < abs(result - target))
                    result = sum;
                if (sum == target)
                    return sum;
                if (sum < target)
                {
                    j++;
                }
                if (sum > target)
                {
                    k--;
                }
            }
        }
        return result;
    }
};