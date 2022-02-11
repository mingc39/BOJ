#include <stdio.h>

int min[262144];
int pow[22];

int main() {
	// 인덱스 계산용 2의 제곱 미리 구하기  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// 수열 길이 입력 
	scanf("%d", &n);
	
	// 세그먼트 트리 깊이 구하기  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	min[0] = a;
	
	// 주어진 수를 입력받아 리프 노드로 넣기  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%d", &c);
		min[a + b] = c;
	}
	for(; b < a; b++) { // 남는 리프 노드 0으로 채우기  
		min[a + b] = 2147483647;
	}
	
	// 세그먼트 트리 생성(리프 노드 위로 만들어 올라가기) 
	if(min[0] - 1 >= 0) {
		for(int j = pow[min[0] - 1]; j < pow[min[0]]; j++) {
			min[j] = min[2 * j] <= min[2 * j + 1] ? 2 * j : 2 * j + 1;
		}
	}
	for(int i = min[0] - 2; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
		}
	}
	
	// 명령 수 입력  
	scanf("%d", &m);
	
	// 명령 수행  
	for(int i = 0; i < m; i++) {
		// 명령 입력  
		scanf("%d", &a);
		
			// 수 변경
			if(a == 1) {
				scanf("%d %d", &b, &c);
				b--;
				b = b + pow[min[0]];
				min[b] = c;
				if(b / 2 > 0) {
					min[b / 2] = min[2 * (b / 2)] <= min[2 * (b / 2) + 1] ? 2 * (b / 2) : 2 * (b / 2) + 1;
				}
				for(int j = b / 4; j > 0; j /= 2) { // 변경된 리프 노드를 자손으로 가지는 노드 값 갱신  
					min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
				}
			} 
			
			// 최소 인덱스 구하기 
			else if(a == 2) printf("%d\n", min[1] - pow[min[0]] + 1);
	}
	
	return 0;
}

