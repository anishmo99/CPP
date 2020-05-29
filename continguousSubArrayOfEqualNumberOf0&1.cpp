class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>m;
        int max_len=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            count=count+(nums.at(i)==1?1:-1);
            if(count==0)
            {
                max_len=max(max_len,i+1);
            }
            else if(m.find(count)==m.end())
            {
                m[count]=i;
            }
            else
            {
                max_len=max(max_len,i-m[count]);
            }
        }
        return max_len;
    }
};

/*
 * //gfg solution
 * int maxLen(int arr[], int n) {
    int max_len=0,count=0;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        count+=arr[i]==1?1:-1;
        if(count==0)
            max_len=max(max_len,i+1);
        else if(m.find(count)==m.end())
            m[count]=i;
        else
            max_len=max(max_len,i-m[count]);
    }
    return max_len;
}
 */