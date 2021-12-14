#include <stdio.h>
#include <stdlib.h>

int c1 = 0;
int c0 = 0;
int cm = 0;

void paper(int** p, int x, int y, int s) {
	
	int t = p[x][y];
	for(int i = x; i < x + s; i++) {
		for(int j = y; j < y + s; j++) {
			if(t != p[i][j]) {
				paper(p,             x,             y, s / 3);
				paper(p,             x,     y + s / 3, s / 3);
				paper(p,             x, y + 2 * s / 3, s / 3);
				paper(p,     x + s / 3,             y, s / 3);
				paper(p,     x + s / 3,     y + s / 3, s / 3);
				paper(p,     x + s / 3, y + 2 * s / 3, s / 3);
				paper(p, x + 2 * s / 3,             y, s / 3);
				paper(p, x + 2 * s / 3,     y + s / 3, s / 3);
				paper(p, x + 2 * s / 3, y + 2 * s / 3, s / 3);
				return;
			}
		}
	}
	
	if(t == 1) c1++;
	else if(t == 0) c0++;
	else if(t == -1) cm++;
}

int main() {
	int n, **p;
	scanf("%d", &n);
	p = (int**)malloc(sizeof(int*) * n);
	p[0] = (int*)malloc(sizeof(int) * n * n);
	for(int i = 1; i < n; i++) p[i] = p[i - 1] + n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	
	paper(p, 0, 0, n);
	
	printf("%d\n", cm);
	printf("%d\n", c0);
	printf(  "%d", c1);
	
	return 0;
}
