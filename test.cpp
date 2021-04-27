#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long int lli;

lli solve()
{
	lli n, m, x;
	cin >> n >> m >> x;

	lli ans = 1;
	lli temp = 1;

	lli col = 0, row = 0;
	while (temp < x)
	{
		col++;
		temp += n;
	}

	while (x != temp)
	{
		temp++;
		row++;
	}

	while (row--)
	{
		ans += m;
	}

	while (col--)
	{
		ans++;
	}

	return ans;
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cases;
	cin >> cases;
	int k = 1;
	while (cases--)
	{
		cout << solve() << endl;
	}
	return 0;
}
