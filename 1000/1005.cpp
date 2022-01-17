#include <stdio.h>
#include <stdlib.h>

#define MEM 128

#define PQSIZE 1024

// ========< �켱���� ť >======== 
long long a[PQSIZE];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// �� ����
	long long t;
	int t1, t2, i = 0;
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
	long long t;
	int t1, i = l - 1;
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
// =============================== 

int acm() {
	int n, m; 
	int a, b;
	int **g, *size, *length;
	int *in;
	int *weight, *time;
	int win;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	g = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int));
	length = (int*)calloc(n + 1, sizeof(int));
	in = (int*)calloc(n + 1, sizeof(int));
	weight = (int*)calloc(n + 1, sizeof(int));
	time = (int*)calloc(n + 1, sizeof(int));
	
	for(int i = 1; i <= n; i++) scanf("%d", &weight[i]);
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		
		// ���� ���� ������ �߰� �Ҵ� 
		if(size[a] == length[a]) {
			g[a] = (int*)realloc(g[a], sizeof(int) * (size[a] + MEM));
			size[a] += MEM;
		}
		
		// �Է� ���� ���� 
		g[a][length[a]] = b;
		length[a]++;
		in[b]++;
	}
	
	scanf("%d", &win);
	
	// ������ ������ ���� ����(=���� �湮�ؾ� �ϴ°��� ���� ����)�� g[0]�� ����  
	for(int i = 1; i <= n; i++) {
		if(in[i] != 0) continue;
		
		// ���� ���� ������ �߰� �Ҵ� 
		if(size[0] == length[0]) {
			g[0] = (int*)realloc(g[0], sizeof(int) * (size[0] + MEM));
			size[0] += MEM;
		}
		
		// �Է� ���� ���� 
		g[0][length[0]] = i;
		length[0]++;
		time[i] = weight[i];
		
		// ť�� ����
		push(i);
	}
	
	free(size); // length �־ size �ʿ���� 
	
	// ũ�� ����  
	for(int a = 0; a <= n; a++) {
		g[a] = (int*)realloc(g[a], sizeof(int) * length[a]);
	}
	
	// Ž��  
	while(l > 0) {
		int t = pop();
		for(int i = 0; i < length[t]; i++) {
			in[g[t][i]]--;
			if(time[g[t][i]] < time[t] + weight[g[t][i]]) time[g[t][i]] = time[t] + weight[g[t][i]];
			if(in[g[t][i]] == 0) push(g[t][i]);
		} 
	} 
	
	// ���  
	printf("%d\n", time[win]);
	
	// ���� �Ҵ� ��ȯ  
	for(int i = 0; i <= n; i++) free(g[i]);
	free(g);
	free(length);
	free(in);
	free(weight);
	free(time);
	/* Ž���� ť�� ��� ���� Ž�� �ߴ��ϴ� ��� ���� ������ ���� ť �������� */
	
	return 0;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) acm();
	return 0;
}
