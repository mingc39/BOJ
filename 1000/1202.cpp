#include <stdio.h>
#include <stdlib.h>

#define PQSIZE 300000

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

int cmp(const void *i, const void *j) {
	int* t1 = (int*)i;
	int* t2 = (int*)j;
	if(t1[0] == t2[0]) return t1[1] - t2[1];
	else return t1[0] - t2[0];
}

int cmp2(const void *i, const void *j) {
	return *((int*)i) - *((int*)j);
}

int bag[300000];
int jw[300001][2];

int main() {
	int n, k;
	
	// �Է�  
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		int m, v;
		scanf("%d %d", &jw[i][0], &jw[i][1]);
	}
	for(int i = 0; i < k; i++) {
		scanf("%d", &bag[i]);
	}
	
	// ����  
	qsort(bag, k, sizeof(int), cmp2);
	qsort(jw, n, 2 * sizeof(int), cmp);
	jw[n][0] = 99999999; jw[n][1] = 99999999;
	
	// ���� ���� ������� �� �� �ִ� ���� ��ġ�� ���� ������ �ִ´�  
	long long value = 0;
	for(int i = 0, j = 0; i < k; i++) {
		int m = jw[i][0];
		int v = jw[i][1];
		for(; jw[j][0] <= bag[i]; j++) push(-jw[j][1]);
		if(l > 0) value -= pop(); // ���� �� �ִ� ������ ���� �� ����  
	}
	
	// ���  
	printf("%lld", value);
	
	return 0;
}
