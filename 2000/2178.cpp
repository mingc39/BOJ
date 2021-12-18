#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l, x, y;
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0;
	bool vb[100][100];
	
	// 입력 
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			scanf(" %c", &l);
			if(l == '1') vb[i][j] = 0;
			else vb[i][j] = 1;
		}
	}
	
	// 시작 위치 큐에 넣고 탐색 시작  
	queue[qs  ][2] = 1;
	queue[qs  ][1] = 0;
	queue[qs++][0] = 0;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][2];
		y = queue[qe  ][1];
		x = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		
		//printf("%d %d\n", x, y);
		if(vb[x][y] == true) continue; // 이미 방문했는지 확인  
		vb[x][y] = true;
		
		if(x == n - 1 && y == k - 1) break; // 끝부분에 도착하면 탐색 종료
		
		// 다음 위치 큐에 저장 
		if(x - 1 >= 0) {
			queue[qs  ][2] = l + 1;
			queue[qs  ][1] = y;
			queue[qs++][0] = x - 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(y - 1 >= 0) {
			queue[qs  ][2] = l + 1;
			queue[qs  ][1] = y - 1;
			queue[qs++][0] = x;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(x + 1 < n) {
			queue[qs  ][2] = l + 1;
			queue[qs  ][1] = y;
			queue[qs++][0] = x + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(y + 1 < k) {
			queue[qs  ][2] = l + 1;
			queue[qs  ][1] = y + 1;
			queue[qs++][0] = x;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 결과 출력  
	printf("%d", l);
	
	return 0;
}
