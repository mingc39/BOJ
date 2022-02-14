#include <stdio.h>

typedef struct conv{
	int x;
	int y;
	int m;
} conv;

int main() {
	int n, m = 0;
	conv a[1000];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &(a[i].x), &(a[i].y));
		a[i].m = 0;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int t = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
			if(t > a[i].m) a[i].m = t;
		}
		if(a[m].m > a[i].m) m = i;
	}
	
	printf("%d %d", a[m].x, a[m].y);
	
	return 0;
}
