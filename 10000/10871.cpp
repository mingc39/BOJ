#include <stdio.h>

int main() {
	int n, x, t;
	
	scanf("%d %d", &n, &x);
	
	while(n-- > 0) {
		scanf("%d", &t);
		if(t < x) printf("%d ", t);
	}
	
	return 0;
}
