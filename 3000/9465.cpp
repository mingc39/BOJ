#include <stdio.h>

int main() {
	int t, n, s[100000][2];
	
	for(scanf("%d", &t); t > 0; t--) {
		// 입력  
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &s[i][0]);
		for(int i = 0; i < n; i++) scanf("%d", &s[i][1]);
		
		// 가장 왼쪽, 왼쪽에서 2번째 스티커
		if(1 < n) {
			s[1][0] += s[0][1];
			s[1][1] += s[0][0];
		}
		// (i, 0) 스티커를 선택하는 경우 s[i][0] + (s[i - 1][1] or s[i - 2][1])이 최대값  
		for(int i = 2; i < n; i++) {
			s[i][0] += s[i - 1][1] > s[i - 2][1] ? s[i - 1][1] : s[i - 2][1];
			s[i][1] += s[i - 1][0] > s[i - 2][0] ? s[i - 1][0] : s[i - 2][0];
		}
		
		// 출력: 최대값은 오른쪽 끝 스티커를 선택하는 경우 중 있음  
		printf("%d\n", s[n - 1][0] > s[n - 1][1] ? s[n - 1][0] : s[n - 1][1]);
	}
	
	return 0;
}
