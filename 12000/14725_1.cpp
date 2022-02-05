#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *child;
	struct node *next;
	char str[16];
} node;

void print(node* root, int level) {
	while(root != NULL) {
		for(int i = 0; i < level; i++) putchar('-');
		printf("%s\n", root->str);
		print(root->child, level + 2);
		root = root->next;
	}
} 

int main() { 
	node* root = NULL;
	int n;
	
	// ���� �κ� �� �Է�
	scanf("%d", &n);
	
	// ���� �κ� �� Ž��  
	for(int i = 0; i < n; i++) {
		// �ʱ�ȭ  
		int m;
		char str[16];
		node *cur = root;
		node **prv = &root;
		
		// Ž�� ���� �Է�  
		scanf("%d", &m);
		
		// �� �ܰ� Ž��  
		for(int j = 0; j < m; j++) {
			// �̹� �ܰ� �Է�  
			scanf("%s", str);
			 
			while(prv != NULL) {
				int cmp = -1; // �̹� ��尡 NULL�̸� �׳� �̹� ��� ��(=����Ʈ �� ��)�� ������ ��  
				if(cur != NULL) cmp = strcmp(str, cur->str);
				
				if(cmp < 0) {// �̹� ��� �տ� 
					// �� ��� ����  
					node* newNode = (node*)malloc(sizeof(node));
					newNode->next = cur; newNode->child = NULL;
					strcpy(newNode->str, str);
					
					// ���� ��� �տ� �����ֱ� 
					*prv = newNode;
					cur = newNode;
					
					prv = &(cur->child);
					cur = cur->child;
					break;
				} else if(cmp == 0) { // �̹� ��忡
					prv = &(cur->child);
					cur = cur->child;
					break;
				} else { // ���� ����
					prv = &(cur->next);
					cur = cur->next;
				}
			}
		}
	}
	
	// ���  
	print(root, 0);
	
	return 0;
}
