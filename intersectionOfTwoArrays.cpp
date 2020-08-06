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

// GFG

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while(cases --)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    int arr1[n1], arr2[n2];
	    unordered_set<int> set1, set2;
	    int count = 0;
	    for(int i = 0; i < n1; i++)
	    {
	        cin >> arr1[i];
	        set1.insert(arr1[i]);
	    }
	    for(int i = 0; i < n2; i++)
	    {
	        cin >> arr2[i];
	        if(set1.find(arr2[i]) != set1.end())
	            set2.insert(arr2[i]);
	    }
	    cout << set2.size() << endl;
	}
	return 0;
}