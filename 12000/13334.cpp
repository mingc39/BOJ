#include <stdio.h>
#include <stdlib.h>

#define PQSIZE 100000

int n, p[100000][2];

// ========< �켱���� ť >======== 
long long a[PQSIZE];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// �� ����
	long long t;
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(a[t1] < a[i] && a[t1] <= a[t2]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(a[t2] < a[i] && a[t2] < a[t1]) {
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp;
}

long long push(long long x) {
	a[l++] = x;
	// �� ���� 
	long long t;
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// �θ� ��尡 �� ������ ���� �Ϸ�
		break; 
	}
	return x;
}
// =============================== 

int cmp(const void *a, const void *b) {
	return ((int*)a)[1] - ((int*)b)[1];
}

int main() {
	int d, r = 0;
	
	// �Է� �ޱ�  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &p[i][0], &p[i][1]);
		if(p[i][0] > p[i][1]) { // ���� ���� ������������  
			d = p[i][0];
			p[i][0] = p[i][1];
			p[i][1] = d;
		}
	}
	scanf("%d", &d);
	
	// �� ���� �������� ����  
	qsort(p, n, sizeof(int) * 2, cmp);
	
	// ������� �켱���� ť�� �ְ� ���� Ȯ���ϱ�  
	for(int i = 0; i < n; i++) {
		// �켱���� ť�� �̹� ��� �ֱ�  
		push(p[i][0]); 
		// ���� ������ ���� d �ȿ� ���� ��� ���� 
		while(l > 0) {
			if(a[0] < p[i][1] - d) pop();
			else break;
		}
		// �켱���� ť�� �ִ밪 ����
		if(r < l) r = l; 
	}
	
	// ���
	printf("%d", r) ;
	
	return 0;
}
