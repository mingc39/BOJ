#include <stdio.h>
#include <memory.h>

int main() {
	int n, m, a[100][100];
	int time, cheese = 0;
	int v[100][100], s[10000][2], p;
	int i, j;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1) cheese++;
		}
	}
	
	time = 0;
	// ġ� ������ ������ �ݺ�  
	while(cheese > 0) {
		// �ʱ�ȭ  
		memset(v, 0, sizeof(int) * 10000);
		p = 0;
		
		// ���ÿ� �𼭸� �ϳ� ����  
		s[p][0] = 0;
		s[p][1] = 0;
		v[0][0] = 1;
		p++;
		
		// �𼭸��� ����� �� ����(= ġ�� ���ΰ� �ƴ� ����) Ž��  
		while(p > 0) {
			p--;
			i = s[p][0];
			j = s[p][1];
			
			if(i >= 1)
				if(a[i - 1][j] == 0 && v[i - 1][j] == 0) {
					s[p][0] = i - 1;
					s[p][1] = j;
					v[i - 1][j] = 1;
					p++;
				}
			
			if(j >= 1)
				if(a[i][j - 1] == 0 && v[i][j - 1] == 0) {
					s[p][0] = i;
					s[p][1] = j - 1;
					v[i][j - 1] = 1;
					p++;
				}
			
			if(i <= n - 2) 
				if(a[i + 1][j] == 0 && v[i + 1][j] == 0) {
					s[p][0] = i + 1;
					s[p][1] = j;
					v[i + 1][j] = 1;
					p++;
				}
			
			if(j <= m - 2)
				if(a[i][j + 1] == 0 && v[i][j + 1] == 0) {
					s[p][0] = i;
					s[p][1] = j + 1;
					v[i][j + 1] = 1;
					p++;
				}
		}
		
		// ġ�� ���ֱ�  
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(a[i][j] == 1) {
					if((a[i - 1][j] == 0 && v[i - 1][j] == 1) + (a[i + 1][j] == 0 && v[i + 1][j] == 1) + (a[i][j - 1] == 0 && v[i][j - 1] == 1)
					+ (a[i][j + 1] == 0 && v[i][j + 1] == 1) >= 2) {
						a[i][j] = 0;
						cheese--;
					}
				}
			}
		}
		
		time++;
	}
	
	// ���  
	printf("%d", time);
	
	return 0;
}
