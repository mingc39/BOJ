#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l;
	int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[200010] = { 0, };
	
	// �Է� 
	scanf("%d %d", &n, &k);
	
	// ���� ��ġ ť�� �ְ� Ž�� ����  
	queue[qs  ][1] = 0;
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][1];
		c = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue; // �̹� �湮�ߴ��� Ȯ��  
		vb[c] = true;
		if(c == k) break; // ������ �ִ� ��ġ k�� �����ϸ� Ž�� ����
		// ���� ��ġ ť�� ���� 
		if(c - 1 >= 0) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c - 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c + 1 <= 100000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c * 2 <= 100000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// ��� ���  
	printf("%d", l);
	
	return 0;
}
