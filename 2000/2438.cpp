#include <stdio.h>

int main() {
	int num, idx, max = 0;
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++) {
		for(int j = 0; j <= i; j++) putchar('*');
		putchar('\n');
	}
	
	return 0;
}
