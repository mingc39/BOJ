#include <stdio.h> 
#include <stdlib.h>

//#include <algorithm>

// �׸� ���� ũ���� parent �迭�� parent[i] = i�� �ʱ�ȭ�ؼ� ���  

// ==========< union-find >==========
int find(int n, int* parent) { // n�� �ִ� ������ ��ǥ��(��Ʈ) ã��   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}
// ==================================

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}


int main() {
	int G, P, t, i;
	int n, m, k;
	int *p, *c;
	
	// n m k �Է�  
	scanf("%d %d %d", &n, &m, &k);
	
	// ���� ī�� �Է� �� ����  
	c = (int*)malloc(sizeof(int) * (m + 1));
	for(int i = 0; i < m; i++) scanf("%d", &c[i]);
	//qsort(c, m, sizeof(int), cmp); <- �̰� ������ ����  
	//std::sort(c, c + m); // qsort���� ����  
	// ======ī���� ��Ʈ====== 
	t = 0;
	for(int i = 0; i < m; i++) if(t < c[i]) t = c[i];
	p = (int*)malloc(sizeof(int) * (t + 1));
	for(int i = 1; i <= t; i++) p[i] = 0;
	for(int i = 0; i < m; i++) p[c[i]]++;
	for(int i = 1, j = 0; i <= t; i++) if(p[i] > 0) c[j++] = i;
	free(p);
	c[m] = -1;
	//for(int i = 0; i < m; i++) printf("%d ", c[i]); putchar('\n');
	
	// �θ� �迭 �ʱ�ȭ  
	p = (int*)malloc(sizeof(int) * (m + 1));
	for(i = 0; i <= m; i++) p[i] = i;
	
	// ī��  �ޱ�  
	for(i = 0; i < k; i++) {
		scanf("%d", &t); // �Է� 
		
		{ // c���� t���� ū ù ��� ã�� 
			int left = 0, right = m - 1;
			while(left < right) {
				int mid = (left + right) / 2;
				if(c[mid] < t) left = mid + 1;
				else right = mid;
			}
			if(t == c[right]) t = right + 1; // t�� ��ġ�ϴ� ���� ���� �� t�� ���� ���� �����Ƿ� �� ���� ���� ��ġ ����  
			else t = right;
		}
		if(find(t, p) == m) break; // ���� �� �ִ� ����Ʈ ������ ������ ������  
		printf("%d\n", c[find(t, p)]);
		p[find(t, p)]++; // ����Ʈ�� ����� �ޱ� 
	}
	
	return 0;
}
