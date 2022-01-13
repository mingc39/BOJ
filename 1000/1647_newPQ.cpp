#include <stdio.h>
#include <stdlib.h>

#define MEM 128
#define PQSIZE 4000000

typedef struct edge{
	int weight;
	int start;
	int end;
} edge; 

int compare(const void *x, const void *y) {
	return ((edge*)x)->weight - ((edge*)y)->weight;
}

// ========< �켱���� ť >======== 
void* a[PQSIZE];
int l = 0;
int (*cmp)(const void *, const void *); // ������ ������ ����  

void* pop() {
	void* tmp = a[0];
	a[0] = a[--l];
	// �� ���� 
	void* t;
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(cmp(a[t1], a[i]) < 0) { // a[t1] < a[i]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(cmp(a[t1], a[i]) < 0 && cmp(a[t1], a[t2]) <= 0) { // a[t1] < a[i] && a[t1] <= a[t2]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(cmp(a[t2], a[i]) < 0 && cmp(a[t2], a[t1]) < 0) { // a[t2] < a[i] && a[t2] < a[t1]
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp;
}

void* push(void* x) {
	a[l++] = x;
	// �� ���� 
	void* t;
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(cmp(a[i], a[t1]) < 0) { // a[t1] > a[i] -> a[i] < a[t1]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
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
	setComparor(compare);
	
	// ����  
	while(pos != 0) {
		// ������ Ʈ���� �߰��� ������ ���� �� Ʈ���� ���Ե��� ���� �������� ���� ������ �켱���� ť�� �߰�  
		for(int i = 0; i < length[pos]; i++) {
			if(p[g[pos][i]] == 0) {
				edge* t = (edge*)malloc(sizeof(edge));
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
				free(t);
				break;
			}
			free(t);
		}
	}
	
	printf("%d", weight - mroad);
	
	return 0;
}
