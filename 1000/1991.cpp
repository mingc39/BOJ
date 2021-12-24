#include <stdio.h>
#include <stdlib.h>

// 전위 순회 출력  
void PreOrder(int tree[26][2], int root) {
	if(root == -1) return;
	printf("%c", root + 'A');
	PreOrder(tree, tree[root][0]);
	PreOrder(tree, tree[root][1]);
}

// 중위 순회 출력  
void InOrder(int tree[26][2], int root) {
	if(root == -1) return;
	InOrder(tree, tree[root][0]);
	printf("%c", root + 'A');
	InOrder(tree, tree[root][1]);
}

// 후위 순회 출력  
void PostOrder(int tree[26][2], int root) {
	if(root == -1) return;
	PostOrder(tree, tree[root][0]);
	PostOrder(tree, tree[root][1]);
	printf("%c", root + 'A');
}

int main() {
	int n;
	int tree[26][2];
	char a, b, c;
	
	// 입력 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		if(b != '.') tree[a - 'A'][0] = b - 'A';
		else tree[a - 'A'][0] = -1;
		if(c != '.') tree[a - 'A'][1] = c - 'A';
		else tree[a - 'A'][1] = -1;
	}
	
	// 지정된 순회법으로 출력
	PreOrder(tree, 0);
	putchar('\n');
	InOrder(tree, 0);
	putchar('\n');
	PostOrder(tree, 0);
	
	return 0;
}
