#include <stdio.h>
#include <memory.h>

int main() {
	int n, m, a[8][8], vi[10][2], vl = 0;
	int s[128][2], v[8][8], p;
	int cnt, max = 0;
	
	// 입력  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if(a[i][j] == 2) {
				vi[vl][0] = i;
				vi[vl][1] = j;
				vl++;
			}
		}
	}
	
	// 모든 경우 확인  
	for(int i = 0; i < n * m; i++) {
		if(a[i / m][i % m] != 0) continue;
		
		for(int j = i + 1; j < n * m; j++) {
			if(a[j / m][j % m] != 0) continue;
			
			for(int k = j + 1; k < n * m; k++) {
				if(a[k / m][k % m] != 0) continue;
				
				// 초기화  
				memset(v, 0, sizeof(int) * 64);
				p = 0;
				for(int l = 0; l < vl; l++) {
					s[p][0] = vi[l][0];
					s[p][1] = vi[l][1];
					p++;
					v[vi[l][0]][vi[l][1]] = 1;
				}
				
				// 바이러스 퍼트리기  
				while(p > 0) {
					p--;
					int c = s[p][0];
					int b = s[p][1];
					
					if(c - 1 >= 0) {
						if(v[c - 1][b] == 0 && a[c - 1][b] == 0 && !(c - 1 == i / m && b == i % m) && !(c - 1 == j / m && b == j % m) && !(c - 1 == k / m && b == k % m)) {
							s[p][0] = c - 1;
							s[p][1] = b;
							p++;
							v[c - 1][b] = 1;
						}
					}
					if(c + 1 < n) {
						if(v[c + 1][b] == 0 && a[c + 1][b] == 0 && !(c + 1 == i / m && b == i % m) && !(c + 1 == j / m && b == j % m) && !(c + 1 == k / m && b == k % m)) {
							s[p][0] = c + 1;
							s[p][1] = b;
							p++;
							v[c + 1][b] = 1;
						}
					}
					if(b - 1 >= 0) {
						if(v[c][b - 1] == 0 && a[c][b - 1] == 0 && !(c == i / m && b - 1 == i % m) && !(c == j / m && b - 1 == j % m) && !(c == k / m && b - 1 == k % m)) {
							s[p][0] = c;
							s[p][1] = b - 1;
							p++;
							v[c][b - 1] = 1;
						}
					}
					if(b + 1 < m) {
						if(v[c][b + 1] == 0 && a[c][b + 1] == 0 && !(c == i / m && b + 1 == i % m) && !(c == j / m && b + 1 == j % m) && !(c == k / m && b + 1 == k % m)) {
							s[p][0] = c;
							s[p][1] = b + 1;
							p++;
							v[c][b + 1] = 1;
						}
					}
				}
				
				// 바이러스가 퍼지지 않는 위치 확인  
				cnt = 0;
				for(int b = 0; b < n; b++) {
					for(int c = 0; c < m; c++) {
						if(a[b][c] == 0 && v[b][c] == 0) cnt++;
					}
				}
				if(cnt - 3 > max) max = cnt - 3;
			}
		}
	}
	
	printf("%d", max);
	
	return 0;
}
