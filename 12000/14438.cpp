#include <stdio.h>

int min[262144];
int pow[22];

// 최소 구하기(현재 확인할 index 번호, 현재 index의 범위 시작, 끝, 합을 구하려는 범위의 시작, 끝) 
int getMin(int index, int istart, int iend, int rstart, int rend) {
	if(istart > rend || iend < rstart) return 2147483647; // index의 범위와 구하려는 범위가 전혀 겹치지 않는 경우  
	else if(rstart <= istart && iend <= rend) return min[index]; // index의 범위 전체가 구하려는 범위에 포함된 경우  
	else {
		int  left = getMin(index * 2    ,  istart , (istart + iend) / 2, rstart, rend);
		int right = getMin(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);
		return left <= right ? left : right;
	}
}

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
	for(int i = min[0] - 1; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			min[j] = min[2 * j] <= min[2 * j + 1] ? min[2 * j] : min[2 * j + 1];
		}
	}
	
	// 명령 수 입력  
	scanf("%d", &m);
	
	// 명령 수행  
	for(int i = 0; i < m; i++) {
		// 명령 입력  
		scanf("%d %d %d", &a, &b, &c);
		
			// 수 변경
			if(a == 1) {
				b--;
				b = b + pow[min[0]];
				min[b] = c;
				for(int j = b / 2; j > 0; j /= 2) { // 변경된 리프 노드를 자손으로 가지는 노드 값 갱신  
					min[j] = min[2 * j] <= min[2 * j + 1] ? min[2 * j] : min[2 * j + 1];
				}
			} 
			
			// 최소 인덱스 구하기 
			else if(a == 2) printf("%d\n", getMin(1, 0, pow[min[0]] - 1, b - 1, c - 1));
	}
	
	return 0;
}

