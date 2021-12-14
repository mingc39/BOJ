#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int l, s, t;
	if(a > b) { l = a; s = b; }
	else if(a < b)  { l = b; s = a; }
	else { l = a; s = 0; }
	while(s != 0) {
		t = s;
		s = l % s;
		l = t;
	}
	printf("%d\n%d", l, a * b / l);
	return 0;
}
