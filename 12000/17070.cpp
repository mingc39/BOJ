#include <stdio.h>

// n-2 n-2 대각선
// n-1 n-2 가로
// n-2 n-1 세로  

int n, a[16][16];
int v[16][16][3];

// x, y 지점에 각도 d로 놓일 수 있는지 탐색  
int pipe(int x, int y, int d) {
	if(v[x][y][d] >= 0) return v[x][y][d];
	v[x][y][d] = 0;
	if(d == 0 && a[x][y + 1] == 0) { // 가로  
		if(y >= 1) 			 v[x][y][d] += pipe(x    , y - 1, 0);
		if(y >= 1 && x >= 1) v[x][y][d] += pipe(x - 1, y - 1, 2);
		return v[x][y][d];
	} else if(d == 1 && a[x + 1][y] == 0) { // 세로  
		if(x >= 1) 			 v[x][y][d] += pipe(x - 1, y    , 1);
		if(y >= 1 && x >= 1) v[x][y][d] += pipe(x - 1, y - 1, 2);
		return v[x][y][d];
	} else if(d == 2 && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) { // 대각선  
		if(y >= 1) 			 v[x][y][d] += pipe(x    , y - 1, 0);
		if(x >= 1) 			 v[x][y][d] += pipe(x - 1, y    , 1);
		if(y >= 1 && x >= 1) v[x][y][d] += pipe(x - 1, y - 1, 2);
		return v[x][y][d];
	} else return 0;
}

int main() {
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			v[i][j][0] = -1; // 가로 
			v[i][j][1] = -1; // 세로 
			v[i][j][2] = -1; // 대각선  
		}
	}
	v[0][0][0] = 1; // 초기값((1, 1)에 가로) 지정  
	
	printf("%d", pipe(n - 2, n - 2, 2) + pipe(n - 2, n - 1, 1) + pipe(n - 1, n - 2, 0));
	
	return 0;
}
