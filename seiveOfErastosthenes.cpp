class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<bool> prime(n + 1, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        vector<int> sol;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
                sol.push_back(i);
        }

        return sol;
    }
};