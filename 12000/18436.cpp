#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	struct node* left, * right;
	int value, start, end;
} Node;

void printTree(Node *root);
int sum(Node* root, int start, int end);
int update(Node* root, int location, int value);

int main() {
	Node* root = NULL;
	int N, h, t;
	Node** nodes = (Node**)malloc(sizeof(Node*) * 1000005);
	int l, c, a, b;

	scanf("%d", &N);
	h = ceil(log2(N));
	l = N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t); 
		nodes[i] = (Node*)malloc(sizeof(Node));
		nodes[i]->left = NULL; nodes[i]->right = NULL;
		nodes[i]->value = t % 2; nodes[i]->start = i + 1; nodes[i]->end = i + 1;
	}

	for (int j = 0; j < l; j += 2) {
		root = (Node*)malloc(sizeof(Node));
		if (j + 1 < l) {
			root->left = nodes[j]; root->right = nodes[j + 1];
			root->value = nodes[j]->value + nodes[j + 1]->value;
			root->start = nodes[j]->start; root->end = nodes[j + 1]->end;
		}
		else {
			root = nodes[j];
		}
	}

	for (int i = 0; i < h; i++) {
		c = 0;
		for (int j = 0; j < l; j += 2) {
			root = (Node*)malloc(sizeof(Node));
			if (j + 1 < l) {
				root->left = nodes[j]; root->right = nodes[j + 1];
				root->value = nodes[j]->value + nodes[j + 1]->value;
				root->start = nodes[j]->start; root->end = nodes[j + 1]->end;
			}
			else {
				root = nodes[j];
			}
			nodes[c++] = root;
		}
		l = c;
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &t, &a, &b);
		switch (t) {
		case 1:
			update(root, a, b % 2);
			//printTree(root);
			break;
		case 2:
			printf("%d\n", b - a + 1 - sum(root, a, b));
			break;
		case 3:
			printf("%d\n", sum(root, a, b));
			break;
		}


	}



	//printTree(root);

	return 0;
}

void printTree(Node *root) {
	if (root == NULL) return;
	printTree(root->left);
	printf("%d ", root->value);
	printTree(root->right);
}

int sum(Node* root, int start, int end) {
	if (root->start == start && root->end == end) return root->value;
	else if (root->left->end < start) return sum(root->right, start, end);
	else if (root->right->start > end) return sum(root->left, start, end);
	else return sum(root->left, start, root->left->end) + sum(root->right, root->right->start, end);
}

int update(Node* root, int location, int value) {
	if (root->start == location && root->end == location) {
		root->value = value;
		return root->value;
	}
	else if (root->start > location || root->end < location) return root->value;
	else {
		root->value = update(root->left, location, value) + update(root->right, location, value);
		return root->value;
	}
}