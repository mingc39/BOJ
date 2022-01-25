#include <stdio.h>
#include <memory.h>

int n, a[100001];
char c[100001];

void f() {
	// 입력  
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	// 초기화  
	int cnt = 0; 
	memset(c + 1, 0, sizeof(char) * n);
	
	// 1번부터 n번까지 탐색  
	for(int i = 1; i <= n; i++) {
		// 이전에 방문한 경우 통과  
		if(c[i] != 0) continue;
		
		// i부터 원하는 사람 이어서 탐색 (이전에 탐색한 사람 만나면 종료) 
		int j = i;
		while(c[j] == 0) {
			c[j] = 2;
			j = a[j];
		} 
		int k = j; // 탐색이 종료된 사람 번호  
		
		// 순환 고리 이전에 있는사 람은 팀 생성 불가로 체크 
		// ex) 1->3->4->7->6->4 에서 1, 3 
		j = i;
		while(j != k && c[j] == 2) {
			c[j] = -1;
			j = a[j];
		}
		
		// 순환 고리에 있는 사람은 팀 생성 완료로 체크 
		// ex) 1->3->4->7->6->4 에서 4, 6, 7 
		if(c[j] != 2) continue;
		j = k;
		do {
			c[j] = 1;
			cnt++;
			j = a[j];
		} while(k != j);
	}
	
	// 결과 출력  
	printf("%d\n", n - cnt);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) f();
	return 0;
}
