#include <stdio.h>
#include <stdlib.h>

// ���� tree ���� 

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
} node;

void makeTree(node* root, int* in, int istart, int iend, int* post, int pstart, int pend) {
	// ������ ������ ��尡 �ϳ��� ��� 
	if(istart + 1 == iend) {
		root->value = post[pend - 1];
		root->left = NULL;
		root->right = NULL;
		return;
	}
	
	// ��Ʈ ��� ��ġ ã��
	int rv = post[pend - 1];
	int i;
	for(i = 0; i + istart < iend; i++) {
		if(in[i + istart] == rv) break;
	}
	
	// ��Ʈ ��� �� ���� �� �ڽ� ��� �Ҵ�
	root->value = rv;
	root->left = (node*)malloc(sizeof(node));
	root->right = (node*)malloc(sizeof(node));
	
	// ���� �ڽ� ��� ����
	if(istart == istart + i) {
		// ���� �ڽ� ��尡 ���� ���
		free(root->left);
		root->left = NULL;
	} else {
		makeTree(root->left , in, istart, istart + i, post, pstart, pstart + i);
	}
	
	// ������ �ڽ� ��� ����
	if(i + istart + 1 == iend) {
		// ������ �ڽ� ��尡 ���� ���
		free(root->right);
		root->right = NULL;
	} else {
		makeTree(root->right, in, istart + i + 1, iend, post, pstart + i, pend - 1);
	}
}

// ���� ��ȸ ���  
void PreOrder(node* root) {
	if(root == NULL) return;
	printf("%d ", root->value);
	PreOrder(root->left);
	PreOrder(root->right);
}

// ���� ��ȸ ���  
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
	
	// �Է�
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	
	// ��Ʈ ��� �Ҵ�
	root = (node*)malloc(sizeof(node));
	// Ʈ�� ����
	makeTree(root, in, 0, n, post, 0, n);
	
	// ���
	PreOrder(root);
	
	return 0;
}
