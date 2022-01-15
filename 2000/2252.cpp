#include <stdio.h>
#include <stdlib.h>

#define MEM 128

int **g, *size, *length;
int n, m; 
int v[32001] = {0,};
int s[32001], p = 0;

void dfs(int c) {
	if(v[c] != 0) return;
	for(int i = 0; i < length[c]; i++) {
		if(v[g[c][i]] == 0) {
			dfs(g[c][i]);
			v[g[c][i]] = 1;
		}
	}
	s[p++] = c;
}

int main() {
	int a, b;
	int *in;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	g = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int*));
	length = (int*)calloc(n + 1, sizeof(int*));
	in = (int*)calloc(n + 1, sizeof(int*));
	
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
		in[b] = 1;
	}
	
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
	}
	
	free(in);
	free(size); // length �־ size �ʿ���� 
	// ũ�� ����  
	for(int a = 1; a <= n; a++) {
		g[a] = (int*)realloc(g[a], sizeof(int) * length[a]);
	}
	
	dfs(0); // dfs Ž�� 
	
	// �������� ��� ���  
	p--;
	while(p > 0) printf("%d ", s[--p]);
	
	return 0;
}
