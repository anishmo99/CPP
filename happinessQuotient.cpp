long long int minHappiness(long long int a[], long long int b[], int n, int k)
{
    long long int sum = 0;

    int abs_max_pos_b = 0;

    for (int i = 1; i < n; i++)
    {
        if (abs(b[abs_max_pos_b]) < abs(b[i]))
            abs_max_pos_b = i;
    }

    if (b[abs_max_pos_b] >= 0)
        a[abs_max_pos_b] -= k * 2;
    else
        a[abs_max_pos_b] += k * 2;

    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
}