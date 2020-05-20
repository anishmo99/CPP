class Solution {
public:
    int firstMissingPositive
    {
        int n=nums.size();
        if(n==0)    return 1;
        vector<bool>num1(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0&&nums[i]<=n)
            {
                num1[nums[i]]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(num1[i]==false)
                return i;
        }
        return n+1;
    }
};
