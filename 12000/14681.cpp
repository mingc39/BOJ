#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if(x > 0 && y > 0) putchar('1');
	if(x > 0 && y < 0) putchar('4');
	if(x < 0 && y > 0) putchar('2');
	if(x < 0 && y < 0) putchar('3');
	
	return 0;
}
