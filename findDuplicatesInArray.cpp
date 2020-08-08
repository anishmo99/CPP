// O(N*logN)
vector<int> duplicates(int nums[], int n)
{
    vector<int> sol;
    sort(nums, nums + n);
    int sol_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (sol_count > 0 && sol[sol_count - 1] == nums[i])
            continue;
        if (nums[i] == nums[i + 1])
        {
            sol.push_back(nums[i]);
            sol_count++;
        }
    }
    if (sol.empty())
        sol.push_back(-1);
    return sol;
}

// gfg

// 2
// 4
// 0 3 1 2
// 5
// 2 3 1 2 3

// O(N)

vector<int> duplicates(int a[], int n) {
    vector<int> sol;
    for (int i = 0; i < n; i++) 
    { 
        a[a[i] % n] += n; 
    } 
    
    for (int i = 0; i < n; i++)  
    { 
        if (a[i] >= n*2)  
        { 
            sol.push_back(i);
        } 
    } 
    if(sol.empty())
        sol.push_back(-1);
    return sol;
}