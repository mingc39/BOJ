#include <stdio.h>

int main() {
	
	int N, r, c;
	int a = 0;
	
	scanf("%d %d %d", &N, &r, &c); 
	
	for(int i = N; i > 0; i--) {
		
		if(r >= (1 << (i - 1))) {
			a += 1 << (2 * i - 1);
			r -= 1 << (i - 1);
		}
		
		if(c >= (1 << (i - 1))) {
			a += 1 << (2 * i - 2);
			c -= 1 << (i - 1);
		}
		
	}
	
	printf("%d", a);
}