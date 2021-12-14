#include <stdio.h>

int a[100000], l = 0;

int pop() {
	int tmp = a[0];
	a[0] = a[--l];
	// �� ���� 
	int t, t1, t2, i = 0;
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

int push(int x) {
	a[l++] = x;
	// �� ���� 
	int t, t1, i = l - 1;
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

void print() {
	for(int i = 0; i < l; i++) printf("%2d: %4d\n", i, a[i]);
}

int main()
{
	int n, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		push(t);
	}
	
	long long sum = 0;
	int c, b;
	while(l > 1) {
		sum += push(pop() + pop());
	}
	
	printf("%lld", sum);
	
	return 0;
}
