#include <stdio.h>
#include <memory.h>

// ��Ž�� �����ε� �ð��� 2�質 �þ ��������  
// ���ؿ��� 15000�� ��� �ǰ� 10000�� ť�� �������� ����  
#define QUEUE_SIZE 100000

// �� D ����(2�� ������) -> x = rD(n)�϶� D(x) = n�̰� D(x + 5000)�� n��  
int rD(int n) {
	return n / 2;
}

// �� S ����(1���ϱ� , n = 9999�϶� 0) 
int rS(int n) {
	return n == 9999 ? 0 : n + 1;
}

// ���������� �� ĭ 
int rL(int n) {
	return n / 10 + (n % 10) * 1000;
}

// �������� �� ĭ
int rR(int n) {
	return (n * 10) % 10000 + n / 1000;
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
		queue[qs++][0] = k;
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
			if(c == n) break;
			
			// ���� ��ġ ť�� ����  
			if(c % 2 == 0) {
				queue[qs  ][2] = c;
				queue[qs  ][1] = 'D';
				queue[qs++][0] = rD(c);
				if(qs == QUEUE_SIZE) qs = 0;
				queue[qs  ][2] = c;
				queue[qs  ][1] = 'D';
				queue[qs++][0] = rD(c) + 5000;
				if(qs == QUEUE_SIZE) qs = 0;
			}
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'S';
			queue[qs++][0] = rS(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'L';
			queue[qs++][0] = rL(c);
			if(qs == QUEUE_SIZE) qs = 0;
			queue[qs  ][2] = c;
			queue[qs  ][1] = 'R';
			queue[qs++][0] = rR(c);
			if(qs == QUEUE_SIZE) qs = 0;
		}
		
		// ������ġ Ž���ؼ� ���ÿ� ����  
		c = n;
		while(po[c] != -1) {
			printf("%c" , po[c]);
			c = pv[c];
		}
		putchar('\n');
	}
	
	return 0;
}
