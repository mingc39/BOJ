#include <stdio.h>

long long arr[2097152];
long long pow[22];

// 합 구하기(현재 확인할 index 번호, 현재 index의 범위 시작, 끝, 합을 구하려는 범위의 시작, 끝) 
long long sum(int index, int istart, int iend, int rstart, int rend) { 
	if(istart > rend || iend < rstart) return 0; // index의 범위와 구하려는 범위가 전혀 겹치지 않는 경우  
	else if(rstart <= istart && iend <= rend) return arr[index]; // index의 범위 전체가 구하려는 범위에 포함된 경우  
	else return sum(index * 2    ,  istart , (istart + iend) / 2, rstart, rend) + // index의 범위 일부만 구하려는 범위에 포함된 경우   
				sum(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);  // 자식 노드 탐색  
}

int main() {
	// 인덱스 계산용 2의 제곱 미리 구하기  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	long long a, b, c;
	
	// n, m, k값 입력 
	scanf("%d %d %d", &n, &m, &k);
	
	// 세그먼트 트리 깊이 구하기  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	arr[0] = a;
	
	// 주어진 수를 입력받아 리프 노드로 넣기  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%lld", &c);
		arr[a + b] = c;
	}
	for(; b < a; b++) arr[a + b] = 0; // 남는 리프 노드 0으로 채우기  
	
	// 세그먼트 트리 생성(리프 노드 위로 만들어 올라가기) 
	for(int i = arr[0] - 1; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			arr[j] = arr[2 * j] + arr[2 * j + 1];
		}
	}
	
	// 명령 수행  
	for(int i = 0; i < m + k; i++) {
		// 명령 입력  
		scanf("%lld %lld %lld", &a, &b, &c);
		
		if(a == 1) {  
			// 수 변경
			b--; // 인덱스는 0부터 시작, 입력은 1부터 시작  
			b = b + pow[arr[0]]; // 수를 변경할 리프 노드 위치 구하기  
			arr[b] = c; // 리프 노드 값 변경  
			for(int j = b / 2; j > 0; j /= 2) { // 변경된 리프 노드를 자손으로 가지는 노드 값 갱신  
				arr[j] = arr[2 * j] + arr[2 * j + 1];
			}
			
		} else if(a == 2) { 
			// 합 구하기 
			printf("%lld\n", sum(1, 0, pow[arr[0]] - 1, b - 1, c - 1));
		}
	}
	
	return 0;
}
