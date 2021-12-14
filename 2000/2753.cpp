#include <stdio.h>

int main() {
	int num;
	
	scanf("%d", &num);
	
	if(num % 400 == 0 || num % 4 == 0 && num % 100 != 0) putchar('1');
	else putchar('0');
	
	return 0;
}
