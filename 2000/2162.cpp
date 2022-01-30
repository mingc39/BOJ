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

typedef struct line{
	int x1, y1;
	int x2, y2;
} line;

int f(line l1, line l2) {
	long long a, b, c, d;
	a = (long long) (l1.x2 - l1.x1) * (l2.y1 - l1.y1) - (long long) (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
	b = (long long) (l1.x2 - l1.x1) * (l2.y2 - l1.y1) - (long long) (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
	c = (long long) (l2.x2 - l2.x1) * (l1.y1 - l2.y1) - (long long) (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
	d = (long long) (l2.x2 - l2.x1) * (l1.y2 - l2.y1) - (long long) (l1.x2 - l2.x1) * (l2.y2 - l2.y1);
	
	if(a > 0 && b > 0 || a < 0 && b < 0) return 0; // 선분2가 직선1의 한쪽에 있는 경우
	else if(c > 0 && d > 0 || c < 0 && d < 0) return 0; // 선분1이 직선2의 한쪽에 있는 경우  
	else if(a == 0 && b == 0 && c == 0 && d == 0) { // 두 선분이 같은 직선 위인 경우   
		if(l1.x1 == l1.x2 && l1.x2 == l2.x1 && l2.x1 == l2.x2) { // y축 평행 
			if(l1.y1 > l2.y1 && l1.y1 > l2.y2 && l1.y2 > l2.y1 && l1.y2 > l2.y2) return 0;
			else if(l2.y1 > l1.y1 && l2.y1 > l1.y2 && l2.y2 > l1.y1 && l2.y2 > l1.y2) return 0;
			else return 1;
		} else { // x축 평행, 대각선  
			if(l1.x1 > l2.x1 && l1.x1 > l2.x2 && l1.x2 > l2.x1 && l1.x2 > l2.x2) return 0;
			else if(l2.x1 > l1.x1 && l2.x1 > l1.x2 && l2.x2 > l1.x1 && l2.x2 > l1.x2) return 0;
			else return 1;
		}
	} else return 1;
}

int main() {
	int n, p[3000], c[3000] = {0,};
	line lines[3000];
	
	// 선분 개수 입력  
	scanf("%d", &n);
	
	// 부모 배열 초기화 
	for(int i = 0; i < n; i++) p[i] = i;
	
	// 선분 입력  
	for(int i = 0; i < n; i++) scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
	
	// 두 선분이 교차하는지 확인 후 교차하면 합집합  
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(f(lines[i], lines[j])) unionn(i, j, p);
		}
	}
	
	// 집합별 원소 개수 세기  
	for(int i = 0; i < n; i++) c[find(i, p)]++;
	
	// 집합 개수와 가장 큰 집합의 크기 구하기  
	int max = 0, grp = 0;
	for(int i = 0; i < n; i++) {
		if(max < c[i]) max = c[i];
		if(c[i] > 0) grp++;
	}
	
	// 출력  
	printf("%d\n%d", grp, max);
	
	return 0;
}
