#include <stdio.h>

int main() {
	int tc;
	int n, m, w;
	int e[5200][3];
	int v[500];
	int a, b, c;
	
	for(scanf("%d", &tc); tc > 0; tc--) {
		// �Է�  
		scanf("%d %d %d", &n, &m, &w);
		// ���� �Է� (�����) 
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			e[i * 2][0] = a - 1;
			e[i * 2][1] = b - 1;
			e[i * 2][2] = c;
			e[i * 2 + 1][0] = b - 1;
			e[i * 2 + 1][1] = a - 1;
			e[i * 2 + 1][2] = c;
		}
		// ����(?) �Է� (�ܹ���) 
		for(int i = m * 2; i < m * 2 + w; i++) {
			scanf("%d %d %d", &a, &b, &c);
			e[i][0] = a - 1;
			e[i][1] = b - 1;
			e[i][2] = -c;
		}
		
		// �ʱ�ȭ ���� �������  
		for(int i = 0; i < n; i++) {
			v[i] = 0;
		}
		
		// ��������  
		for(int j = 0; j < n; j++) {
			for(int i = 0; i < 2 * m + w; i++) {
				if(v[e[i][1]] > v[e[i][0]] + e[i][2]) {
					v[e[i][1]] = v[e[i][0]] + e[i][2];
				}
			}
		}
		
		// �������� Ȯ�� �� ���   
		a = 0;
		for(int i = 0; i < 2 * m + w; i++) {
			if(v[e[i][1]] > v[e[i][0]] + e[i][2]) {
				printf("YES");
				a = 1;
				break;
			}
		}
		if(a == 0) printf("NO");
        putchar('\n'); // �� �ٲٱ�  
	}
	
	return 0;
}
