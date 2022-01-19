#include <stdio.h>
#include <math.h>

int p[300000] = {1, 2, 3, 0, } , n = 283150, l = 3;

int prime(int k) {
	// 이미 찾은 소수면 출력  
	if(k < l) return p[k];
	// 아직 안찾은 소수면 찾기 
	int i = p[l - 1] + 2;
	int c = 1;
	while(k >= l) {
		c = 1;
		for(int j = 1; p[j] <= sqrt(i); j++) {
			if(i % p[j] == 0) {
				c = 0;
				break;
			}
		}
		if(c != 0) {
			p[l++] = i;
		}
		i += 2;
	}
	return p[k];
}

int main() {
	int i = 0, j = 0, cnt = 0, sum = 0, s;
	
	// 입력  
	scanf("%d", &s);
	
	// i, j 사이의 범위의 부분합 확인  
	while(i <= n && j <= n) {
		// i 번째 소수가 s보다 크면 더 이상 탐색할 필요 없음 
		if(prime(i) > s) break; 
		// 부분합이 s보다 크거나 같을 때까지 끝부분 뒤로 늘리기  
		while(sum <= s) {
			sum += prime(j);
			j++;
		}
		// 부분합이 s보다 작아지기 직전까지 앞부분 뒤로 당기기  
		while(sum - prime(i) >= s) {
			sum -= prime(i);
			i++;
		}
		// 현재 범위의 합이 원하는 수와 같으면 카운트  
		if(sum == s) cnt++;
		// 다음 부분합 탐색을 위해 끝부분 뒤로 한 칸 밀기  
		sum += prime(j);
		j++;
	}
	
	// 출력  
	printf("%d", cnt);
		
	return 0;
}
