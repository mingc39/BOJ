#include <stdio.h>

int main() {
	int n, t, c = 0;
	
	scanf("%d", &n);
	
	for(int i = 5; i <= n; i += 5) {
		t = i;
		while(t % 5 == 0) {
			c++;
			t /= 5;
		}
	}
	
	printf("%d", c);
	
	return 0;
}
