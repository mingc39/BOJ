#include <stdio.h>

int main() {
	int t, r;
	char s[24];
	
	for(scanf("%d", &t); t > 0; t--) {
		scanf("%d %s", &r, s);
		for(int i = 0; s[i] != '\0'; i++) {
			for(int j = 0; j < r; j++) putchar(s[i]);
		}
		putchar('\n');
	}
	
	return 0;
}
