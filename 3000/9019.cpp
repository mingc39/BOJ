#include <stdio.h>
#include <memory.h>

// 백준에서 15000은 통과 되고 10000은 큐가 가득차서 뻑남  
#define QUEUE_SIZE 100000

// D 연산(2배하고 뒤의 4자리만 저장) 
int D(int n) {
	return (n * 2) % 10000;
}

// S 연산(1빼기, n=0일땐 9999) 
int S(int n) {
	return n == 0 ? 9999 : n - 1;
}

// 왼쪽으로 한 칸  
int L(int n) {
	return (n * 10) % 10000 + n / 1000;
}

// 오른쪽으로 한 칸 
int R(int n) {
	return n / 10 + (n % 10) * 1000; 
}

int main() {
	int t, n, k; // 입력받을 값 
	int p, c, o; // 탐색시 사용 
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0; // 큐!  
	int pv[10000]; // 이전 위치  
	char po[10000]; // 이전 연산자 & 방문 여부(0이면 미방문) 
	
	for(scanf("%d", &t); t > 0; t--) {
		// 변수 초기화 
		memset(po, 0, 10000); // po배열 전부 0으로
		qs = 0; qe = 0; // 큐 초기화 
		
		// 값 입력 
		scanf("%d %d", &n, &k);
		 
		// 큐에 시작 지점 삽입 
		queue[qs  ][2] = -1;
		queue[qs  ][1] = -1;
		queue[qs++][0] = n;
		if(qs == QUEUE_SIZE) qs = 0;
		// 탐색  
		while(qs != qe) {
			// 큐에서 하나 꺼내기  
			p = queue[qe  ][2];
			o = queue[qe  ][1];
			c = queue[qe++][0];
			if(qe == QUEUE_SIZE) qe = 0;
			
			// 이미 방문햇는지 확인  
			if(po[c] != 0) continue;
			
			// 이전위치, 이전 연산 기록  
			po[c] = o;
			pv[c] = p;
			
			// k에 도착하면 탐색 종료  
			if(c == k) break;
			
			// 다음 위치 큐에 저장  
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'D';
			queue[qs++][0] = D(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'S';
			queue[qs++][0] = S(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'L';
			queue[qs++][0] = L(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'R';
			queue[qs++][0] = R(c);
			if(qs == QUEUE_SIZE) qs = 0;
		}
		
		// 이전위치 탐색해서 스택에 삽입  
		p = 0; c = k;
		while(po[c] != -1) {
			queue[p++][0] = po[c]; // 이름은 큐지만 메모리가 아까우니 스택으로 재활용할꺼임-_- 
			c = pv[c];
		}
		while(p > 0) {
			printf("%c", queue[--p][0]);
		}
		putchar('\n');
	}
	
	return 0;
}
