#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 100000

int main() {
	int n, k, c, l;
	int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	
	scanf("%d %d", &n, &k);
	 
	queue[qs  ][1] = 0; // ���� ���� ť�� ����  
	queue[qs++][0] = n;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		l = queue[qe  ][1];
		c = queue[qe++][0]; // ť���� �ϳ� ������  
		if(qe == QUEUE_SIZE) qe = 0;
		if(c > k) continue; // �پ��� ������ �����Ƿ� k���� ū �� ���ʿ䵵 ����  
		if(c == k) { // k�� �����ϸ� Ž�� ����
			printf("%d", l + 1);
			return 0;
		} 
		// ���� ��ġ ť�� ���� 
		if(c <= 500000000) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 2;
			if(qs == QUEUE_SIZE) qs = 0;
		}
		if(c <= 99999999) {
			queue[qs  ][1] = l + 1;
			queue[qs++][0] = c * 10 + 1;
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	printf("-1");
	
	return 0;
}
