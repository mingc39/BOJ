#include <stdio.h>
#include <stdlib.h>

#define MEM 128

long long a[102400];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// 힙 갱신 
	long long t, t1, t2, i = 0;
	//long long t;
	//int t1, t2, i = 0;
	while(i < l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // 왼쪽 노드만 있는 경우 
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

long long push(long long x) {
	a[l++] = x;
	// 힙 갱신 
	long long t, t1, i = l - 1;
	//long long t;
	//int t1, i = l - 1;
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

void pushE(int w, int v1, int v2) {
	push((long long) (w + 1000000) * 100000000 + (v1 - 1) * 10000 + (v2 - 1));
}

int getMinWeight() {
	return a[0] / 100000000 - 1000000;
}

int getMinV1() {
	return a[0] / 10000 % 10000 + 1;
}

int getMinV2() {
	return a[0] % 10000 + 1;
}

int main() {
	int **g, **w, *size, *length;
	// tree: 트리 연결 정보
	// weight: 간선별 가중치
	// size: 해당 간선의 연결리스트 크기(할당된 메모리 기준) 
	// length: 해당 간선의 연결리스트 길이(실제 데이터 기준) 
	int a, b, c;
	int v, e; // v: 정점, e: 간선  
	
	// 입력  
	scanf("%d %d", &v, &e);
	g = (int**)calloc(v + 1, sizeof(int*));
	w = (int**)calloc(v + 1, sizeof(int*));
	size = (int*)calloc(v + 1, sizeof(int*));
	length = (int*)calloc(v + 1, sizeof(int*));
	
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// 저장 공간 부족시 추가 할당 
		if(size[a] == length[a]) {
			g[a] = (int*)realloc(g[a], sizeof(int) * (size[a] + MEM));
			w[a] = (int*)realloc(w[a], sizeof(int) * (size[a] + MEM));
			size[a] += MEM;
		}
		if(size[b] == length[b]) {
			g[b] = (int*)realloc(g[b], sizeof(int) * (size[b] + MEM));
			w[b] = (int*)realloc(w[b], sizeof(int) * (size[b] + MEM));
			size[b] += MEM;
		}
		
		// 입력 내용 저장 
		g[a][length[a]] = b;
		w[a][length[a]] = c;
		length[a]++;
		g[b][length[b]] = a;
		w[b][length[b]] = c;
		length[b]++;
	}
	
	free(size); // length 있어서 size 필요없음 
	// 크기 조정  
	for(int a = 1; a <= v; a++) {
		g[a] = (int*)realloc(g[a], sizeof(int) * length[a]);
		w[a] = (int*)realloc(w[a], sizeof(int) * length[a]);
	}
	
	// 초기화  
	int tw = 0, p[10001] = {0, -1, 0,}; // 부모 노드 초기화  
	int pos = 1;
	
	// 프림  
	while(pos != 0) {
		// 직전에 트리에 추가된 정점의 간선 중 트리에 포함되지 않은 정점으로 가는 간선을 우선순위 큐에 추가  
		for(int i = 0; i < length[pos]; i++) {
			if(p[g[pos][i]] == 0) pushE(w[pos][i] , pos, g[pos][i]);
		}
		
		// 트리에 추가되지 않은 정점과 연결된 간선 중 가중치가 최소인 간선 찾기 
		int weight, v1, v2;
		pos = 0;
		while(l > 0) {
			weight = getMinWeight();
			v1 = getMinV1();
			v2 = getMinV2();
			pop(); 
			if(p[v2] == 0) {
				p[v2] = v1;
				pos = v2;
				tw += weight;
				break;
			}
		}
	}
	
	printf("%d", tw);
	
	return 0;
}
