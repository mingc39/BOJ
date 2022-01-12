#include <stdio.h>

int n, m, a[10][10], b[19];

void convCord(int l, int p, int* x, int* y) {
	if(l < n) {
		*x = l - p;
		*y = p;
	} else {
		*x = n - p - 1;
		*y = l - n + 1 + p;
	}
}

int checkPos(int l, int p, int k) {
	if(l < 0 || p < 0) return 0;
	int cx, cy, tx, ty;
	convCord(l, p, &cx, &cy);
	if(cx < 0 || cx >= n) return 0;
	if(cy < 0 || cy >= n) return 0;
	if(a[cx][cy] != 1) return 0;
	for(int i = l % 2; i < k; i += 2) {
		if(b[i] < 0) continue;
		convCord(i, b[i], &tx, &ty);
		if(tx - cx == ty - cy) return 0;
	}
	return 1;
}

void f(int k, int p, int c) {
	// 가망이 없는 경우 탐색 중단  
	if(2 * n - 1 - k + c <= m) return;
	
	// 이번 비숍 놓기 
	if(checkPos(k, p, k) != 0) {
		b[k] = p;
		c++;
	} else if(p >= 0) return;
	
	
	// 비숍을 놓을 대각선이 없으면 리턴  
	if(k + 1 == 2 * n - 1) {
		// 최댓값 갱신
		if(c > m) m = c;
		return;
	}
	
	// 다음 비숍 놓기  
	int l = k + 1;
	if(l > n) l = 2 * n - l - 1;
	for(int i = 0; i <= l; i++) {
		f(k + 1, i, c);
		if(2 * n - 1 - k + c <= m) return; 
	}
	f(k + 1, -1, c);
}

int main() {
	
	// 입력  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i = 0; i < 19; i++) b[i] = -1;
	
	f(0, 0, 0);
	f(0, -1, 0);
	
	printf("%d", m);
	
	return 0;
}
