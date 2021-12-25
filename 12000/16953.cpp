#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, c, l;
	int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	
	scanf("%d %d", &n, &k);
	 
	queue[qs  ][1] = 0; // 시작 지점 큐에 삽입  
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][1];
		c = queue[qe++][0]; // 큐에서 하나 꺼내기  
		if(qe == QUEUE_SIZE) qe = 0;
		if(c > k) continue; // 줄어드는 연산이 없으므로 k보다 큰 건 볼필요도 엄슴  
		if(c == k) { // k에 도착하면 탐색 종료
			printf("%d", l + 1);
			return 0;
		} 
		// 다음 위치 큐에 저장 
		if(c <= 500000000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c <= 99999999) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 10 + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	printf("-1");
	
	return 0;
}
