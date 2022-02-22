#include <stdio.h> 
#include <stdlib.h>

int g[100001][3];	// ���� ��� 
int p[10001];		// p�� ���� ���� ���� �ε���  
int l[10001];		// i��° �������� ���� �ִ� �ð�  
int c[100000];		// i��° ������ ������������ ���� �ִ� �ð� ��� ���� ����  
int n, m;			// ����, ���� ����  
int s, e;			// ����, ���� ���� 

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int d(int cur) {
	// ��������� ���, �̹� Ž���� ���  
	if(cur == s || l[cur] > 0) return l[cur];
	
	// cur�� ���� ��� ���� Ȯ��  
	int i = p[cur];
	while(g[i][0] == cur) {
		// g[i]�� Ÿ�� ���� ��� �� ���� �����ɸ��� �ð� ����  
		int t = d(g[i][1]) + g[i][2];
		if(t > l[cur]) l[cur] = t;
		i++;
	}
	
	// cur���� ���µ� �ɸ��� �ִ� �ð� ��ȯ  
	return l[cur];
}

void f(int cur) {
	// cur�� ���� ��� ���� Ȯ��  
	int i = p[cur];
	while(g[i][0] == cur) {
		// g[i]�� Ÿ�� �ö� ���� �ð��� ���� ���  
		if(l[g[i][1]] + g[i][2] == l[cur] && c[i] == 0) {
			c[i] = 1;	// �ش� ������ ǥ�� �صα�  
			f(g[i][1]);	// �ش� ������ ���� ���� Ž��  
		}
		i++;
	}
}

int main() {
	// �Է� 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &g[i][1], &g[i][0], &g[i][2]);
	}
	qsort(g, m, sizeof(int) * 3, cmp);
	for(int i = 0; i < n; i++) p[i] = -1;
	for(int i = 0, prv = 0; i < m; i++) {
		if(g[i][0] != prv) {
			prv = g[i][0];
			p[prv] = i;
		}
	}
	scanf("%d %d", &s, &e);
	
	// �������� �����ϴ� ���� �����ɸ��� �ð� ���  
	printf("%d", d(e));
	
	// �������� �����ϴ� ���� �����ɸ��� ��ο� ���Ե� ���� �� ����  
	f(e);
	int cnt = 0;
	for(int i = 0; i < m; i++) cnt += c[i];
	// �������� �����ϴ� ���� �����ɸ��� ��ο� ���Ե� ���� �� ���  
	printf("\n%d", cnt);
	
	return 0;
}
