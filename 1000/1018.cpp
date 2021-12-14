#include <stdio.h>

int chessBoard(char c[50][50], int n, int m, int x, int y) {
	
	int b = 0, w = 0;
	
	// 첫 칸이 B인 경우 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((i + j) % 2 == 0 && c[i + x][j + y] == 'W') b++;
			if((i + j) % 2 == 1 && c[i + x][j + y] == 'B') b++;
		}
	}
	
	// 첫 칸이 W인 경우 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((i + j) % 2 == 0 && c[i + x][j + y] == 'B') w++;
			if((i + j) % 2 == 1 && c[i + x][j + y] == 'W') w++;
		}
	}
	
	if(b < w) return b;
	else return w;
}

int main() {
	int n, m;
	char c[50][50];
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", c[i]);
	
	int min = 999999999;
	int t;
	
	for(int i = 0; i < n - 7; i++) {
		for(int j = 0; j < m - 7; j++) {
			t = chessBoard(c, 8, 8, i, j);
			if(t < min) min = t;
		}
	}
	
	printf("%d", min);
	
	return 0;
}
