#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 1000000

// Dev-C++���� ���ÿ��� �����ؼ� ����� �ű� 
int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
int l[200000][2];
int pn[100000];
int s[100001];

int cmp(const void* a, const void* b) {
	if(((int*)a)[0] == ((int*)b)[0])
		return ((int*)a)[1] - ((int*)b)[1];
	else return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
	int n;
	//int l[200000][2]; // ��� ���� ��  
	int k, v, c, t, p;
	//int queue[QUEUE_SIZE][2], qs = 0, qe = 0;
	bool vb[100000] = { 0, }; // �湮 ���� ����  
	//int s[100001]; // n��° ����� ���ἱ ������ l[k]���� �����ϴ� ��� s[n] = k
	//int pn[100000]; // pn[n]�� n��° ����� �θ� ��� ��ȣ  
	
	// �Է�  
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d", &l[2 * i][0], &l[2 * i][1]);
		l[2 * i][0] = l[2 * i][0] - 1;
		l[2 * i][1] = l[2 * i][1] - 1;
		// ��尣 ���ἱ�� ������ �����Ƿ� �ݴ� ���൵ ����  
		l[2 * i + 1][0] = l[2 * i][1];
		l[2 * i + 1][1] = l[2 * i][0];
	}
	
	// ���� Ž���� ���� ����  
	qsort(l, 2 * n - 2, sizeof(l[0]), cmp);
	
	// s�迭 �� ���� 
	t = l[0][0];
	s[t] = 0;
	for(int i = 1; i < 2 * n - 2; i++) {
		if(l[i][0] != t) {
			t = l[i][0];
			s[t] = i;
		}
	}
	s[n] = 2 * n - 2;
	
	// ���1���� Ž��  
	queue[qs  ][1] = -1;
	queue[qs++][0] =  0;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		// ť���� Ž���� ��� ������  
		p = queue[qe  ][1];
		c = queue[qe++][0];
		if(qe == QUEUE_SIZE) qe = 0;
		// �̹� �湮�� ��� �ǳʶٱ�  
		if(vb[c] == true) continue;
		vb[c] = true;
		// �θ� ��� ���  
		pn[c] = p;
		// ť�� ���� ��� ����  
		for(int i = s[c]; i < s[c + 1]; i++) {
			queue[qs  ][1] = c;
			queue[qs++][0] = l[i][1];
			if(qs == QUEUE_SIZE) qs = 0;
		}
	}
	
	// �� ��庰 �θ� ��� ��ȣ ���(��Ʈ(���1) ����) 
	for(int i = 1; i < n; i++) {
		printf("%d\n", pn[i] + 1);
	}
	
	return 0;
}
