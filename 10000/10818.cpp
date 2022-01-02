#include <stdio.h>

int main() {
	int n, t;
	int min = +9999999, max = -9999999;
	
	for(scanf("%d", &n); n > 0; n--) {
		scanf("%d", &t);
		if(min > t) min = t;
		if(max < t) max = t;
	}
	
	printf("%d %d", min, max);
	
	return 0;
}
