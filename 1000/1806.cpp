#include <stdio.h>

int a[100000], n, s;

int main() {
	int i = 0, j = 0, min = 200000, sum = 0;
	
	// 입력 및 수열의 전체 합 계산  
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	// 전체 합이 s보다 작은 경우 합이 s 이상인 연속된 부분합이 있을 수 없음  
	if(sum < s) {
		putchar('0'); // 0 출력 
		goto AAA; // 리턴 직전으로 점프  
	}
	
	sum = 0;
	// i, j 사이의 범위의 부분합 확인  
	while(i <= n && j <= n) {
		// 부분합이 s보다 커질때까지 끝부분 뒤로 늘리기  
		while(sum < s) {
			sum += a[j];
			j++;
		}
		// 부분합이 s보다 작아지기 직전까지 앞부분 뒤로 당기기  
		while(sum - a[i] >= s) {
			sum -= a[i];
			i++;
		}
		// 현재 범위의 크기가 기존보다 작으면 갱신  
		if(min > j - i) min =  j - i;
		// 다음 부분합 탐색을 위해 끝부분 뒤로 한 칸 밀기  
		sum += a[j];
		j++;
	}
	
	// 출력  
	printf("%d", min);
	
AAA:	
	return 0;
}
