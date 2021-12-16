#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 1024

int main() {
	int n, m, v, a, b, c;
	bool l[1000][1000] = {0,};
	bool vd[1000] = {0,};
	int stack[STACK_SIZE], se = 0;
	scanf("%d %d", &n, &m);
	v--;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		l[a][b] = 1;
		l[b][a] = 1;
	}
	
	int cnt = 0;
	// �湮������ ���� ���� ã�� 
	v = -1;
	for(int i = 0; i < n; i++) {
		if(vd[i] == false) {
			v = i;
			break;
		}
	}
	// �湮������ ���� ������ �ִٸ� DFS�� ���� ����� �������� ã�� �湮
	// �湮������ ���� ������ ���ٸ� Ž�� �Ϸ� 
	while(v != -1) {
		cnt++;
		// DFS
		stack[se++] = v;
		while(se != 0) {
			c = stack[--se];
			if(vd[c] == true) continue;
			vd[c] = true;
			for(int i = n - 1; i >= 0; i--) {
				if(l[c][i] == true && vd[i] == false) {
					stack[se++] = i;
				}
			}
		}
		// DFS ��=================================
		// �湮������ ���� ���� ã��
		v = -1;
		for(int i = 0; i < n; i++) {
			if(vd[i] == false) {
				v = i;
				break;
			}
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
