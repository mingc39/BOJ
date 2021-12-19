#include <stdio.h>
#include <memory.h>

// 역탐색 버전인데 시간이 2배나 늘어남 ㄷㄷㄷㄷ  
// 백준에서 15000은 통과 되고 10000은 큐가 가득차서 뻑남  
#define QUEUE_SIZE 100000

// 역 D 연산(2로 나누기) -> x = rD(n)일때 D(x) = n이고 D(x + 5000)도 n임  
int rD(int n) {
	return n / 2;
}

// 역 S 연산(1더하기 , n = 9999일땐 0) 
int rS(int n) {
	return n == 9999 ? 0 : n + 1;
}

// 오른쪽으로 한 칸 
int rL(int n) {
	return n / 10 + (n % 10) * 1000;
}

// 왼쪽으로 한 칸
int rR(int n) {
	return (n * 10) % 10000 + n / 1000;
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
		queue[qs++][0] = k;
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
			if(c == n) break;
			
			// 다음 위치 큐에 저장  
			if(c % 2 == 0) {
				queue[qs  ][2] = c;
				queue[qs  ][1] = 'D';
				queue[qs++][0] = rD(c);
				if(qs == QUEUE_SIZE) qs = 0;
				queue[qs  ][2] = c;
				queue[qs  ][1] = 'D';
				queue[qs++][0] = rD(c) + 5000;
				if(qs == QUEUE_SIZE) qs = 0;
			}
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'S';
			queue[qs++][0] = rS(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'L';
			queue[qs++][0] = rL(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'R';
			queue[qs++][0] = rR(c);
			if(qs == QUEUE_SIZE) qs = 0;
		}
		
		// 이전위치 탐색해서 스택에 삽입  
		c = n;
		while(po[c] != -1) {
			printf("%c" , po[c]);
			c = pv[c];
		}
		putchar('\n');
	}
	
	return 0;
}
