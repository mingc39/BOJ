#include <stdio.h>

int main() {
	int n, t[500][500];
	
	// �Է� 
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			scanf("%d", &t[i][j]);
	
	// �ﰢ���� �� ���� ���Ͽ� �� �������� �����ö� �ִ밪 ���  
	for(int i = 1; i < n; i++) {
		t[i][0] = t[i][0] + t[i - 1][0];
		for(int j = 1; j < i; j++)
			t[i][j] = t[i - 1][j] > t[i - 1][j - 1] ? t[i - 1][j] + t[i][j] : t[i - 1][j - 1] + t[i][j];
		t[i][i] = t[i][i] + t[i - 1][i - 1];
	}
	
	// �� �Ʒ����� �ִ밪 ã�� 
	int m = 0;
	for(int i = 0; i < n; i++)
		if(m < t[n - 1][i]) m = t[n - 1][i];
	
	printf("%d", m);
	
	return 0;
}
