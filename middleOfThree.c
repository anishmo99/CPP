#include <stdio.h>
#define max(a,b)    ((a < b) ?  (b) : (a))
#define min(a,b)    ((a < b) ?  (a) : (b))
int main() {
	int cases;
	scanf("%d", &cases);
	while(cases --)
	{
	    int a, b, c;
	    scanf("%d %d %d", &a, &b, &c);
	    int min1 = min(a, min(b, c));
	    int max1 = max(a, max(b, c));
	    int mid = (a + b + c) - (min1 + max1);
	    printf("%d\n", mid);
	}
	return 0;
}