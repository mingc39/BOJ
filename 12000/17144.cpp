#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
	int r, c, t;
	int **cur, **nxt, **tmp;
	int cux = -1, cuy, cdx, cdy, cnt;
	
	scanf("%d %d %d", &r, &c, &t);
	
	cur = (int**)malloc(sizeof(int*) * r);
	cur[0] = (int*)malloc(sizeof(int) * r * c);
	for(int i = 1; i < r; i++) cur[i] = cur[i - 1] + c;
	nxt = cur;
	cur = (int**)malloc(sizeof(int*) * r);
	cur[0] = (int*)malloc(sizeof(int) * r * c);
	for(int i = 1; i < r; i++) cur[i] = cur[i - 1] + c;
	
	// 입력  
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%d", &cur[i][j]);
			if(cur[i][j] == -1) {
				if(cux == -1) {
					cux = i;
					cuy = j;
				} else {
					cdx = i;
					cdy = j;
				}
			}
		}
	}
	
	while(t-- > 0) {
		// 다음 상태 배열 초기화 
		memset(nxt[0], 0, sizeof(int) * r * c);
		
		// 먼지 확산
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				// 해당 위치에 먼지가 없으면 통과  
				if(cur[i][j] <= 0) continue;
				
				// 해당 위치에 먼지가 있으면 확산  
				cnt = 0;
				if(i - 1 >= 0) { // 위로 확산  
					if(cur[i - 1][j] >= 0) {
						nxt[i - 1][j] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				if(i + 1 < r) { // 아래로 확산 
					if(cur[i + 1][j] >= 0) {
						nxt[i + 1][j] += cur[i][j] / 5;
						cnt++; 
					}
				}
				if(j - 1 >= 0) { // 왼쪽으로 확산  
					if(cur[i][j - 1] >= 0) {
						nxt[i][j - 1] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				if(j + 1 < c) { // 오른쪽으로 확산  
					if(cur[i][j + 1] >= 0) {
						nxt[i][j + 1] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				nxt[i][j] += cur[i][j] - cur[i][j] / 5 * cnt; // 확산되고 남은 먼지 
			}
		} 
		
		// 공기 청정기 위치 보존  
		nxt[cux][cuy] = -1;
		nxt[cdx][cdy] = -1;
		
		// 공기 청정기에 의한 먼지 이동 
		int pv = 0, nv;
		
		// 공기 청정기 윗부분 
		pv = 0;
		for(int i = cuy + 1; i <= c - 1; i++) { // 오른쪽으로 이동  
			nv = nxt[cux][i];
			nxt[cux][i] = pv;
			pv = nv;
		}
		for(int i = cux - 1; i >= 0; i--) { // 위로 이동  
			nv = nxt[i][c - 1];
			nxt[i][c - 1] = pv;
			pv = nv;
		}
		for(int i = c - 2; i >= 0; i--) { // 왼쪽으로 이동  
			nv = nxt[0][i];
			nxt[0][i] = pv;
			pv = nv;
		}
		for(int i = 1; i < cux; i++) { // 아래로 이동  
			nv = nxt[i][0];
			nxt[i][0] = pv;
			pv = nv;
		}
		
		// 공기 청정기 아랫부분 
		pv = 0;
		for(int i = cdy + 1; i < c; i++) { // 오른쪽으로 이동  
			nv = nxt[cdx][i];
			nxt[cdx][i] = pv;
			pv = nv;
		}
		for(int i = cdx + 1; i <= r - 1; i++) { // 아래로 이동  
			nv = nxt[i][c - 1];
			nxt[i][c - 1] = pv;
			pv = nv;
		}
		for(int i = c - 2; i >= 0; i--) { // 왼쪽으로 이동  
			nv = nxt[r - 1][i];
			nxt[r - 1][i] = pv;
			pv = nv;
		}
		for(int i = r - 2; i > cdx; i--) { // 위로 이동  
			nv = nxt[i][0];
			nxt[i][0] = pv;
			pv = nv;
		}
		
		// 새 먼지 분포를 현재 위치 분포로 이동  
		tmp = cur;
		cur = nxt;
		nxt = tmp;
	}
	
	// 전체 먼지 양 계산  
	cnt = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(cur[i][j] > 0) cnt += cur[i][j];
		}
	}
	
	// 출력 
	printf("%d", cnt);
	
	return 0;
}
