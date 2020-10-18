class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int count = 0;
        vector<pair<int, int>> vec;

        int i = 0, j = 1;

        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }

            j++;

            if (j == nums.size())
            {
                i++;
                j = i + 1;
            }
        }

        return count;
    }
};

// or

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                    sum++;
            }
        }
        return sum;
    }
};