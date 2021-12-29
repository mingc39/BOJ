#include <stdio.h>
#define QUEUE_SIZE 100000

int main() {
	// �޸� �Ҵ� ���ؼ� ������ ������ ���������� �ű⼼��  
	int n, m, a[1000][1000]; // �� ũ��, �� ����  
    int queue[QUEUE_SIZE][4], qs = 0, qe = 0; // ť  
    int vn[1000][1000] = { 0, }; // ���� �μ��� �ʰ� �湮�� ���� �ִ��� ����  
    int vb[1000][1000] = { 0, }; // ���� �μ��� �湮�� ���� �ִ��� ����
	int l, c, x, y; // Ž���� ����� ����  
	int eb = 0, en = 0; // ���� �μ���/�Ⱥμ��� �������� �����ߴ��� ����  
	
	// �Է�  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			a[i][j] -= '0';
		}
	}
	
	// ���� ��ġ ť�� �ְ� Ž�� ���� 
	queue[qs  ][3] = 1; //���μ� ��ȸ  
	queue[qs  ][2] = 0; //l
	queue[qs  ][1] = 0; //y
	queue[qs++][0] = 0; //x
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		c = queue[qe  ][3];
		l = queue[qe  ][2];
		y = queue[qe  ][1];
		x = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		
		// ���� �湮 Ȯ�� �� �湮 ���� ���  
		if(vn[x][y] != 0 && c != 0) continue; // ���� �Ⱥμ��� �湮, ���� �Ⱥμ��� ��湮�� ��� 
		if(vb[x][y] != 0 && c == 0) continue; // ���� �μ��� �湮, ���� �μ��� ��湮�� ��� 
		if(c != 0) vn[x][y] = 1;
		else vb[x][y] = 1;
		
		// ������ ������ Ž�� ����
		// (��¥�� ť�� �ִ°� ���̰� ���ų� �� ��� ������ ���� �μ��� �������� Ȯ�� �ʿ� ����) 
		if(x == n - 1 && y == m - 1) break;
		
		// ���� ��ġ ť�� ���� 
		if(x - 1 >= 0) {
			if(a[x - 1][y] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x - 1;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x - 1;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(x + 1 < n) {
			if(a[x + 1][y] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x + 1;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y;
				queue[qs++][0] = x + 1;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(y - 1 >= 0) {
			if(a[x][y - 1] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y - 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y - 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
		if(y + 1 < m) {
			if(a[x][y + 1] == 0) {
				queue[qs  ][3] = c;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y + 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			} else if(c > 0) {
				queue[qs  ][3] = c - 1;
				queue[qs  ][2] = l + 1;
				queue[qs  ][1] = y + 1;
				queue[qs++][0] = x;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
	}
	
	// ���  
	if(vb[n - 1][m - 1] == 1 || vn[n - 1][m - 1] == 1) printf("%d", l + 1);
	else printf("-1");
	
	return 0;
}
