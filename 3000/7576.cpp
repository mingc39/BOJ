#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int n, m, t[1000][1000];

int queue[QUEUE_SIZE][2], qs = 0, qe = 0;

// ���� ���� �丶�� 
int bfs() {
	//printf("\n%2d %2d %2d\n", qs - qe, qs, qe);
	//for(int i = qe; i < qs; i++) printf("\t%2d: %d,%d\n", i, queue[i][0], queue[i][1]);
	
	// �� ������ ������ Ž�� ����  
	if(qs == qe) return 0;
	int c = 0;
	for(int i = qe; i < qs; i++) {
		if(t[queue[i][0]][queue[i][1]] == 0) c = 1;
	}
	if(c == 0) return 0;
	
	// ť�� �ִ� �丶�並 �;��ٰ� ó�����ְ� �ֺ� �丶�並 ť�� ����  
	for(int s = qs; qe != s; qe++) {
		if(qe == QUEUE_SIZE) qe = 0;
		if(t[queue[qe][0]][queue[qe][1]] != 0) continue;
		t[queue[qe][0]][queue[qe][1]] = 1;
		if(queue[qe][0] - 1 >= 0) 
			if(t[queue[qe][0] - 1][queue[qe][1]] == 0) {
				queue[qs][0] = queue[qe][0] - 1;
				queue[qs][1] = queue[qe][1];
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][1] - 1 >= 0) 
			if(t[queue[qe][0]][queue[qe][1] - 1] == 0) {
				queue[qs][0] = queue[qe][0];
				queue[qs][1] = queue[qe][1] - 1;
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][0] + 1 < n)
			if(t[queue[qe][0] + 1][queue[qe][1]] == 0) {
				queue[qs][0] = queue[qe][0] + 1;
				queue[qs][1] = queue[qe][1];
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
		if(queue[qe][1] + 1 < m)
			if(t[queue[qe][0]][queue[qe][1] + 1] == 0) {
				queue[qs][0] = queue[qe][0];
				queue[qs][1] = queue[qe][1] + 1;
				qs++;
				if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// ���� Ž��  
	return bfs() + 1;
}

int main() {
	int x, y, l, g = 1, s = 100000000;
	
	// �Է� 
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &t[i][j]);
			if(t[i][j] == 1) {
				queue[qs  ][0] = i;
				queue[qs++][1] = j;
				t[i][j] = 0;
			}
			if(t[i][j] != -1) g = 0;
		}
	}
	
	// �丶�䰡 ������ �� �����ŷ���(?)  
	if(g == 1) {
		printf("0");
		return 0;
	}
	
	// �丶�䰡 �ʹµ� �󸶳� �ɸ����� Ž��  
	int r = bfs() - 1;
	
	// ������ �丶�䰡 ���������� -1 ���  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(t[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	
	// ��� �� ��  
	printf("%d", r);
	
	return 0;
}
