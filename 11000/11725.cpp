#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 1000000

// Dev-C++에서 스택영역 부족해서 여기로 옮김 
int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
int l[200000][2];
int pn[100000];
int s[100001];

int cmp(const void* a, const void* b) {
	if(((int*)a)[0] == ((int*)b)[0])
		return ((int*)a)[1] - ((int*)b)[1];
	else return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
	int n;
	//int l[200000][2]; // 노드 연결 선  
	int k, v, c, t, p;
	//int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[100000] = { 0, }; // 방문 여부 저장  
	//int s[100001]; // n번째 노드의 연결선 정보가 l[k]부터 시작하는 경우 s[n] = k
	//int pn[100000]; // pn[n]은 n번째 노드의 부모 노드 번호  
	
	// 입력  
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d", &l[2 * i][0], &l[2 * i][1]);
		l[2 * i][0] = l[2 * i][0] - 1;
		l[2 * i][1] = l[2 * i][1] - 1;
		// 노드간 연결선의 방향이 없으므로 반대 방행도 저장  
		l[2 * i + 1][0] = l[2 * i][1];
		l[2 * i + 1][1] = l[2 * i][0];
	}
	
	// 빠른 탐색을 위해 정렬  
	qsort(l, 2 * n - 2, sizeof(l[0]), cmp);
	
	// s배열 값 지정 
	t = l[0][0];
	s[t] = 0;
	for(int i = 1; i < 2 * n - 2; i++) {
		if(l[i][0] != t) {
			t = l[i][0];
			s[t] = i;
		}
	}
	s[n] = 2 * n - 2;
	
	// 노드1부터 탐색  
	queue[qs  ][1] = -1;
	queue[qs++][0] =  0;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		// 큐에서 탐색할 노드 꺼내기  
		p = queue[qe  ][1];
		c = queue[qe++][0];
		if(qe == QUEUE_SIZE) qe = 0;
		// 이미 방문한 경우 건너뛰기  
		if(vb[c] == true) continue;
		vb[c] = true;
		// 부모 노드 기록  
		pn[c] = p;
		// 큐에 다음 노드 삽입  
		for(int i = s[c]; i < s[c + 1]; i++) {
			queue[qs  ][1] = c;
			queue[qs++][0] = l[i][1];
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// 각 노드별 부모 노드 번호 출력(루트(노드1) 제외) 
	for(int i = 1; i < n; i++) {
		printf("%d\n", pn[i] + 1);
	}
	
	return 0;
}
