#include <stdio.h>

// void s()는 2667 단지번호에서 쓴거 수정  
void s(int a[1000][1000], int x, int y, int m, int n, int v, int *cnt) {
	if(a[x][y] != 0) return;
	a[x][y] = v;
	*cnt = *cnt + 1;
	if(x < m - 1) s(a, x + 1, y, m, n, v, cnt);
	if(y < n - 1) s(a, x, y + 1, m, n, v, cnt);
	if(x > 0)     s(a, x - 1, y, m, n, v, cnt);
	if(y > 0)     s(a, x, y - 1, m, n, v, cnt);
}

int main() {
	int t, m, n, l = 2;
	int near[4];
	int a[1000][1000];
	int c[500002];
	
	// 입력 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &t);
			if(t == '0') a[i][j] = 0;
			else if(t == '1') a[i][j] = 1;
		}
	}
	
	// 0 뭉텅이(?)에 0이 각각 몇 개 있는지 알아내기  
	// a[i][j]가 0이면 뭉텅이 번호(2부터 시작)가 부여되고
	// c[i]에 i번째 뭉텅이(i >= 2)의 0 개수 저장(c[0], c[1]은 0) 
	c[0] = c[1] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 0) {
				t = 0;
				s(a, i, j, n, m, l, &t);
				c[l++] = t;
			}
		}
	}
	
	// 벽뿌! 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			// 벽이 있는 경우  
			if(a[i][j] == 1) {
				// 상하좌우에 인접한  뭉텅이 번호 알어오기  
				near[0] = 1; near[1] = 1; near[2] = 1; near[3] = 1;
				if(i > 0)     near[0] = a[i - 1][j];
				if(j > 0)     near[1] = a[i][j - 1];
				if(i < n - 1) near[2] = a[i + 1][j];
				if(j < m - 1) near[3] = a[i][j + 1];
				// 중복된 뭉텅이 하나만 남기고 제거  
				for(int i = 0; i <= 2; i++) {
					for(int j = i + 1; j <= 3; j++) {
						if(near[i] == near[j]) near[j] = 1;
					}
				}
				// 각각의 뭉텅이에 포함된 0의 갯수 + 벽 부순자리 자기 자신 출력  
				t = c[near[0]] + c[near[1]] + c[near[2]] + c[near[3]] + 1;
				printf("%d", t % 10);
			} else putchar('0');
		} putchar('\n');
	}
	
	return 0;
}
