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

typedef struct line{
	int x1, y1;
	int x2, y2;
} line;

int f(line l1, line l2) {
	long long a, b, c, d;
	a = (long long) (l1.x2 - l1.x1) * (l2.y1 - l1.y1) - (long long) (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
	b = (long long) (l1.x2 - l1.x1) * (l2.y2 - l1.y1) - (long long) (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
	c = (long long) (l2.x2 - l2.x1) * (l1.y1 - l2.y1) - (long long) (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
	d = (long long) (l2.x2 - l2.x1) * (l1.y2 - l2.y1) - (long long) (l1.x2 - l2.x1) * (l2.y2 - l2.y1);
	
	if(a > 0 && b > 0 || a < 0 && b < 0) return 0; // ����2�� ����1�� ���ʿ� �ִ� ���
	else if(c > 0 && d > 0 || c < 0 && d < 0) return 0; // ����1�� ����2�� ���ʿ� �ִ� ���  
	else if(a == 0 && b == 0 && c == 0 && d == 0) { // �� ������ ���� ���� ���� ���   
		if(l1.x1 == l1.x2 && l1.x2 == l2.x1 && l2.x1 == l2.x2) { // y�� ���� 
			if(l1.y1 > l2.y1 && l1.y1 > l2.y2 && l1.y2 > l2.y1 && l1.y2 > l2.y2) return 0;
			else if(l2.y1 > l1.y1 && l2.y1 > l1.y2 && l2.y2 > l1.y1 && l2.y2 > l1.y2) return 0;
			else return 1;
		} else { // x�� ����, �밢��  
			if(l1.x1 > l2.x1 && l1.x1 > l2.x2 && l1.x2 > l2.x1 && l1.x2 > l2.x2) return 0;
			else if(l2.x1 > l1.x1 && l2.x1 > l1.x2 && l2.x2 > l1.x1 && l2.x2 > l1.x2) return 0;
			else return 1;
		}
	} else return 1;
}

int main() {
	int n, p[3000], c[3000] = {0,};
	line lines[3000];
	
	// ���� ���� �Է�  
	scanf("%d", &n);
	
	// �θ� �迭 �ʱ�ȭ 
	for(int i = 0; i < n; i++) p[i] = i;
	
	// ���� �Է�  
	for(int i = 0; i < n; i++) scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
	
	// �� ������ �����ϴ��� Ȯ�� �� �����ϸ� ������  
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(f(lines[i], lines[j])) unionn(i, j, p);
		}
	}
	
	// ���պ� ���� ���� ����  
	for(int i = 0; i < n; i++) c[find(i, p)]++;
	
	// ���� ������ ���� ū ������ ũ�� ���ϱ�  
	int max = 0, grp = 0;
	for(int i = 0; i < n; i++) {
		if(max < c[i]) max = c[i];
		if(c[i] > 0) grp++;
	}
	
	// ���  
	printf("%d\n%d", grp, max);
	
	return 0;
}
