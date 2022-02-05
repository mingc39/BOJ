#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *child;
	struct node *next;
	char str[16];
} node;

void print(node* root, int level) {
	if(root != NULL && root->str[0] == '\0') root = root->next; // ����Ʈ�� �� ���ڿ��� �����ϸ� �� ���ڿ� �ǳʶٱ�  
	while(root != NULL) {
		for(int i = 0; i < level; i++) putchar('-');
		printf("%s\n", root->str);
		print(root->child, level + 2);
		root = root->next;
	}
} 

int main() {
	// ��Ʈ ��� �ʱ�ȭ  
	node* root = (node*)malloc(sizeof(node));
	root->str[0] = '\0';
	root->next = NULL;
	root->child = NULL;
	
	// ���� �κ� �� �Է�  
	int n;
	scanf("%d", &n);
	
	// ���� �κ� �� Ž��  
	for(int i = 0; i < n; i++) {
		// �ʱ�ȭ  
		int m;
		char str[16];
		node *cur = root, *prv;
		
		// Ž�� ���� �Է�  
		scanf("%d", &m);
		
		// �� �ܰ� Ž��  
		for(int j = 0; j < m; j++) {
			// �̹� �ܰ� �Է�  
			scanf("%s", str);
			
			prv = root; // prv�� NULL�� �Ǹ� while�� �ȵ��Ƽ� �ƹ��ų� �־���  
			while(prv != NULL) {
				int cmp = -1; // �̹� ��尡 NULL�̸� �׳� �̹� ��� ��(=����Ʈ �� ��)�� ������ ��  
				if(cur != NULL) cmp = strcmp(str, cur->str);
				
				if(cmp < 0) { // �̹� ��� �տ� 
					// �� ��� ����  
					node* newNode = (node*)malloc(sizeof(node));
					newNode->next = cur;
					strcpy(newNode->str, str);
					
					// ���� ��� �տ� �����ֱ� 
					prv->next = newNode;
					cur = newNode;
					
					// �⺻ �ڽ� ��� ����  
					newNode = (node*)malloc(sizeof(node));
					newNode->child = NULL;
					newNode->next = NULL;
					newNode->str[0] = '\0';
					cur->child = newNode;
					
					cur = cur->child;
					break;
				} else if(cmp == 0) { // �̹� ��忡
					cur = cur->child;
					break;
				} else { // ���� ����
					prv = cur;
					cur = cur->next;
				}
			}
		}
	}
	
	// ���  
	print(root, 0);
	
	return 0;
}
