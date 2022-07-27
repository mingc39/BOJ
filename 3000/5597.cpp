#include <stdio.h>

int main() {
	int c[30] = { 0, }, t;
	
	for(int i = 0; i < 28; i++) {
		scanf("%d", &t);
		c[t - 1] = 1;
	}
	
	for(int i = 0; i < 30; i++) {
		if(c[i] == 0) printf("%d\n", i + 1);
	}
	
	return 0;
}
