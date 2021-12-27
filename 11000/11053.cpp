#include <stdio.h>

int main() {
	int n, a[1000];
	int l[1001] = {0,};
	int t, m = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	// 맨 오른쪽부터 a[i] 오른쪽에서 시작하고 시작이 a[i]보다 크고 길이가 가장 긴 감소 부분 수열 찾기 
	l[1001] = 0;
	for(int i = n - 1; i >= 0; i--) {
		l[i] = 1;
		t = 1000;
		for(int j = n - 1; j > i; j--) {
			if(l[j] > l[t] && a[j] > a[i]) t = j;
		}
		l[i] += l[t];
		if(m < l[i]) m = l[i]; // 길이의 최대값도 같이 구하기 
	}
	
	printf("%d", m);
	
	return 0;
}
