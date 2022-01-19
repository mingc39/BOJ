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
