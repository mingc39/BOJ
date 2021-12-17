#include <stdio.h>

// 1012번 유기농 배추 코드 수정  
// 상하좌우 재귀함수로 탐색
// 값이 v면 계속 탐색 아니면 종료 
// 이미 탐색한 곳은 재방문 필요 없으므로 0으로 변경  
void s(int a[100][100], int x, int y, int m, int n, int v) {
	if(a[x][y] != v) return;
	a[x][y] = 0;
	if(x < m - 1) s(a, x + 1, y, m, n, v);
	if(y < n - 1) s(a, x, y + 1, m, n, v);
	if(x > 0)     s(a, x - 1, y, m, n, v);
	if(y > 0)     s(a, x, y - 1, m, n, v);
}

int main() {
	int t, m, n, k;
	int a[100][100]; // 정상인용  
	int b[100][100]; // 색약자용  
	
	// 입력 받기  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf(" %c", &t);
			switch(t) {
			case 'R':
				a[i][j] = 1;
				b[i][j] = 1;
				break;
			case 'G':
				a[i][j] = 2;
				b[i][j] = 1;
				break;
			case 'B':
				a[i][j] = 3;
				b[i][j] = 3;
				break;
			}
		}
	}
	
	m = 0; k = 0; // 정상인 영역수; 색약자 영역수; 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 0) {
				s(a, i, j, n, n, a[i][j]);
				m++;
			}
			if(b[i][j] != 0) {
				s(b, i, j, n, n, b[i][j]);
				k++;
			}
		}
	}
	
	// 출력 
	printf("%d %d", m, k);
	
	return 0;
}

