#include <stdio.h>
#define QUEUE_SIZE 100000

int main() {
	// 메모리 할당 못해서 뻑나면 변수를 전역변수로 옮기세요  
	int n, m, a[1000][1000]; // 맵 크기, 맵 정보  
    int queue[QUEUE_SIZE][4], qs = 0, qe = 0; // 큐  
    int vn[1000][1000] = { 0, }; // 벽을 부수지 않고 방문한 적이 있는지 저장  
    int vb[1000][1000] = { 0, }; // 벽을 부수고 방문한 적이 있는지 저장
	int l, c, x, y; // 탐색시 사용할 변수  
	int eb = 0, en = 0; // 벽을 부수고/안부수고 목적지에 도달했는지 저장  
	
	// 입력  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			a[i][j] -= '0';
		}
	}
	
	// 시작 위치 큐에 넣고 탐색 시작 
	queue[qs  ][3] = 1; //벽부술 기회  
	queue[qs  ][2] = 0; //l
	queue[qs  ][1] = 0; //y
	queue[qs++][0] = 0; //x
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		c = queue[qe  ][3];
		l = queue[qe  ][2];
		y = queue[qe  ][1];
		x = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		
		// 이전 방문 확인 및 방문 여부 기록  
		if(vn[x][y] != 0 && c != 0) continue; // 전에 안부수고 방문, 현재 안부수고 재방문시 통과 
		if(vb[x][y] != 0 && c == 0) continue; // 전에 부수고 방문, 현재 부수고 재방문시 통과 
		if(c != 0) vn[x][y] = 1;
		else vb[x][y] = 1;
		
		// 목적지 도착시 탐색 종료
		// (어짜피 큐에 있는건 길이가 같거나 더 길기 때문에 벽을 부수고 갔는지는 확인 필요 없음) 
		if(x == n - 1 && y == m - 1) break;
		
		// 다음 위치 큐에 저장 
		if(x - 1 >= 0) {
			if(a[x - 1][y] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x - 1;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x - 1;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(x + 1 < n) {
			if(a[x + 1][y] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x + 1;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x + 1;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(y - 1 >= 0) {
			if(a[x][y - 1] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y - 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y - 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(y + 1 < m) {
			if(a[x][y + 1] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y + 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y + 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
	}
	
	// 출력  
	if(vb[n - 1][m - 1] == 1 || vn[n - 1][m - 1] == 1) printf("%d", l + 1);
	else printf("-1");
	
	return 0;
}
