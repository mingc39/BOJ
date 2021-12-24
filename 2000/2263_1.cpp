#include <stdio.h>
#include <stdlib.h>

// tree 생성 없이 바로 출력

void makeTree(int* in, int istart, int iend, int* post, int pstart, int pend) {
	// 지정된 범위에 노드가 하나인 경우 
	if(istart + 1 == iend) {
		printf("%d ", post[pend - 1]);
		return;
	}
	
	// 루트 노드 위치 찾기
	int rv = post[pend - 1];
	int i;
	for(i = 0; i + istart < iend; i++) {
		if(in[i + istart] == rv) break;
	}
	
	// 루트 노드 출력 
	printf("%d ", rv);
	
	// 왼쪽 자식 노드 생성
	if(istart == istart + i) {
	} else {
		makeTree(in, istart, istart + i, post, pstart, pstart + i);
	}
	
	// 오른쪽 자식 노드 생성
	if(i + istart + 1 == iend) {
	} else {
		makeTree(in, istart + i + 1, iend, post, pstart + i, pend - 1);
	}
}

int main() {
	int n;
	int in[100000];
	int post[100000];
	
	// 입력
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	
	// 출력 
	makeTree( in, 0, n, post, 0, n);
	
	return 0;
}
