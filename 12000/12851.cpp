#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 1000000

// 백준에선 되는데 Dev-C++에선 지역변수로 선언하면 뻑남  
int vc[200010] = { 0, };
int vl[200010] = { 0, };
int queue[QUEUE_SIZE][2], qs = 0, qe = 0;

int main() {
	int n, k, v, c, l;
	//int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[200010] = { 0, }; // 방문여부
	//int  vc[200010] = { 0, }; // 방문 방법 수 
	//int  vl[200010] = { 0, }; // 최소 이동 수 
	
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
		if(vb[c] == true) { // 이미 방문했는지 확인  
			if(l == vl[c]) vc[c]++; // 이전 방문과 같은 횟수로 방문할 수 있으면 방문 방법 수 증가  
			else continue; // 이전 방문과 같은 횟수의 방문이 아니면 통과  
		} else { // 처음 방문한 경우  
			vb[c] = true; // 방문여부 true  
			vc[c] = 1; // 방문 방법 수  
			vl[c] = l; // 최소 횟수  
		}
		if(c == k) break; // 동생이 있는 위치 k에 도착하면 탐색 종료
		// 다음 위치 큐에 저장 
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
		if(c * 2 <= 100000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 결과 출력  
	printf("%d", l);
	
	int m = l;
	// 큐에 남아있는거 확인
	while(qs != qe){
		if(queue[qe  ][1] != m) break; // 거리가 최소보다 크면 남은거 확인 종료 
		l = queue[qe  ][1];
		c = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) { // 이미 방문했는지 확인  
			if(l == vl[c]) vc[c]++; // 이전 방문과 같은 횟수로 방문할 수 있으면 방문 방법 수 증가 
			else continue; // 이전 방문과 같은 횟수의 방문이 아니면 통과 
		}
	}
	
	// 방문 방법 수 출력  
	printf("\n%d", vc[k]);
	
	return 0;
}
