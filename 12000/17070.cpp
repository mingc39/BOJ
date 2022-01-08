#include <stdio.h>

// n-2 n-2 �밢��
// n-1 n-2 ����
// n-2 n-1 ����  

int n, a[16][16];
int v[16][16][3];

// x, y ������ ���� d�� ���� �� �ִ��� Ž��  
int pipe(int x, int y, int d) {
	if(v[x][y][d] >= 0) return v[x][y][d];
	v[x][y][d] = 0;
	if(d == 0 && a[x][y + 1] == 0) { // ����  
		if(y >= 1) 			 v[x][y][d] += pipe(x    , y - 1, 0);
		if(y >= 1 && x >= 1) v[x][y][d] += pipe(x - 1, y - 1, 2);
		return v[x][y][d];
	} else if(d == 1 && a[x + 1][y] == 0) { // ����  
		if(x >= 1) 			 v[x][y][d] += pipe(x - 1, y    , 1);
		if(y >= 1 && x >= 1) v[x][y][d] += pipe(x - 1, y - 1, 2);
		return v[x][y][d];
	} else if(d == 2 && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) { // �밢��  
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
			v[i][j][0] = -1; // ���� 
			v[i][j][1] = -1; // ���� 
			v[i][j][2] = -1; // �밢��  
		}
	}
	v[0][0][0] = 1; // �ʱⰪ((1, 1)�� ����) ����  
	
	printf("%d", pipe(n - 2, n - 2, 2) + pipe(n - 2, n - 1, 1) + pipe(n - 1, n - 2, 0));
	
	return 0;
}
