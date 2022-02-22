#include <stdio.h>

int arr[2097152];
int pow[22];

// 사탕 수 변경  
void addCandy(int flavor, int number) {
	flavor = flavor + pow[arr[0]]; // 수를 변경할 리프 노드 위치 구하기  
	arr[flavor] += number; // 리프 노드 값 변경 
	for(int i = flavor / 2; i > 0; i /= 2) { // 변경된 리프 노드를 자손으로 가지는 노드 값 갱신  
		arr[i] = arr[2 * i] + arr[2 * i + 1];
	} 
}

// n번째 사탕 찾아서 꺼내기  
int getCandy(int priority, int index, int level) {
	// 리프 노드에 도달한 경우  
	if(level == arr[0]) { 
		// 사탕 수 -1 해주고 맛 반환 
		addCandy(index - pow[arr[0]], -1);
		return index - pow[arr[0]];
	}
	
	// 자식 노드 탐색  
	if(priority > arr[index * 2]) { // (현재 우선 순위 > 왼쪽 노드에 포함된 사탕 개수) 인 경우 오른쪽으로 진행  
		return getCandy(priority - arr[index * 2], index * 2 + 1, level + 1);
	} else { // (현재 우선 순위 <= 왼쪽 노드에 포함된 사탕 개수) 인 경우 왼쪽으로 진행
		return getCandy(priority, index * 2, level + 1);
	}
}

int main() {
	// 인덱스 계산용 2의 제곱 미리 구하기  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// n, m, k값 입력 
	scanf("%d", &n);
	
	// 세그먼트 트리 깊이 구하기  
	arr[0] = 20;
	
	// 명령 수행  
	while(n--) {
		// 명령 입력  
		scanf("%d", &a);
		
		if(a == 2) {  
			// 사탕 추가 
			scanf("%d %d", &b, &c);
			//b--; // 인덱스는 0부터 시작, 입력은 1부터 시작  
			addCandy(b, c);
			
		} else if(a == 1) { 
			// 사탕 구하기 
			scanf("%d", &b);
			printf("%d\n", getCandy(b, 1, 0));
		}
	}
	
	return 0;
}
