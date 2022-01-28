#include <stdio.h>

// �׸� ���� ũ���� parent �迭�� parent[i] = i�� �ʱ�ȭ�ؼ� ���  

// ==========< union-find >==========
int find(int n, int* parent) { // n�� �ִ� ������ ��ǥ��(��Ʈ) ã��   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}

int unionn(int a, int b, int* parent) { // a�� �ִ� ���հ� b�� �ִ� ������ ��ġ�� (union�� ������ unionn���� �߾��)
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================

int main() {
	int n, m, t;
	int p[1000000];
	char a[1000000];
	
	// �Է� �� �θ� �迭 �ʱ�ȭ  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n * m; i++) {
		scanf(" %c", &a[i]);
		p[i] = i;
	}
	
	// ����� ĭ�� ���� �������� ��ġ��  
	for(int i = 0; i < n * m; i++) {
		if(a[i] == 'L') t = i - 1;
		else if(a[i] == 'R') t = i + 1;
		else if(a[i] == 'D') t = i + m;
		else if(a[i] == 'U') t = i - m;
		
		unionn(i, t, p);
	}
	
	// ���� ��(=��Ʈ ��� ��) ī��Ʈ  
	t = 0;
	for(int i = 0; i < n * m; i++) {
		if(i == p[i]) t++;
	}
	
	// ��� 
	printf("%d", t);
		
	return 0;
}
