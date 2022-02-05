#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *child;
	struct node *next;
	char str[16];
} node;

void print(node* root, int level) {
	if(root != NULL && root->str[0] == '\0') root = root->next; // 리스트가 빈 문자열로 시작하면 빈 문자열 건너뛰기  
	while(root != NULL) {
		for(int i = 0; i < level; i++) putchar('-');
		printf("%s\n", root->str);
		print(root->child, level + 2);
		root = root->next;
	}
} 

int main() {
	// 루트 노드 초기화  
	node* root = (node*)malloc(sizeof(node));
	root->str[0] = '\0';
	root->next = NULL;
	root->child = NULL;
	
	// 개미 로봇 수 입력  
	int n;
	scanf("%d", &n);
	
	// 개미 로봇 별 탐색  
	for(int i = 0; i < n; i++) {
		// 초기화  
		int m;
		char str[16];
		node *cur = root, *prv;
		
		// 탐색 길이 입력  
		scanf("%d", &m);
		
		// 각 단계 탐색  
		for(int j = 0; j < m; j++) {
			// 이번 단계 입력  
			scanf("%s", str);
			
			prv = root; // prv가 NULL이 되면 while이 안돌아서 아무거나 넣어줌  
			while(prv != NULL) {
				int cmp = -1; // 이번 노드가 NULL이면 그냥 이번 노드 앞(=리스트 맨 끝)에 넣으면 됨  
				if(cur != NULL) cmp = strcmp(str, cur->str);
				
				if(cmp < 0) { // 이번 노드 앞에 
					// 새 노드 생성  
					node* newNode = (node*)malloc(sizeof(node));
					newNode->next = cur;
					strcpy(newNode->str, str);
					
					// 현재 노드 앞에 끼워넣기 
					prv->next = newNode;
					cur = newNode;
					
					// 기본 자식 노드 생성  
					newNode = (node*)malloc(sizeof(node));
					newNode->child = NULL;
					newNode->next = NULL;
					newNode->str[0] = '\0';
					cur->child = newNode;
					
					cur = cur->child;
					break;
				} else if(cmp == 0) { // 이번 노드에
					cur = cur->child;
					break;
				} else { // 다음 노드로
					prv = cur;
					cur = cur->next;
				}
			}
		}
	}
	
	// 출력  
	print(root, 0);
	
	return 0;
}
