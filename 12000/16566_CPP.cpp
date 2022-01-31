// C++로 제출해야함 
// c언어는 qsort가 느려서 터짐;;; 

#include <stdio.h> 
#include <stdlib.h>

#include <algorithm>

// 항목 개수 크기의 parent 배열을 parent[i] = i로 초기화해서 사용  

// ==========< union-find >==========
int find(int n, int* parent) { // n가 있는 집합의 대표값(루트) 찾기   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}
// ==================================

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}


int main() {
	int G, P, t, i;
	int n, m, k;
	int *p, *c;
	
	// n m k 입력  
	scanf("%d %d %d", &n, &m, &k);
	
	// 가진 카드 입력 및 정렬  
	c = (int*)malloc(sizeof(int) * (m + 1));
	for(int i = 0; i < m; i++) scanf("%d", &c[i]);
	//qsort(c, m, sizeof(int), cmp); <- 이게 느려서 터짐  
	std::sort(c, c + m); // qsort보다 빠름  
	c[m] = -1;
	
	// 부모 배열 초기화  
	p = (int*)malloc(sizeof(int) * (m + 1));
	for(i = 0; i <= m; i++) p[i] = i;
	
	// 카드  받기  
	for(i = 0; i < k; i++) {
		scanf("%d", &t); // 입력 
		
		{ // c에서 t보다 큰 첫 요소 찾기 
			int left = 0, right = m - 1;
			while(left < right) {
				int mid = (left + right) / 2;
				if(c[mid] < t) left = mid + 1;
				else right = mid;
			}
			if(t == c[right]) t = right + 1; // t와 일치하는 값이 있을 땐 t와 같은 값이 나오므로 그 다음 원소 위치 선택  
			else t = right;
		}
		if(find(t, p) == m) break; // 받을 수 있는 게이트 없으면 공항이 터져요  
		printf("%d\n", c[find(t, p)]);
		p[find(t, p)]++; // 게이트에 비행기 받기 
	}
	
	return 0;
}
