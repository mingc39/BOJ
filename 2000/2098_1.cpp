#include <stdio.h> 

int n, w[16][16];
int a[16][1 << 16];

int f(int cur, int vst) {
	// �̹� ������� ������ �״�� ��ȯ  
	if(a[cur][vst] < 2100000000) return a[cur][vst];
	
	// �������� ���ļ� 0->i �ּҺ�� + i->cur ��� ���
	int min = 2100000000;
	for(int i = 0; i < n; i++) {
		if(i == cur || i == 0) continue;
		if(((1 << i) & vst) == 0) continue;
		if(min > f(i, vst - (1 << cur)) + w[i][cur]) min = f(i, vst - (1 << cur)) + w[i][cur];
	}
	
	// �迭�� ��� ���� �� ��ȯ 
	return a[cur][vst] = min;
}

int main() {
	// �Է�
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
			if(w[i][j] == 0) w[i][j] = 20000000;
		}
	}
	
	// �迭 �ʱ�ȭ 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < (1 << n); j++)
			a[i][j] = 2100000000;
	for(int i = 1; i < n; i++)
		a[i][(1 << i) + 1] = w[0][i];
	
	int min = 2100000000;
	for(int i = 1; i < n; i++)
		if(min > f(i, (1 << n) - 1) + w[i][0]) min = f(i, (1 << n) - 1) + w[i][0];
	
	// ��ȸ �� ��� 
	printf("%d", min);
	
	return 0;
}
