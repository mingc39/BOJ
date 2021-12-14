#include <stdio.h>

int a[100000], l = 0;

int pop() {
	int tmp = a[0];
	a[0] = a[--l];
	// 힙 갱신 
	int t, t1, t2, i = 0;
	while(i < l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // 왼쪽 노드만 있는 경우 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // 둘 다 있는 경우 
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
		// 더 작은 자식 노드 없으면 갱신 완료
		break; 
	}
	return tmp;
}

int push(int x) {
	a[l++] = x;
	// 힙 갱신 
	int t, t1, i = l - 1;
	while(i > 0) {
		// 부모 노드 인덱스 계산
		t1 = (i - 1) / 2;
		// 부모 노드 비교
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
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
