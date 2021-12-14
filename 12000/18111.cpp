#include <stdio.h>

#define WORLD_SIZE 500
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int time(int w[WORLD_SIZE][WORLD_SIZE], int n, int m, int b, int h) {
	
	int t = 0, bb = 0, bp = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(w[i][j] < h) {
				t += h - w[i][j];
				bp += h - w[i][j];
			} else if(w[i][j] > h) {
				t += (w[i][j] - h) * 2;
				bb += w[i][j] - h;
			}
		}
	}
	
	if(b - bp + bb < 0) return -1;
	else return t;
}

int main() {
	int n, m, b, w[WORLD_SIZE][WORLD_SIZE];
	
	scanf("%d %d %d", &n, &m, &b);
	int min = INT_MAX, max = INT_MIN;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &w[i][j]);
			if(w[i][j] > max) max = w[i][j];
			if(w[i][j] < min) min = w[i][j];
		}
	}
	
	int t, hmax, tmin = INT_MAX;
	for(int i = max; i >= min; i--) {
		t = time(w, n, m, b, i);
		if(t < 0) continue;
		else {
			if(t < tmin) {
				hmax = i;
				tmin = t;
			}
		}
	}
	
	printf("%d %d", tmin, hmax);
	
	return 0;
}
