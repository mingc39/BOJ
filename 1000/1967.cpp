#include <stdio.h>
#include <stdlib.h>

#define mem 128
#define qsize 40000

int main() {
	int n, **tree, **weight, *size, *length;
	// tree: Ʈ�� ���� ����
	// weight: ������ ����ġ
	// size: �ش� ������ ���Ḯ��Ʈ ũ��(�Ҵ�� �޸� ����) 
	// length: �ش� ������ ���Ḯ��Ʈ ����(���� ������ ����) 
	int a, b, c;
	
	// �Է�  
	scanf("%d", &n);
	tree = (int**)calloc(n + 1, sizeof(int*));
	weight = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int*));
	length = (int*)calloc(n + 1, sizeof(int*));
	for(int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// ���� ���� ������ �߰� �Ҵ� 
		if(size[a] == length[a]) {
			tree[a]   = (int*)realloc(  tree[a], sizeof(int) * (size[a] + mem));
			weight[a] = (int*)realloc(weight[a], sizeof(int) * (size[a] + mem));
			size[a] += mem;
		}
		if(size[b] == length[b]) {
			tree[b]   = (int*)realloc(  tree[b], sizeof(int) * (size[b] + mem));
			weight[b] = (int*)realloc(weight[b], sizeof(int) * (size[b] + mem));
			size[b] += mem;
		}
		
		// �Է� ���� ���� 
		tree  [a][length[a]] = b;
		weight[a][length[a]] = c;
		length[a]++;
		tree  [b][length[b]] = a;
		weight[b][length[b]] = c;
		length[b]++;
	}
	free(size); // length �־ size �ʿ���� 
	// ũ�� ����  
	for(int a = 1; a <= n; a++) {
		tree[a]   = (int*)realloc(  tree[a], sizeof(int) * length[a]);
		weight[a] = (int*)realloc(weight[a], sizeof(int) * length[a]);
	}
	
	// �Է¹��� Ʈ�� ������ Ȯ�� 
	#ifdef DEBUG
	for(int i = 1; i <= n; i++) {
		printf("%d:", i);
		for(int j = 0; j < length[i]; j++) printf(" (%2d %2d)", tree[i][j], weight[i][j]);
		putchar('\n');
	}
	#endif
	
	// ť �ʱ�ȭ  
	int *qn, *ql, *qp, qi = 0, qo = 0;
	int maxLen = 0, maxNod;
	qn = (int*)malloc(sizeof(int) * qsize);
	ql = (int*)malloc(sizeof(int) * qsize);
	qp = (int*)malloc(sizeof(int) * qsize);
	
	// ��Ʈ���� �Ÿ��� �ִ��� ��� ã��  
	qn[qi] = 1;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == qsize) qi = 0;
	while(qi != qo) {
		// ť���� ������  
		a = qn[qo]; // ���� ��� 
		b = ql[qo]; // Ž�� �Ÿ�  
		c = qp[qo]; // ���� ���  
		qo++;
		if(qo == qsize) qo = 0;
		
		// �������� �ִ�Ÿ� ���� 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// ���� ��� ť�� ����
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == qsize) qi = 0;
		} 
	}
	
	// ť�� ������ �̹� �� ���� ť �ʱ�ȭ ���ص� ��
	// ��Ʈ���� �Ÿ��� �ִ��� ��忡�� �Ÿ��� �ִ��� ��� ã��  
	qn[qi] = maxNod;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == qsize) qi = 0;
	while(qi != qo) {
		// ť���� ������  
		a = qn[qo]; // ���� ��� 
		b = ql[qo]; // Ž�� �Ÿ�  
		c = qp[qo]; // ���� ���  
		qo++;
		if(qo == qsize) qo = 0;
		
		// �������� �ִ�Ÿ� ���� 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// ���� ��� ť�� ����
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == qsize) qi = 0;
		} 
	}
	
	// ��� ��� 
	printf("%d", maxLen);
	
	return 0;
}
