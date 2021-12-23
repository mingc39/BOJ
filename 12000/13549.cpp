#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l;
	int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[200010] = { 0, };
	
	// 입력 
	scanf("%d %d", &n, &k);
	
	// 시작 위치 큐에 넣고 탐색 시작  
	queue[qs  ][1] = 0;
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][1];
		c = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue; // 이미 방문했는지 확인
		vb[c] = true;
		if(c == k) break; // 동생이 있는 위치 k에 도착하면 탐색 종료
		// 다음 위치 큐에 저장 
		for(int i = c; i <= 200010 && i != 0; i *= 2) {
			queue[qs  ][1] = l;
			queue[qs++][0] = i;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c - 1 >= 0) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c - 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c + 1 <= 100000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 결과 출력  
	printf("%d", l);
	
	return 0;
}
