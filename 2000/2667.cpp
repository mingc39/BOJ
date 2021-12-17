#include <stdio.h>
#include <stdlib.h>

// qsort 비교함수(정수용) 
int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

// 10026 적록색약 코드 수정 
// 1012번 유기농 배추 코드 수정  
// 상하좌우 재귀함수로 탐색
// 값이 v면 계속 탐색 아니면 종료 
// 이미 탐색한 곳은 재방문 필요 없으므로 0으로 변경  
// 방문한 곳 수를 cnt에 세어보기  
void s(int a[100][100], int x, int y, int m, int n, int v, int *cnt) {
	if(a[x][y] != v) return;
	a[x][y] = 0;
	*cnt = *cnt + 1;
	if(x < m - 1) s(a, x + 1, y, m, n, v, cnt);
	if(y < n - 1) s(a, x, y + 1, m, n, v, cnt);
	if(x > 0)     s(a, x - 1, y, m, n, v, cnt);
	if(y > 0)     s(a, x, y - 1, m, n, v, cnt);
}

int main() {
	int t, m, n;
	int a[100][100];
	int c[400];
	
	// 입력 받기  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf(" %c", &t);
			if(t == '0') a[i][j] = 0;
			else if(t == '1') a[i][j] = 1;
		}
	}
	
	m = 0; // 단지수  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 0) {
				t = 0; // 단지내 집 수 
				s(a, i, j, n, n, a[i][j], &t);
				c[m] = t; // 단지내 집 수를 배열에 저장  
				m++;
			}
		}
	}
	
	printf("%d", m); // 단지 수 출력 
	
	qsort(c, m, sizeof(int), cmp); // 단지내 집 수 정렬 
	
	for(int i = 0; i < m; i++) printf("\n%d", c[i]); // 단지내 집 수 출력  
	
	return 0;
}

