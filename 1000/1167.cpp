#include <stdio.h>
#include <stdlib.h>

#define MEM 128
#define QSIZE 400000

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
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c);
		scanf("%d", &a);
		while(a > 0) {
			scanf("%d", &b);
			
			// 저장 공간 부족시 추가 할당 
			if(size[c] == length[c]) {
				tree[c]   = (int*)realloc(  tree[c], sizeof(int) * (size[c] + MEM));
				weight[c] = (int*)realloc(weight[c], sizeof(int) * (size[c] + MEM));
				size[c] += MEM;
			}
			
			// 입력 내용 저장 
			tree  [c][length[c]] = a;
			weight[c][length[c]] = b; 
			length[c]++;
			
			scanf("%d", &a);
		}
		// 크기 조정  
		tree[c]   = (int*)realloc(  tree[c], sizeof(int) * length[c]);
		weight[c] = (int*)realloc(weight[c], sizeof(int) * length[c]);
	}
	free(size); // length 있어서 size 필요없음  
	
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
	qn = (int*)malloc(sizeof(int) * QSIZE);
	ql = (int*)malloc(sizeof(int) * QSIZE);
	qp = (int*)malloc(sizeof(int) * QSIZE);
	
	// 루트에서 거리가 최대인 노드 찾기  
	qn[qi] = 1;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == QSIZE) qi = 0;
	while(qi != qo) {
		// 큐에서 꺼내기  
		a = qn[qo]; // 현재 노드 
		b = ql[qo]; // 탐색 거리  
		c = qp[qo]; // 이전 노드  
		qo++;
		if(qo == QSIZE) qo = 0;
		
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
			if(qi == QSIZE) qi = 0;
		} 
	}
	
	// 큐는 위에서 이미 빈 상태 큐 초기화 안해도 됨 
	// 루트에서 거리가 최대인 노드에서 거리가 최대인 노드 찾기  
	qn[qi] = maxNod;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == QSIZE) qi = 0;
	while(qi != qo) {
		// 큐에서 꺼내기  
		a = qn[qo]; // 현재 노드 
		b = ql[qo]; // 탐색 거리  
		c = qp[qo]; // 이전 노드  
		qo++;
		if(qo == QSIZE) qo = 0;
		
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
			if(qi == QSIZE) qi = 0;
		} 
	}
	
	// 결과 출력 
	printf("%d", maxLen);
	
	return 0;
}
