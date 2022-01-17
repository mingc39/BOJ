#include <stdio.h>
#include <stdlib.h>

#define MEM 128

#define PQSIZE 1048576

// ========< 우선순위 큐 >======== 
long long a[PQSIZE];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// 힙 갱신
	long long t;
	int t1, t2, i = 0;
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
	long long t;
	int t1, i = l - 1;
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
// =============================== 

int **g, *size, *length;
int n, m; 
int v[32001] = {0,};

int main() {
	int a, b, c;
	int *in;
	
	// 입력  
	scanf("%d %d", &n, &m);
	g = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int*));
	length = (int*)calloc(n + 1, sizeof(int*));
	in = (int*)calloc(n + 1, sizeof(int*));
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &c, &a);
		for(int i = 1; i < c; i++) {
			scanf("%d", &b);
			
			if(size[a] == length[a]) {
				g[a] = (int*)realloc(g[a], sizeof(int) * (size[a] + MEM));
				size[a] += MEM;
			}
			
			// 입력 내용 저장 
			g[a][length[a]] = b;
			length[a]++;
			in[b]++;
			
			a = b; 
		}
	}
	
	// 들어오는 연결이 없는 정점(=먼저 방문해야 하는곳이 없는 정점)을 g[0]에 저장  
	for(int i = 1; i <= n; i++) {
		if(in[i] != 0) continue;
		
		// 저장 공간 부족시 추가 할당 
		if(size[0] == length[0]) {
			g[0] = (int*)realloc(g[0], sizeof(int) * (size[0] + MEM));
			size[0] += MEM;
		}
		
		// 입력 내용 저장 
		g[0][length[0]] = i;
		length[0]++;
		
		// 큐에 삽입
		push(i);
	}
	
	free(size); // length 있어서 size 필요없음 
	// 크기 조정  
	for(int a = 1; a <= n; a++) {
		g[a] = (int*)realloc(g[a], sizeof(int) * length[a]);
	}
	
	c = 0;
	while(l > 0) {
		int t = pop();
		v[c++] = t;
		for(int i = 0; i < length[t]; i++) {
			in[g[t][i]]--;
			if(in[g[t][i]] == 0) push(g[t][i]);
		}
	}
	
	if(c == n) for(int i = 0; i < c; i++) printf("%d\n", v[i]);
	else printf("0\n");
	
	return 0;
}
