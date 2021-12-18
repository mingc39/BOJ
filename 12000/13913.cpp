#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l, p;
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0;
	int vp[100010] = { 0, }; //이전 위치
	bool vb[100010] = { 0, }; // 방문 여부
	
	// 입력 
	scanf("%d %d", &n, &k);
	
	// 시작 위치 큐에 넣고 탐색 시작  
	queue[qs  ][2] = -1;
	queue[qs  ][1] = 0;
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		p = queue[qe  ][2];
		l = queue[qe  ][1];
		c = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue; // 이미 방문했는지 확인  
		vb[c] = true;
		vp[c] = p; // 이전 위치 저장 
		if(c == k) break; // 동생이 있는 위치 k에 도착하면 탐색 종료
		// 다음 위치 큐에 저장 
		if(c - 1 >= 0) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c - 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c + 1 <= 100000) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c * 2 <= 100000) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 결과 출력  
	printf("%d\n", l);
	
	// 이전위치 탐색해서 스택에 삽입  
	p = 0; c = k;
	queue[p++][0] = c; // 끝 지점 삽입  
	while(vp[c] != -1) {
		queue[p++][0] = vp[c]; // 이름은 큐지만 메모리가 아까우니 스택으로 재활용할꺼임-_- 
		c = vp[c];
	}
	// 이동 과정 출력  
	while(p > 0) {
		printf("%d ", queue[--p][0]);
	}
	
	return 0;
}
