// //Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]
// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:

// Input: nums = [1]
// Output: 1
class Solution1
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int val = 0;
        for (int num : nums)
        {
            val ^= num;
        }

        return val;
    }
};

class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mymap;

        for (int num : nums)
        {
            if (mymap.find(num) == mymap.end())
            {
                mymap[num] = 1;
            }
            else
            {
                mymap[num] += 1;
            }
        }

        for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        {
            if (it->second == 1)
                return it->first;
        }

        return -1;
    }
};
