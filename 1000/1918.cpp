#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char exp[128];
	int length;
	struct node* left;
	struct node* right;
} node;

// 문자열 복사  
void strcpy(char* dst, char* src, int start, int end) {
	int i;
	for(i = 0; i + start < end; i++)
		dst[i] = src[i + start];
	if(dst[i - 1] != '\0') dst[i] = '\0';
}

// 문자열 길이  
int strlen(char* str) {
	int length = 0;
	while(str[length] != '\0') length++;
	return length;
}

// 수식 분석  
void p(node* root) {
	if(root->length == 1) { // 수식 길이가 1인 경우 분석 필요 없음  
		return;
	} else {
		// 뒤에서부터 덧셈/뺄셈 연산 찾기  
		for(int i = root->length - 1; i >= 0; i--) {
			// 괄호 내부 통과 
			if(root->exp[i] == ')') {  
				int b = 1;
				for(i--; b != 0; i--) {
					if(root->exp[i] == ')') b++;
					else if(root->exp[i] == '(') b--;
				}
			}
			
			// 덧셈/뺄셈 찾은 경우  
			if(root->exp[i] == '+' || root->exp[i] == '-') {
				// 왼쪽 노드 생성  
				root->left = (node*)malloc(sizeof(node));
				strcpy(root->left->exp, root->exp, 0, i);
				root->left->length = strlen(root->left->exp);
				root->left->left = NULL;
				root->left->right = NULL;
				
				// 오른쪽 노드 생성  
				root->right = (node*)malloc(sizeof(node));
				strcpy(root->right->exp, root->exp, i + 1, root->length);
				root->right->length = strlen(root->right->exp);
				root->right->left = NULL;
				root->right->right = NULL;
				
				// 현재 노드 수식 갱신  
				root->exp[0] = root->exp[i];
				root->exp[1] = '\0';
				root->length = 1;
				
				// 자식 노드 분석  
				p(root->left);
				p(root->right);
				
				return;
			}
		}
		
		// 뒤에서부터 곱셈/나눗셈 연산 찾기  
		for(int i = root->length - 1; i >= 0; i--) {
			// 괄호 내부 통과 
			if(root->exp[i] == ')') {
				int b = 1;
				for(i--; b != 0; i--) {
					if(root->exp[i] == ')') b++;
					else if(root->exp[i] == '(') b--;
				}
			}
			
			// 곱셈/나눗셈 찾은 경우 
			if(root->exp[i] == '*' || root->exp[i] == '/') {
				// 왼쪽 노드 생성 
				root->left = (node*)malloc(sizeof(node));
				strcpy(root->left->exp, root->exp, 0, i);
				root->left->length = strlen(root->left->exp);
				root->left->left = NULL;
				root->left->right = NULL;
				
				// 오른쪽 노드 생성
				root->right = (node*)malloc(sizeof(node));
				strcpy(root->right->exp, root->exp, i + 1, root->length);
				root->right->length = strlen(root->right->exp);
				root->right->left = NULL;
				root->right->right = NULL;
				
				// 현재 노드 수식 갱신
				root->exp[0] = root->exp[i];
				root->exp[1] = '\0';
				root->length = 1;
				
				// 자식 노드 분석 
				p(root->left);
				p(root->right);
				
				return;
			}
		}
	}
	
	// 수식 전체를 감싸는 괄호가 있는 경우
	// (...)+(...)과 같은 형태는 위에서 걸러짐  
	if(root->exp[0] == '(' && root->exp[root->length - 1] == ')') {
		// 수식 전체를 감싸는 괄호 제거 
		strcpy(root->exp, root->exp, 1, root->length - 1);
		root->length = root->length - 2;
		
		// 다시 수식 분석  
		p(root);
	}
}

// 후위 순회 출력  
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
	
	// 입력  
	scanf("%s", str);
	
	// 루트 노드 생성  
	while(str[length] != '\0') length++; // 수식 길이 확인  
	root = (node*)malloc(sizeof(node)); // 루트 노드 할당  
	strcpy(root->exp, str, 0, length); // 값 저장  
	root->length = length;
	root->left = NULL;
	root->right = NULL;
	
	// 수식 분석  
	p(root);
	
	// 후위순회로 출력  
	PostOrder(root);
	
	return 0;
}
