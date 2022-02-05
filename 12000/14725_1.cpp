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
	
	// 개미 로봇 수 입력
	scanf("%d", &n);
	
	// 개미 로봇 별 탐색  
	for(int i = 0; i < n; i++) {
		// 초기화  
		int m;
		char str[16];
		node *cur = root;
		node **prv = &root;
		
		// 탐색 길이 입력  
		scanf("%d", &m);
		
		// 각 단계 탐색  
		for(int j = 0; j < m; j++) {
			// 이번 단계 입력  
			scanf("%s", str);
			 
			while(prv != NULL) {
				int cmp = -1; // 이번 노드가 NULL이면 그냥 이번 노드 앞(=리스트 맨 끝)에 넣으면 됨  
				if(cur != NULL) cmp = strcmp(str, cur->str);
				
				if(cmp < 0) {// 이번 노드 앞에 
					// 새 노드 생성  
					node* newNode = (node*)malloc(sizeof(node));
					newNode->next = cur; newNode->child = NULL;
					strcpy(newNode->str, str);
					
					// 현재 노드 앞에 끼워넣기 
					*prv = newNode;
					cur = newNode;
					
					prv = &(cur->child);
					cur = cur->child;
					break;
				} else if(cmp == 0) { // 이번 노드에
					prv = &(cur->child);
					cur = cur->child;
					break;
				} else { // 다음 노드로
					prv = &(cur->next);
					cur = cur->next;
				}
			}
		}
	}
	
	// 출력  
	print(root, 0);
	
	return 0;
}
