#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, v, c, l, p;
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0;
	int vp[100010] = { 0, }; //���� ��ġ
	bool vb[100010] = { 0, }; // �湮 ����
	
	// �Է� 
	scanf("%d %d", &n, &k);
	
	// ���� ��ġ ť�� �ְ� Ž�� ����  
	queue[qs  ][2] = -1;
	queue[qs  ][1] = 0;
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		p = queue[qe  ][2];
		l = queue[qe  ][1];
		c = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue; // �̹� �湮�ߴ��� Ȯ��  
		vb[c] = true;
		vp[c] = p; // ���� ��ġ ���� 
		if(c == k) break; // ������ �ִ� ��ġ k�� �����ϸ� Ž�� ����
		// ���� ��ġ ť�� ���� 
		if(c - 1 >= 0) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c - 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c + 1 <= 100000) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c * 2 <= 100000) {
			queue[qs  ][2] = c;
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// ��� ���  
	printf("%d\n", l);
	
	// ������ġ Ž���ؼ� ���ÿ� ����  
	p = 0; c = k;
	queue[p++][0] = c; // �� ���� ����  
	while(vp[c] != -1) {
		queue[p++][0] = vp[c]; // �̸��� ť���� �޸𸮰� �Ʊ��� �������� ��Ȱ���Ҳ���-_- 
		c = vp[c];
	}
	// �̵� ���� ���  
	while(p > 0) {
		printf("%d ", queue[--p][0]);
	}
	
	return 0;
}
