#include <stdio.h>
#include <memory.h>

// ���ؿ��� 15000�� ��� �ǰ� 10000�� ť�� �������� ����  
#define QUEUE_SIZE 100000

// D ����(2���ϰ� ���� 4�ڸ��� ����) 
int D(int n) {
	return (n * 2) % 10000;
}

// S ����(1����, n=0�϶� 9999) 
int S(int n) {
	return n == 0 ? 9999 : n - 1;
}

// �������� �� ĭ  
int L(int n) {
	return (n * 10) % 10000 + n / 1000;
}

// ���������� �� ĭ 
int R(int n) {
	return n / 10 + (n % 10) * 1000; 
}

int main() {
	int t, n, k; // �Է¹��� �� 
	int p, c, o; // Ž���� ��� 
	int queue[QUEUE_SIZE][3], qs = 0, qe = 0; // ť!  
	int pv[10000]; // ���� ��ġ  
	char po[10000]; // ���� ������ & �湮 ����(0�̸� �̹湮) 
	
	for(scanf("%d", &t); t > 0; t--) {
		// ���� �ʱ�ȭ 
		memset(po, 0, 10000); // po�迭 ���� 0����
		qs = 0; qe = 0; // ť �ʱ�ȭ 
		
		// �� �Է� 
		scanf("%d %d", &n, &k);
		 
		// ť�� ���� ���� ���� 
		queue[qs  ][2] = -1;
		queue[qs  ][1] = -1;
		queue[qs++][0] = n;
		if(qs == QUEUE_SIZE) qs = 0;
		// Ž��  
		while(qs != qe) {
			// ť���� �ϳ� ������  
			p = queue[qe  ][2];
			o = queue[qe  ][1];
			c = queue[qe++][0];
			if(qe == QUEUE_SIZE) qe = 0;
			
			// �̹� �湮�޴��� Ȯ��  
			if(po[c] != 0) continue;
			
			// ������ġ, ���� ���� ���  
			po[c] = o;
			pv[c] = p;
			
			// k�� �����ϸ� Ž�� ����  
			if(c == k) break;
			
			// ���� ��ġ ť�� ����  
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'D';
			queue[qs++][0] = D(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'S';
			queue[qs++][0] = S(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'L';
			queue[qs++][0] = L(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'R';
			queue[qs++][0] = R(c);
			if(qs == QUEUE_SIZE) qs = 0;
		}
		
		// ������ġ Ž���ؼ� ���ÿ� ����  
		p = 0; c = k;
		while(po[c] != -1) {
			queue[p++][0] = po[c]; // �̸��� ť���� �޸𸮰� �Ʊ��� �������� ��Ȱ���Ҳ���-_- 
			c = pv[c];
		}
		while(p > 0) {
			printf("%c", queue[--p][0]);
		}
		putchar('\n');
	}
	
	return 0;
}
