#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char exp[128];
	int length;
	struct node* left;
	struct node* right;
} node;

// ���ڿ� ����  
void strcpy(char* dst, char* src, int start, int end) {
	int i;
	for(i = 0; i + start < end; i++)
		dst[i] = src[i + start];
	if(dst[i - 1] != '\0') dst[i] = '\0';
}

// ���ڿ� ����  
int strlen(char* str) {
	int length = 0;
	while(str[length] != '\0') length++;
	return length;
}

// ���� �м�  
void p(node* root) {
	if(root->length == 1) { // ���� ���̰� 1�� ��� �м� �ʿ� ����  
		return;
	} else {
		// �ڿ������� ����/���� ���� ã��  
		for(int i = root->length - 1; i >= 0; i--) {
			// ��ȣ ���� ��� 
			if(root->exp[i] == ')') {  
				int b = 1;
				for(i--; b != 0; i--) {
					if(root->exp[i] == ')') b++;
					else if(root->exp[i] == '(') b--;
				}
			}
			
			// ����/���� ã�� ���  
			if(root->exp[i] == '+' || root->exp[i] == '-') {
				// ���� ��� ����  
				root->left = (node*)malloc(sizeof(node));
				strcpy(root->left->exp, root->exp, 0, i);
				root->left->length = strlen(root->left->exp);
				root->left->left = NULL;
				root->left->right = NULL;
				
				// ������ ��� ����  
				root->right = (node*)malloc(sizeof(node));
				strcpy(root->right->exp, root->exp, i + 1, root->length);
				root->right->length = strlen(root->right->exp);
				root->right->left = NULL;
				root->right->right = NULL;
				
				// ���� ��� ���� ����  
				root->exp[0] = root->exp[i];
				root->exp[1] = '\0';
				root->length = 1;
				
				// �ڽ� ��� �м�  
				p(root->left);
				p(root->right);
				
				return;
			}
		}
		
		// �ڿ������� ����/������ ���� ã��  
		for(int i = root->length - 1; i >= 0; i--) {
			// ��ȣ ���� ��� 
			if(root->exp[i] == ')') {
				int b = 1;
				for(i--; b != 0; i--) {
					if(root->exp[i] == ')') b++;
					else if(root->exp[i] == '(') b--;
				}
			}
			
			// ����/������ ã�� ��� 
			if(root->exp[i] == '*' || root->exp[i] == '/') {
				// ���� ��� ���� 
				root->left = (node*)malloc(sizeof(node));
				strcpy(root->left->exp, root->exp, 0, i);
				root->left->length = strlen(root->left->exp);
				root->left->left = NULL;
				root->left->right = NULL;
				
				// ������ ��� ����
				root->right = (node*)malloc(sizeof(node));
				strcpy(root->right->exp, root->exp, i + 1, root->length);
				root->right->length = strlen(root->right->exp);
				root->right->left = NULL;
				root->right->right = NULL;
				
				// ���� ��� ���� ����
				root->exp[0] = root->exp[i];
				root->exp[1] = '\0';
				root->length = 1;
				
				// �ڽ� ��� �м� 
				p(root->left);
				p(root->right);
				
				return;
			}
		}
	}
	
	// ���� ��ü�� ���δ� ��ȣ�� �ִ� ���
	// (...)+(...)�� ���� ���´� ������ �ɷ���  
	if(root->exp[0] == '(' && root->exp[root->length - 1] == ')') {
		// ���� ��ü�� ���δ� ��ȣ ���� 
		strcpy(root->exp, root->exp, 1, root->length - 1);
		root->length = root->length - 2;
		
		// �ٽ� ���� �м�  
		p(root);
	}
}

// ���� ��ȸ ���  
void PostOrder(node* root) {
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c", root->exp[0]);
}

int main() {
	char str[128];
	int length = 0;
	node* root;
	
	// �Է�  
	scanf("%s", str);
	
	// ��Ʈ ��� ����  
	while(str[length] != '\0') length++; // ���� ���� Ȯ��  
	root = (node*)malloc(sizeof(node)); // ��Ʈ ��� �Ҵ�  
	strcpy(root->exp, str, 0, length); // �� ����  
	root->length = length;
	root->left = NULL;
	root->right = NULL;
	
	// ���� �м�  
	p(root);
	
	// ������ȸ�� ���  
	PostOrder(root);
	
	return 0;
}
