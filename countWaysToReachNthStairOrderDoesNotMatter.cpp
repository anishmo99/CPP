#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
	int n, res;
	scanf("%d", &n);
	res = (n / 2) + 1;
	printf("%d\n", res);
	}
	return 0;
}