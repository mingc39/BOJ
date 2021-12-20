#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l;
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0;
	bool vb[100] = { 0, };
	int tp[100];
	
	// ��ٸ�, �� ���� �ʱ�ȭ  
	for(int i = 0; i < 100; i++)
		tp[i] = -1;
	
	// �Է� 
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n + k; i++) {
		scanf("%d %d", &c, &v);
		tp[c - 1] = v - 1;
	}
	
	// ���� ��ġ ť�� �ְ� Ž�� ����  
	queue[qs  ][1] = 0;
	queue[qs++][0] = 0;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][1];
		c = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue; // �̹� �湮�ߴ��� Ȯ��  
		vb[c] = true;
		if(c == 99) break; // 99�� �����ϸ� Ž�� ����
		// ���� ��ġ ť�� ���� 
		for(int i = 1; i <= 6; i++) {
			if(c + 1 > 99) break;
			v = c + i;
			while(tp[v] != -1) v = tp[v];
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = v;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// ��� ���  
	printf("%d", l);
	
	return 0;
}
