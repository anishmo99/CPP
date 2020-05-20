//all test cases did nit pass
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t, n, k, x, y, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &k, &n);
		priority_queue<int> data;
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			while (x--) data.push(y);
		}
		while (k--) {
			ans += data.top();
			data.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}