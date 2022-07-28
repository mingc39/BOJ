#include <stdio.h>

int main() {
	int n, s, p, r1 = 1, r2 = 1;
	int l[50];
	
	scanf("%d %d %d", &n, &s, &p);
	for(int i = 0, t; i < n; i++) {
		scanf("%d", &t);
		if(t >  s) r1++;
		if(t >= s) r2++;
	}
	if(r2 > p) r1 = -1;
	printf("%d", r1);
	
	return 0;
}
