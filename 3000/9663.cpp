#include <stdio.h>
//#define KING KING

// 퀸을 놓을 수 있는지 체크 
int check(int *a, int l, int x, int y) {
	for(int i = 0; i < l; i++) {
		int j = i - x;
		int k = a[i] - y;
		if(j == 0 || k == 0) return 0;
		if(j == k || j == -k) return 0;
	}
	return 1;
}

// 퀸 놓아보기 
void queen(int n, int *a, int l, int *c) {
	if(l == n) (*c)++;
	else {
		for(int i = 0; i < n; i++) {
			if(check(a, l, l, i) != 0) {
				a[l] = i;
				queen(n, a, l + 1, c);
			}
		}
	}
}

int main() {
	int n, c = 0;
	int a[15] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};
	
	scanf("%d", &n);
	#ifdef KING
	printf("%d", a[n - 1]); // 이건 킹쩔수 없는듯;;;;
	#else
	queen(n, a, 0, &c);
	printf("%d", c);
	#endif
	 
	return 0;
}
