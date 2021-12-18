#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int n, m, t[1000][1000];

int queue[QUEUE_SIZE][2], qs = 0, qe = 0;

// 오늘 썩을 토마토 
int bfs() {
	//printf("\n%2d %2d %2d\n", qs - qe, qs, qe);
	//for(int i = qe; i < qs; i++) printf("\t%2d: %d,%d\n", i, queue[i][0], queue[i][1]);
	
	// 더 익을게 없으면 탐색 종료  
	if(qs == qe) return 0;
	int c = 0;
	for(int i = qe; i < qs; i++) {
		if(t[queue[i][0]][queue[i][1]] == 0) c = 1;
	}
	if(c == 0) return 0;
	
	// 큐에 있는 토마토를 익었다고 처리해주고 주변 토마토를 큐에 삽입  
	for(int s = qs; qe != s; qe++) {
		if(qe == QUEUE_SIZE) qe = 0;
		if(t[queue[qe][0]][queue[qe][1]] != 0) continue;
		t[queue[qe][0]][queue[qe][1]] = 1;
		if(queue[qe][0] - 1 >= 0) 
			if(t[queue[qe][0] - 1][queue[qe][1]] == 0) {
				queue[qs][0] = queue[qe][0] - 1;
				queue[qs][1] = queue[qe][1];
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][1] - 1 >= 0) 
			if(t[queue[qe][0]][queue[qe][1] - 1] == 0) {
				queue[qs][0] = queue[qe][0];
				queue[qs][1] = queue[qe][1] - 1;
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][0] + 1 < n)
			if(t[queue[qe][0] + 1][queue[qe][1]] == 0) {
				queue[qs][0] = queue[qe][0] + 1;
				queue[qs][1] = queue[qe][1];
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][1] + 1 < m)
			if(t[queue[qe][0]][queue[qe][1] + 1] == 0) {
				queue[qs][0] = queue[qe][0];
				queue[qs][1] = queue[qe][1] + 1;
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 다음 탐색  
	return bfs() + 1;
}

int main() {
	int x, y, l, g = 1, s = 100000000;
	
	// 입력 
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &t[i][j]);
			if(t[i][j] == 1) {
				queue[qs  ][0] = i;
				queue[qs++][1] = j;
				t[i][j] = 0;
			}
			if(t[i][j] != -1) g = 0;
		}
	}
	
	// 토마토가 없으면 다 익은거래요(?)  
	if(g == 1) {
		printf("0");
		return 0;
	}
	
	// 토마토가 익는데 얼마나 걸리는지 탐색  
	int r = bfs() - 1;
	
	// 안익은 토마토가 남아있으면 -1 출력  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(t[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	
	// 결과 출 력  
	printf("%d", r);
	
	return 0;
}
