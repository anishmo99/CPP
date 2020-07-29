// first thought
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_map<int, int> ump1, ump2;
        for (auto i : nums1)
            ump1[i]++;
        for (auto i : nums2)
            ump2[i]++;
        for (auto x : ump1)
        {
            if (ump2.find(x.first) != ump2.end())
                result.push_back(x.first);
        }
        return result;
    }
};

// better solution

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;
        for (auto i : nums1)
            set1.insert(i);
        for (auto i : nums2)
        {
            if (set1.find(i) != set1.end())
                set2.emplace(i);
        }
        return {set2.begin(), set2.end()};
    }
};