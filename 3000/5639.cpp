#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	node* left;
	node* right;
} node;

// ���� ��ȸ ���  
void PostOrder(node* root) {
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d\n", root->value);
}

int main(void) {
	node* root = NULL; // Ʈ�� ��Ʈ  
	node** t; // �� ��� ���� ��ġ Ž���� �ӽ� ����  
	int n; // Ʈ���� ��� ����  
	
	while(scanf("%d", &n) != EOF) { // ������ ������ �ݺ��Է� �ޱ�  
		// ���� ��ġ Ž��  
		t = &root;
		while(*t != NULL) {
			if((*t)->value > n) t = &((*t)->left);
			else t = &((*t)->right);
		}
		// �� ��� ����  
		*t = (node*)malloc(sizeof(node));
		(*t)->value = n;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}
	
	// ������ȸ�� ���  
	PostOrder(root);
	
	return 0;
}
