#include <stdio.h>

int main() {
	
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	while(a != 0 && b != 0 && c !=0) {
		
		a = a * a; b = b * b; c = c * c;
		if(a + b == c) printf("right\n");
		else if(a + c == b) printf("right\n");
		else if(b + c == a) printf("right\n");
		else printf("wrong\n");
		
		scanf("%d %d %d", &a, &b, &c);
	}
	
	return 0;
}
