#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 1000000

// ���ؿ��� �Ǵµ� Dev-C++���� ���������� �����ϸ� ����  
int vc[200010] = { 0, };
int vl[200010] = { 0, };
int queue[QUEUE_SIZE][2], qs = 0, qe = 0;

int main() {
	int n, k, v, c, l;
	//int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[200010] = { 0, }; // �湮����
	//int  vc[200010] = { 0, }; // �湮 ��� �� 
	//int  vl[200010] = { 0, }; // �ּ� �̵� �� 
	
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
		if(vb[c] == true) { // �̹� �湮�ߴ��� Ȯ��  
			if(l == vl[c]) vc[c]++; // ���� �湮�� ���� Ƚ���� �湮�� �� ������ �湮 ��� �� ����  
			else continue; // ���� �湮�� ���� Ƚ���� �湮�� �ƴϸ� ���  
		} else { // ó�� �湮�� ���  
			vb[c] = true; // �湮���� true  
			vc[c] = 1; // �湮 ��� ��  
			vl[c] = l; // �ּ� Ƚ��  
		}
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
	
	int m = l;
	// ť�� �����ִ°� Ȯ��
	while(qs != qe){
		if(queue[qe  ][1] != m) break; // �Ÿ��� �ּҺ��� ũ�� ������ Ȯ�� ���� 
		l = queue[qe  ][1];
		c = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) { // �̹� �湮�ߴ��� Ȯ��  
			if(l == vl[c]) vc[c]++; // ���� �湮�� ���� Ƚ���� �湮�� �� ������ �湮 ��� �� ���� 
			else continue; // ���� �湮�� ���� Ƚ���� �湮�� �ƴϸ� ��� 
		}
	}
	
	// �湮 ��� �� ���  
	printf("\n%d", vc[k]);
	
	return 0;
}
