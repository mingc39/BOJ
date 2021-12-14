#include <stdio.h>

int main() {
	int num, idx, max = 0;
	
	for(int i = 0; i < 9; i++) {
		scanf("%d", &num);
		if(num > max) {
			max = num;
			idx = i + 1;
		}
	}
	
	printf("%d\n%d", max, idx);
	
	return 0;
}
