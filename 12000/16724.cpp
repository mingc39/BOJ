#include <stdio.h>

// 항목 개수 크기의 parent 배열을 parent[i] = i로 초기화해서 사용  

// ==========< union-find >==========
int find(int n, int* parent) { // n가 있는 집합의 대표값(루트) 찾기   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}

int unionn(int a, int b, int* parent) { // a가 있는 집합과 b가 있는 집합을 합치기 (union은 예약어라 unionn으로 했어요)
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================

int main() {
	int n, m, t;
	int p[1000000];
	char a[1000000];
	
	// 입력 및 부모 배열 초기화  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n * m; i++) {
		scanf(" %c", &a[i]);
		p[i] = i;
	}
	
	// 연결된 칸과 같은 구역으로 합치기  
	for(int i = 0; i < n * m; i++) {
		if(a[i] == 'L') t = i - 1;
		else if(a[i] == 'R') t = i + 1;
		else if(a[i] == 'D') t = i + m;
		else if(a[i] == 'U') t = i - m;
		
		unionn(i, t, p);
	}
	
	// 구역 수(=루트 노드 수) 카운트  
	t = 0;
	for(int i = 0; i < n * m; i++) {
		if(i == p[i]) t++;
	}
	
	// 출력 
	printf("%d", t);
		
	return 0;
}
