#include <stdio.h> 

// 항목 개수 크기의 parent 배열을 parent[i] = i로 초기화해서 사용  

// ==========< union-find >==========
int find(int n, int* parent) { // n가 있는 집합의 대표값(루트) 찾기   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}
// ==================================

int main() {
	int G, P, t, i;
	int p[100001];
	
	// 게이트, 비행기 수 입력  
	scanf("%d %d", &G, &P);
	
	// 부모 배열 초기화  
	for(i = 0; i <= G; i++) p[i] = i;
	
	// 비행기 받기  
	for(i = 0; i < P; i++) {
		scanf("%d", &t); // 입력 
		if(find(t, p) == 0) break; // 받을 수 있는 게이트 없으면 공항이 터져요  
		p[find(t, p)]--; // 게이트에 비행기 받기 
	}
	
	// 몇 번째 비행기까지 받았는지 출력  
	printf("%d", i);
	
	return 0;
}
