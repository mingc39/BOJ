#include <stdio.h>

int main() {
	int n[10], l, i;
	scanf("%d", &n[0]);
	while(n[0] != 0) {
		for(l = 1; l < 10; l++) {
			if(n[l - 1] < 10) break;
			n[l] = n[l - 1] / 10;
			n[l - 1] = n[l - 1] % 10;
		}
		
		for(i = 0; i < l / 2; i++) {
			if(n[i] != n[l - i - 1]) { printf("no\n"); break; }
		}
		if(i == l / 2) printf("yes\n");
		
		scanf("%d", &n[0]);
	}
	return 0;
}
