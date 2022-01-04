#include <stdio.h>
#include <stdlib.h>

#define mem 128
#define qsize 40000

int main() {
	int n, **tree, **weight, *size, *length;
	// tree: 트리 연결 정보
	// weight: 간선별 가중치
	// size: 해당 간선의 연결리스트 크기(할당된 메모리 기준) 
	// length: 해당 간선의 연결리스트 길이(실제 데이터 기준) 
	int a, b, c;
	
	// 입력  
	scanf("%d", &n);
	tree = (int**)calloc(n + 1, sizeof(int*));
	weight = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int*));
	length = (int*)calloc(n + 1, sizeof(int*));
	for(int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// 저장 공간 부족시 추가 할당 
		if(size[a] == length[a]) {
			tree[a]   = (int*)realloc(  tree[a], sizeof(int) * (size[a] + mem));
			weight[a] = (int*)realloc(weight[a], sizeof(int) * (size[a] + mem));
			size[a] += mem;
		}
		if(size[b] == length[b]) {
			tree[b]   = (int*)realloc(  tree[b], sizeof(int) * (size[b] + mem));
			weight[b] = (int*)realloc(weight[b], sizeof(int) * (size[b] + mem));
			size[b] += mem;
		}
		
		// 입력 내용 저장 
		tree  [a][length[a]] = b;
		weight[a][length[a]] = c;
		length[a]++;
		tree  [b][length[b]] = a;
		weight[b][length[b]] = c;
		length[b]++;
	}
	free(size); // length 있어서 size 필요없음 
	// 크기 조정  
	for(int a = 1; a <= n; a++) {
		tree[a]   = (int*)realloc(  tree[a], sizeof(int) * length[a]);
		weight[a] = (int*)realloc(weight[a], sizeof(int) * length[a]);
	}
	
	// 입력받은 트리 데이터 확인 
	#ifdef DEBUG
	for(int i = 1; i <= n; i++) {
		printf("%d:", i);
		for(int j = 0; j < length[i]; j++) printf(" (%2d %2d)", tree[i][j], weight[i][j]);
		putchar('\n');
	}
	#endif
	
	// 큐 초기화  
	int *qn, *ql, *qp, qi = 0, qo = 0;
	int maxLen = 0, maxNod;
	qn = (int*)malloc(sizeof(int) * qsize);
	ql = (int*)malloc(sizeof(int) * qsize);
	qp = (int*)malloc(sizeof(int) * qsize);
	
	// 루트에서 거리가 최대인 노드 찾기  
	qn[qi] = 1;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == qsize) qi = 0;
	while(qi != qo) {
		// 큐에서 꺼내기  
		a = qn[qo]; // 현재 노드 
		b = ql[qo]; // 탐색 거리  
		c = qp[qo]; // 이전 노드  
		qo++;
		if(qo == qsize) qo = 0;
		
		// 리프노드면 최대거리 저장 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// 다음 노드 큐에 삽입
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == qsize) qi = 0;
		} 
	}
	
	// 큐는 위에서 이미 빈 상태 큐 초기화 안해도 됨
	// 루트에서 거리가 최대인 노드에서 거리가 최대인 노드 찾기  
	qn[qi] = maxNod;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == qsize) qi = 0;
	while(qi != qo) {
		// 큐에서 꺼내기  
		a = qn[qo]; // 현재 노드 
		b = ql[qo]; // 탐색 거리  
		c = qp[qo]; // 이전 노드  
		qo++;
		if(qo == qsize) qo = 0;
		
		// 리프노드면 최대거리 저장 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// 다음 노드 큐에 삽입
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == qsize) qi = 0;
		} 
	}
	
	// 결과 출력 
	printf("%d", maxLen);
	
	return 0;
}
