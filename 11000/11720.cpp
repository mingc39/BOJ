#include <stdio.h>

int main() {
	int num, sum = 0;
	
	scanf("%d", &num);
	for(int i = num; i > 0; i--) {
		scanf(" %c", &num);
		sum += num - '0';
	}
	printf("%d", sum);
	
	return 0;
}
