#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MEM 128
#define PQSIZE 4

typedef struct edge{
	int weight;
	int start;
	int end;
} edge; 

int compare(const void *x, const void *y) {
	return ((edge*)x)->weight - ((edge*)y)->weight;
}

// ========< �켱���� ť >======== 
char *a;
char *tmp1 = NULL, *tmp2 = NULL;
int memSize, memUnit = 1048576;
int s = sizeof(int);
int l = 0;
int (*cmp)(const void *, const void *); // ������ ������ ����

void swap(void *x, void *y, int size) {
	memcpy(tmp2, y, size);
	memcpy(y, x, size);
	memcpy(x, tmp2, size);
} 

void* pop() {
	if(tmp1 == NULL) tmp1 = (char*)malloc(s);
	memcpy(tmp1, a, s);
	l--;
	memcpy(a, a + s * l, s);
	// �� ����
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(cmp(a + s * t1, a + s * i) < 0) { // a[t1] < a[i]
				swap(a + s * t1, a + s * i, s);
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(cmp(a + s * t1, a + s * i) < 0 && cmp(a + s * t1, a + s * t2) <= 0) { // a[t1] < a[i] && a[t1] <= a[t2]
				swap(a + s * t1, a + s * i, s);
				i = t1;
				continue;
			}
			if(cmp(a + s * t2, a + s * i) < 0 && cmp(a + s * t2, a + s * t1) < 0) { // a[t2] < a[i] && a[t2] < a[t1]
				swap(a + s * t2, a + s * i, s);
				i = t2;
				continue;
			}
		}
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp1;
}

void* push(void* x) {
	// g[a] = (int*)realloc(g[a], sizeof(int) * (size[a] + MEM));
	if(memSize < (l + 1) * s) {
		memSize += memUnit;
		a = (char*)realloc(a, memSize);
	}
	
	memcpy(a + s * l, x, s);
	l++;
	// �� ���� 
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(cmp(a + s * i, a + s * t1) < 0) { // a[t1] > a[i] -> a[i] < a[t1]
				swap(a + s * t1, a + s * i, s);
				i = t1;
				continue;
			}
		}
		// �θ� ��尡 �� ������ ���� �Ϸ�
		break; 
	}
	return x;
}

void setComparor(int (*comparor)(const void *, const void *)) {
	cmp = comparor;
}

void setSize(int size) {
	s = size;
	if(tmp1 != NULL) free(tmp1);
	if(tmp2 != NULL) free(tmp2);
	tmp1 = (char*)malloc(s);
	tmp2 = (char*)malloc(s);
}

int cmpint(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
} 

void initPriorityQueue() {
	#ifdef PQSIZE
	a = (char*)malloc(PQSIZE);
	memSize = PQSIZE;
	#else
	a = (char*)malloc(memUnit);
	memSize = memUnit;
	#endif
	setComparor(cmpint);
	setSize(sizeof(int));
}
// =============================== 

int main() {
	
	int **g, **w, *size, *length;
	// tree: Ʈ�� ���� ����
	// weight: ������ ����ġ
	// size: �ش� ������ ���Ḯ��Ʈ ũ��(�Ҵ�� �޸� ����) 
	// length: �ش� ������ ���Ḯ��Ʈ ����(���� ������ ����) 
	int a, b, c;
	int v, e; // v: ����, e: ����  
	
	// �Է�  
	scanf("%d %d", &v, &e);
	g = (int**)calloc(v + 1, sizeof(int*));
	w = (int**)calloc(v + 1, sizeof(int*));
	size = (int*)calloc(v + 1, sizeof(int*));
	length = (int*)calloc(v + 1, sizeof(int*));
	
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// ���� ���� ������ �߰� �Ҵ� 
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
		
		// �Է� ���� ���� 
		g[a][length[a]] = b;
		w[a][length[a]] = c;
		length[a]++;
		g[b][length[b]] = a;
		w[b][length[b]] = c;
		length[b]++;
	}
	
	free(size); // length �־ size �ʿ���� 
	// ũ�� ����  
	for(int a = 1; a <= v; a++) {
		g[a] = (int*)realloc(g[a], sizeof(int) * length[a]);
		w[a] = (int*)realloc(w[a], sizeof(int) * length[a]);
	}
	
	// �ʱ�ȭ  
	int weight = 0, p[100001] = {0, -1, 0,}; // �θ� ��� �ʱ�ȭ  
	int pos = 1;
	int mroad = 0;
	initPriorityQueue();
	setComparor(compare);
	setSize(sizeof(edge));
	edge* t = (edge*)malloc(sizeof(edge));
	
	// ����  
	while(pos != 0) {
		// ������ Ʈ���� �߰��� ������ ���� �� Ʈ���� ���Ե��� ���� �������� ���� ������ �켱���� ť�� �߰�  
		for(int i = 0; i < length[pos]; i++) {
			if(p[g[pos][i]] == 0) {
				t->start = pos;
				t->end = g[pos][i];
				t->weight = w[pos][i];
				push(t);
			}
		}
		
		// Ʈ���� �߰����� ���� ������ ����� ���� �� ����ġ�� �ּ��� ���� ã�� 
		pos = 0;
		while(l > 0) {
			edge* t = (edge*)pop(); 
			if(p[t->end] == 0) {
				p[t->end] = t->start;
				pos = t->end;
				weight += t->weight;
				if(mroad < t->weight) mroad = t->weight;
				break;
			}
		}
	}
	
	printf("%d", weight - mroad);
	
	return 0;
}
