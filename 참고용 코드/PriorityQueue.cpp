/*
�ּ����� ����� �켱���� ť
�ּ� ���� initPriorityQueue() ȣ���ؼ� �����Ҵ�, �ʱ�ȭ ����
setSize�� setComparor�� ����Ϸ��� �ڷ����̳� �� ���� ���� 
define PQSIZE�� ���� ũ�� ���� ����
PQSIZE�� define���� ������ 1048576����Ʈ�� �ʱ�ȭ 
���� �뷮 ������ 1048576����Ʈ �߰��ؼ� ���Ҵ�  
*/
#include <stdlib.h>
#include <memory.h>

#define PQSIZE 1048576

// ========< �켱���� ť >======== 
char *a;
char *tmp1 = NULL, *tmp2 = NULL;
int memSize, memUnit = 1048576;
int s = sizeof(int);
int l = 0;
int (*cmp)(const void *, const void *); // ������ ������ ����

void swap(void *x, void *y, int size) {
	memcpy(tmp2, y, size);
	memcpy(y, x, size);
	memcpy(x, tmp2, size);
} 

void* pop() {
	if(tmp1 == NULL) tmp1 = (char*)malloc(s);
	memcpy(tmp1, a, s);
	l--;
	memcpy(a, a + s * l, s);
	// �� ����
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(cmp(a + s * t1, a + s * i) < 0) { // a[t1] < a[i]
				swap(a + s * t1, a + s * i, s);
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(cmp(a + s * t1, a + s * i) < 0 && cmp(a + s * t1, a + s * t2) <= 0) { // a[t1] < a[i] && a[t1] <= a[t2]
				swap(a + s * t1, a + s * i, s);
				i = t1;
				continue;
			}
			if(cmp(a + s * t2, a + s * i) < 0 && cmp(a + s * t2, a + s * t1) < 0) { // a[t2] < a[i] && a[t2] < a[t1]
				swap(a + s * t2, a + s * i, s);
				i = t2;
				continue;
			}
		}
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp1;
}

void* push(void* x) {
	// g[a] = (int*)realloc(g[a], sizeof(int) * (size[a] + MEM));
	if(memSize < (l + 1) * s) {
		memSize += memUnit;
		a = (char*)realloc(a, memSize);
	}
	
	memcpy(a + s * l, x, s);
	l++;
	// �� ���� 
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(cmp(a + s * i, a + s * t1) < 0) { // a[t1] > a[i] -> a[i] < a[t1]
				swap(a + s * t1, a + s * i, s);
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

void setSize(int size) {
	s = size;
	if(tmp1 != NULL) free(tmp1);
	if(tmp2 != NULL) free(tmp2);
	tmp1 = (char*)malloc(s);
	tmp2 = (char*)malloc(s);
}

int cmpint(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
} 

void initPriorityQueue() {
	#ifdef PQSIZE
	a = (char*)malloc(PQSIZE);
	memSize = PQSIZE;
	#else
	a = (char*)malloc(memUnit);
	memSize = memUnit;
	#endif
	setComparor(cmpint);
	setSize(sizeof(int));
}
// =============================== 
