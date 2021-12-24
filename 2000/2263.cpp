#include <stdio.h>
#include <stdlib.h>

// 실제 tree 생성 

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
} node;

void makeTree(node* root, int* in, int istart, int iend, int* post, int pstart, int pend) {
	// 지정된 범위에 노드가 하나인 경우 
	if(istart + 1 == iend) {
		root->value = post[pend - 1];
		root->left = NULL;
		root->right = NULL;
		return;
	}
	
	// 루트 노드 위치 찾기
	int rv = post[pend - 1];
	int i;
	for(i = 0; i + istart < iend; i++) {
		if(in[i + istart] == rv) break;
	}
	
	// 루트 노드 값 저장 및 자식 노드 할당
	root->value = rv;
	root->left = (node*)malloc(sizeof(node));
	root->right = (node*)malloc(sizeof(node));
	
	// 왼쪽 자식 노드 생성
	if(istart == istart + i) {
		// 왼쪽 자식 노드가 없는 경우
		free(root->left);
		root->left = NULL;
	} else {
		makeTree(root->left , in, istart, istart + i, post, pstart, pstart + i);
	}
	
	// 오른쪽 자식 노드 생성
	if(i + istart + 1 == iend) {
		// 오른쪽 자식 노드가 없는 경우
		free(root->right);
		root->right = NULL;
	} else {
		makeTree(root->right, in, istart + i + 1, iend, post, pstart + i, pend - 1);
	}
}

// 전위 순회 출력  
void PreOrder(node* root) {
	if(root == NULL) return;
	printf("%d ", root->value);
	PreOrder(root->left);
	PreOrder(root->right);
}

// 후위 순회 출력  
void PostOrder(node* root) {
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->value);
}

int main() {
	int n;
	int in[100000];
	int post[100000];
	node* root;
	
	// 입력
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	
	// 루트 노드 할당
	root = (node*)malloc(sizeof(node));
	// 트리 생성
	makeTree(root, in, 0, n, post, 0, n);
	
	// 출력
	PreOrder(root);
	
	return 0;
}
