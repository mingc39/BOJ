#include <stdio.h>

// ��� ��ȣ�� 1���� ����, ��� ��ȣ 0�� �������� �ʱ� ��ġ�� ������ ��Ÿ��  
int a[1001][1001];	// a[i][j]: ��� max(i, j)���� ��� ó���߰� ������1�� ��� i, ������2�� ��� j ��ġ�� ������ �̵� �Ÿ��� �ּҰ� 
int b[1001][2];		// b[i]: ��� i�� ��ġ ��ǥ   
int s[1000];		// �������� �̵��� ������ ����� ����  

// �� ��ǥ�� �Ÿ�  
int dist(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	return x + y;
}

// �� ��ǰ� �Ÿ�  
int dist2(int w1, int w2) {
	return dist(b[w1][0], b[w1][1], b[w2][0], b[w2][1]);
}

// �� ��ǰ� �� ��ǥ�� �Ÿ�  
int dist3(int w, int x, int y) {
	return dist(b[w][0], b[w][1], x, y);
}

int main() {
	int n, w;
	
	// �Է�  
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= w; i++) scanf("%d %d", &b[i][0], &b[i][1]);
	
	// �ּ� ��� Ž��  
	a[1][0] = dist3(1, 1, 1);
	a[0][1] = dist3(1, n, n);
	for(int i = 2; i <= w; i++) {
		int t;
		
		// ������1�� �̵� 
		// i - 1��° ��ǿ��� �̵��ؿ��� ���  
		for(int j = 0; j < i - 1; j++) {
			a[i][j] = a[i - 1][j] + dist2(i - 1, i);
		} 
		// 0 ~ i - 2��° ��ǿ��� �̵��ؿ��� ��� 
		t = a[0][i - 1] + dist3(i, 1, 1);
		for(int j = 1; j < i - 1; j++) {
			if(t > a[j][i - 1] + dist2(i, j)) t = a[j][i - 1] + dist2(i, j);
		}
		a[i][i - 1] = t;
		
		// ������2�� �̵� 
		// i - 1��° ��ǿ��� �̵��ؿ��� ��� 
		for(int j = 0; j < i - 1; j++) {
			a[j][i] = a[j][i - 1] + dist2(i - 1, i);
		} 
		// 0 ~ i - 2��° ��ǿ��� �̵��ؿ��� ���
		t = a[i - 1][0] + dist3(i, n, n);
		for(int j = 1; j < i - 1; j++) {
			if(t > a[i - 1][j] + dist2(i, j)) t = a[i - 1][j] + dist2(i, j);
		}
		a[i - 1][i] = t;
	}
	
	// �ּ� �̵� �Ÿ�, a �迭������ ��ġ ���ϱ�  
	int min = 999999999, x, y;
	for(int i = 0; i < w; i++) {
		if(min > a[i][w]) {
			min = a[i][w];
			x = i;
			y = w;
		}
		if(min > a[w][i]) {
			min = a[w][i];
			x = w;
			y = i;
		}
	}
	// �ּ� �̵� �Ÿ� ���  
	printf("%d", min);
	
	// � �������� �̵��ߴ��� ����  
	for(int i = 0; i < w; i++) {
		
		// ������1�� ������  
		if(x > y) {
			// �̵��� ������ ��ȣ ���  
			s[i] = 1;
			// ��� 0 ~ ���� ��ǿ��� �� ��� ����  
			if(x - 1 == y) {
				int t = a[0][x - 1] + dist3(w - i, 1, 1), p = 0;
				for(int j = 1; j < x - 1; j++) {
					if(t > a[j][x - 1] + dist2(w - i, j)) {
						t = a[j][x - 1] + dist2(w - i, j);
						p = j;
					}
				}
				x = p;
			}
			// ���� ��ǿ��� �� ���  
			else x--;
		}
		
		// ������2�� ������  
		else {
			// �̵��� ������ ��ȣ ��� 
			s[i] = 2;
			// ��� 0 ~ ���� ��ǿ��� �� ��� ���� 
			if(y - 1 == x) {
				int t = a[y - 1][0] + dist3(w - i, n, n), p = 0;
				for(int j = 1; j < y - 1; j++) {
					if(t > a[y - 1][j] + dist2(w - i, j)) {
						t = a[y - 1][j] + dist2(w - i, j);
						p = j;
					}
				}
				y = p;
			}
			// ���� ��ǿ��� �� ��� 
			else y--;
		}
		
	}
	
	// ���� ��� �������� ��� (s���� ������ �̵� ������ -> ù��° �̵� ������ ������ �����) 
	while(w) printf("\n%d", s[--w]);
	
	return 0;
}
