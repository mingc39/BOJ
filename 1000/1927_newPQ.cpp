#include <stdio.h>
#include <stdlib.h>

#define MEM 128
#define PQSIZE 4000000

// ========< 우선순위 큐 >======== 
void* a[PQSIZE];
int l = 0;
int (*cmp)(const void *, const void *); // 왼쪽이 작으면 음수  

void* pop() {
	void* tmp = a[0];
	a[0] = a[--l];
	// 힙 갱신 
	void* t;
	int t1, t2, i = 0;
	while(i < l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // 왼쪽 노드만 있는 경우 
			if(cmp(a[t1], a[i]) < 0) { // a[t1] < a[i]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // 둘 다 있는 경우 
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
		// 더 작은 자식 노드 없으면 갱신 완료
		break; 
	}
	return tmp;
}

void* push(void* x) {
	a[l++] = x;
	// 힙 갱신 
	void* t;
	int t1, i = l - 1;
	while(i > 0) {
		// 부모 노드 인덱스 계산
		t1 = (i - 1) / 2;
		// 부모 노드 비교
		if(t1 >= 0) {
			if(cmp(a[i], a[t1]) < 0) { // a[t1] > a[i] -> a[i] < a[t1]
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// 부모 노드가 더 작으면 갱신 완료
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
