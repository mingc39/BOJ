#include <stdio.h>

int main() {
	int s;
	
	scanf("%d", &s);
	
	if(s >= 90) putchar('A');
	else if(s >= 80) putchar('B');
	else if(s >= 70) putchar('C');
	else if(s >= 60) putchar('D');
	else putchar('F');
	
	return 0;
}
