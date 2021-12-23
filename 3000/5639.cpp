#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	node* left;
	node* right;
} node;

// 후위 순회 출력  
void PostOrder(node* root) {
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d\n", root->value);
}

int main(void) {
	node* root = NULL; // 트리 루트  
	node** t; // 새 노드 삽입 위치 탐색용 임시 변수  
	int n; // 트리의 노드 개수  
	
	while(scanf("%d", &n) != EOF) { // 파일의 끝까지 반복입력 받기  
		// 삽입 위치 탐색  
		t = &root;
		while(*t != NULL) {
			if((*t)->value > n) t = &((*t)->left);
			else t = &((*t)->right);
		}
		// 새 노드 삽입  
		*t = (node*)malloc(sizeof(node));
		(*t)->value = n;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}
	
	// 후위순회로 출력  
	PostOrder(root);
	
	return 0;
}
