#include <stdio.h>
#include <stdlib.h>

#define MEM 128
#define PQSIZE 4000000

// ========< �켱���� ť >======== 
void* a[PQSIZE];
int l = 0;
int (*cmp)(const void *, const void *); // ������ ������ ����  

void* pop() {
	void* tmp = a[0];
	a[0] = a[--l];
	// �� ���� 
	void* t;
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(cmp(a[t1], a[i]) < 0) { // a[t1] < a[i]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(cmp(a[t1], a[i]) < 0 && cmp(a[t1], a[t2]) <= 0) { // a[t1] < a[i] && a[t1] <= a[t2]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(cmp(a[t2], a[i]) < 0 && cmp(a[t2], a[t1]) < 0) { // a[t2] < a[i] && a[t2] < a[t1]
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

void* push(void* x) {
	a[l++] = x;
	// �� ���� 
	void* t;
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(cmp(a[i], a[t1]) < 0) { // a[t1] > a[i] -> a[i] < a[t1]
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

void setComparor(int (*comparor)(const void *, const void *)) {
	cmp = comparor;
}
// =============================== 

int compare(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
}

int main() {
	setComparor(compare);
	
	int n, x, *t;
	scanf("%d", &n);
	while(n-- > 0) {
		scanf("%d", &x);
		if(x == 0) {
			if(l == 0) printf("0\n");
			else {
				t = (int*)pop();
				printf("%d\n", *t);
				free(t);
			}
		} else {
			t = (int*)malloc(sizeof(int));
			*t = x;
			push(t);
		}
	}
	
	return 0;
}
