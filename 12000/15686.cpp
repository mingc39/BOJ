#include <stdio.h>

int n, m;
int home[100][2], h = 0; // �� ��� 
int chick[13][2], c = 0; // ġŲ�� ��� 
int cdis[100][13]; // cdis[i][j]: i��° ���� j��° ġŲ���� �Ÿ� 

int func(char a[13], int l) {
	if(l == m) { // ������� ���� ġŲ���� ��� �� ��� ������ ġŲ�Ÿ� ����  
		int dis = 0;
		int min;
		for(int i = 0; i < h; i++) {
			min = 99999;
			for(int j = 0; j < m; j++) {
				if(cdis[i][a[j]] < min) min = cdis[i][a[j]];
			}
			dis += min;
		}
		return dis;
	} else { // ������� ���� ġŲ���� �� ���� �ϴ� ���  
		int dis = 0;
		int min = 2000000000;
		int t;
		if(l == 0) t = 0;
		else t = a[l - 1] + 1;
		for(int i = t; i < c; i++) { // ���� ������� ġŲ���� �ϳ��� �����غ���  
			a[l] = i;
			t = func(a, l + 1);
			if(t < min) min = t;
		}
		return min;
	}
}

int main() {
	int t;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &t);
			if(t == 1) {
				home[h][0] = i;
				home[h][1] = j;
				h++;
			} else if(t == 2) {
				chick[c][0] = i;
				chick[c][1] = j;
				c++;
			}
		}
	}
	
	// ġŲ�� <-> �� ������ �Ÿ� ���  
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) {
			cdis[i][j] = ((home[i][0] - chick[j][0]) < 0 ? -(home[i][0] - chick[j][0]) : home[i][0] - chick[j][0])
				+ ((home[i][1] - chick[j][1]) < 0 ? -(home[i][1] - chick[j][1]) : home[i][1] - chick[j][1]);
		}
	}
	
	// ġŲ�� ����� �ּ� ġŲ�Ÿ� ã�Ƽ� ���  
	char a[13];
	printf("%d", func(a, 0));
	
	return 0;
}
