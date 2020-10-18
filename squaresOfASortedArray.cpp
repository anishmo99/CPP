class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> sol(A.size());

        int low = 0, high = A.size() - 1, pos = A.size() - 1;

        while (low <= high)
        {
            if (abs(A[low]) > abs(A[high]))
            {
                sol[pos--] = pow(A[low], 2);
                low++;
            }
            else
            {
                sol[pos--] = pow(A[high], 2);
                high--;
            }
        }

        return sol;
    }
};