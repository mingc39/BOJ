#include <stdio.h>

int arr[1025][1025] = {0,};

int main() {
	int n, m;
	int k;
	int x1, y1, x2, y2;
	
	// �Է� ������ ǥ �Է�  
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	// arr[i][j]�� (1, 1)���� (i, j)������ �� ����  
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	
	// ���� ���� �Է� �� ��� ��� ���  
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--;
		printf("%d\n", arr[x2][y2] - arr[x1][y2] - arr[x2][y1] + arr[x1][y1]);
	}
	
	return 0;
}
