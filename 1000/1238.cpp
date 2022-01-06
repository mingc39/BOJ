#include <stdio.h>
#include <stdlib.h>

#define INF 250000

// 인접리스트에서 쓸 노드  
typedef struct node{
	int v1;
	int v2;
	struct node* next;
} node;

// 최소힙
// 7662에서 가져와서 long long으로 바꿨어요  
long long pop(long long* a, int *l) {
	long long tmp = a[0];
	*l = *l - 1;
	a[0] = a[*l];
	// 힙 갱신 
	long long t, t1, t2, i = 0;
	while(i < *l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= *l) break;
		if(t2 >= *l) { // 왼쪽 노드만 있는 경우 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // 둘 다 있는 경우 
			if(a[t1] < a[i] && a[t1] <= a[t2]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(a[t2] < a[i] && a[t2] < a[t1]) {
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// 더 작은 자식 노드 없으면 갱신 완료
		break; 
	}
	return tmp;
}

long long push(long long x, long long* a, int* l) {
	a[*l] = x;
	*l = *l + 1;
	// 힙 갱신 
	long long t, t1, i = *l - 1;
	while(i > 0) {
		// 부모 노드 인덱스 계산
		t1 = (i - 1) / 2;
		// 부모 노드 비교
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// 부모 노드가 더 작으면 갱신 완료
		break; 
	}
	return x;
}

// 최소힙에서 빼서 써야하는 값 -> 정점번호
// 최소힙에서 정렬 기준인 값 -> 거리 
// 힙에 배열을 넣게 고치려면 오래걸리니까
// long long으로 고치고 거리 * 1000000 + 정점번호 로 사용 
int main() {
	int n, e, x; // 정점, 간선 개수 
	int d[1024], r[1024]; // 정점별 최소 이동 거리  
	int a1, b1, c1; // 입력용 임시 변수  
	int m; // 다익스트라에서 쓸 임시 변수  
	node** arr; // 인접리스트 배열  
	node** rev; // 인접리스트 배열  
	node* tn; // 인접 리스트에 입력값 저장, 다익스트라에서 사용할 임시 변수  
	
	// 입력  
	scanf("%d %d %d", &n, &m, &x); 
	x--; // 입력은 1부턴데 배열은 0부터임
	arr = (node**)calloc(n, sizeof(node*)); // 인접리스트 배열 동적할당 후 NULL로 초기화  
	rev = (node**)calloc(n, sizeof(node*)); // 인접리스트 배열 동적할당 후 NULL로 초기화  
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		a1--; b1--; // 입력은 1부턴데 배열은 0부터임 
		// 인접리스트에 넣을 노드 생성후 삽입  
		tn = (node*)malloc(sizeof(node));
		tn->v1 = b1;
		tn->v2 = c1;
		tn->next = arr[a1];
		arr[a1] = tn;
		// 인접리스트에 넣을 노드 생성후 삽입  
		tn = (node*)malloc(sizeof(node));
		tn->v1 = a1;
		tn->v2 = c1;
		tn->next = rev[b1];
		rev[b1] = tn;
	}
	
	// 최소 이동 거리 배열 초기화  
	for(int j = 0; j < n; j++) {
		d[j] = INF;
	}
	d[x] = 0; // 출발정점은 0으로  
	
	// 출발 정점 큐에 삽입  
	long long a[200000], lt;
	int l = 0;
	push((long long)0 * 1000000 + x, a, &l);
	
	// 다익스트라  
	while(l != 0) {
		// 거리가 최소인 정점 큐에서 꺼내기  
		lt = pop(a, &l);
		m = lt % 1000000;
		
		// 인접 정점 거리 갱신 후 거리가 달라진 정점 큐에 삽입  
		for(tn = arr[m]; tn != NULL; tn = tn->next) {
			if(d[tn->v1] > d[m] + tn->v2) {
				d[tn->v1] = d[m] + tn->v2;
				push((long long)d[tn->v1] * 1000000 + tn->v1, a, &l);
			}
		}
	}
	
	// 최소 이동 거리 배열 초기화  
	for(int j = 0; j < n; j++) {
		r[j] = INF;
	}
	r[x] = 0; // 출발정점은 0으로  
	
	// 출발 정점 큐에 삽입  
	l = 0;
	push((long long)0 * 1000000 + x, a, &l);
	
	// 다익스트라  
	while(l != 0) {
		// 거리가 최소인 정점 큐에서 꺼내기  
		lt = pop(a, &l);
		m = lt % 1000000;
		
		// 인접 정점 거리 갱신 후 거리가 달라진 정점 큐에 삽입  
		for(tn = rev[m]; tn != NULL; tn = tn->next) {
			if(r[tn->v1] > r[m] + tn->v2) {
				r[tn->v1] = r[m] + tn->v2;
				push((long long)r[tn->v1] * 1000000 + tn->v1, a, &l);
			}
		}
	}
	
	// 최댓값 계산  
	int max = 0;
	for(int i = 0; i < n; i++)
		if(d[i] < INF && r[i] < INF && max < d[i] + r[i])
			max = d[i] + r[i];
	
	// 출력  
	printf("%d", max);
	
	return 0;
}
