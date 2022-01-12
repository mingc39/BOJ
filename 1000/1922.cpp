#include <stdio.h>
#include <stdlib.h>

#define MEM 128

long long a[102400];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// �� ���� 
	long long t, t1, t2, i = 0;
	//long long t;
	//int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
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
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp;
}

long long push(long long x) {
	a[l++] = x;
	// �� ���� 
	long long t, t1, i = l - 1;
	//long long t;
	//int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
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
	int tw = 0, p[10001] = {0, -1, 0,}; // �θ� ��� �ʱ�ȭ  
	int pos = 1;
	
	// ����  
	while(pos != 0) {
		// ������ Ʈ���� �߰��� ������ ���� �� Ʈ���� ���Ե��� ���� �������� ���� ������ �켱���� ť�� �߰�  
		for(int i = 0; i < length[pos]; i++) {
			if(p[g[pos][i]] == 0) pushE(w[pos][i] , pos, g[pos][i]);
		}
		
		// Ʈ���� �߰����� ���� ������ ����� ���� �� ����ġ�� �ּ��� ���� ã�� 
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
