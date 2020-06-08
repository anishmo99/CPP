vector <int> countDistinct (int arr[], int n, int k)
{
    vector<int> ans;
    int i=0,j=0;
    int count=0;
    unordered_map<int,int> ump;
    while(j<n)
    {
        if(j-i<k)
        {
            if(ump.find(arr[j])==ump.end())
            {
                count++;
            }
            ump[arr[j]]++;
            j++;
        }
        else
        {
            ans.push_back(count);
            if(ump[arr[i]]>1)
                ump[arr[i]]--;
            else
            {
                ump.erase(arr[i]);
                count--;
            }
            i++;
        }
    }
    ans.push_back(count);
    return ans;
}
