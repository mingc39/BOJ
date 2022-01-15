#include <stdio.h> 

int main() {
	int x1, x2, x3;
	int y1, y2, y3;
	
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	
	int a;
	a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	
	if(a == 0) putchar('0');
	else if(a > 0) putchar('1');
	else puts("-1");
	
	return 0;
}
